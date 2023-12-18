const std = @import("std");
const string = @import("string.zig").String;
const stb = @cImport(@cInclude("stb_image.c"));

pub fn write_bytes_format(var_modifier: [] const u8, writer: anytype, buffer: []const u8) !void
{
    _ = try writer.print("{s} unsigned char sg_File_as_code[] =\n{{\n\t", .{var_modifier});
    
    var processed: usize = 0;
    for (buffer) |c|
    {
        processed += 1;
        if (processed == buffer.len)
        {
            _ = try writer.print("0x{X:0>2}\n}};\n", .{c});
        }
        else if (processed % 16 == 0)
        {
            _ = try writer.print("0x{X:0>2},\n\t", .{c});
        }
        else
        {
            _ = try writer.print("0x{X:0>2}, ", .{c});
        }
    }
    _ = try writer.print("{s} unsigned int sg_File_as_code_size = sizeof(sg_File_as_code) / sizeof(*sg_File_as_code);\n", .{var_modifier});
    _ = try writer.write("#endif // FILE_AS_CODE_H");
}


pub fn write_file_header(content: string, writer: anytype) !void
{
    //////////////////////////////////////////////////////////////////////////////////
    //                                                                              //
    // FileAsCode exporter                                                          //
    //                                                                              //
    // more infos and bug-reports: github.com/pyvyx/FileAsCode                      //
    //                                                                              //
    //////////////////////////////////////////////////////////////////////////////////

    _ = try writer.write("#ifndef FILE_AS_CODE_H\n");
    _ = try writer.write("#define FILE_AS_CODE_H\n");
    _ = try writer.write("//////////////////////////////////////////////////////////////////////////////////\n");
    _ = try writer.write("//                                                                              //\n");
    _ = try writer.write("// FileAsCode exporter                                                          //\n");
    _ = try writer.write("//                                                                              //\n");
    _ = try writer.write("// more infos and bug-reports: https://github.com/pyvyx/FileAsCode              //\n");
    _ = try writer.write("//                                                                              //\n");
    _ = try writer.write("//////////////////////////////////////////////////////////////////////////////////\n\n");
    _ = try writer.write(content.buffer.?[0..content.size]);
}


const Settings = struct {
    input_file: [] const u8 = undefined,
    output_file: [] const u8 = undefined,
    valid: bool = true,
    c_style: bool = true,
    inline_vars: bool = false,
    uncompressed_data: bool = false
};


pub fn print_err(comptime format: []const u8, args: anytype) void
{
    std.io.getStdErr().writer().print(format, args) catch return;
}


pub fn print(comptime format: []const u8, args: anytype) void
{
    std.io.getStdOut().writer().print(format, args) catch return;
}


pub fn print_help(path: [] const u8) void
{
    print("Usage: {s} [options]\nOptions:\n", .{path});
    print("        -i   | --input  [FILE]   Input file path\n", .{});
    print("        -o   | --output [FILE]   Output file path\n", .{});
    print("        -c   | --c-style         Use C-Style variable qualifiers (const)\n", .{});
    print("        -c++ | --cplusplus       Use C-Style variable qualifiers (constexpr)\n", .{});
    print("        -h   | --help            Show this info message\n", .{});
    print("        -u   | --uncompressed    Write uncompressed data to file\n", .{});
    print("        -l   | --inline          Inline the variables (starting from C++17)\n", .{});
}


pub fn parse_args(args: [][] u8) Settings
{
    var settings: Settings = .{};

    if (args.len == 1)
    {
        settings.valid = false;
        print_err("Usage: {s} [options]\nTry '--help' for additional information\n", .{args[0]});
        return settings;
    }

    var skip: bool = true;
    for (0.., args) |i, arg|
    {
        if (skip)
        {
            skip = false;
            continue;
        }

        var str = string.init_with_contents(std.heap.c_allocator, arg) catch { settings.valid = false; return settings; };
        defer str.deinit();
        str.toLowercase();

        if ((str.cmp("-i") or str.cmp("--input")))
        {
            if (i + 1 != args.len)
            {
                skip = true;
                settings.input_file = args[i+1];
            }
            else
            {
                settings.valid = false;
                print_err("Missing file path after '{s}'\nTry '--help' for additional information\n", .{arg});
                return settings;
            }
        }
        else if ((str.cmp("-o") or str.cmp("--output")))
        {
            if (i + 1 != args.len)
            {
                skip = true;
                settings.output_file = args[i+1];
            }
            else
            {
                settings.valid = false;
                print_err("Missing file path after '{s}'\nTry '--help' for additional information\n", .{arg});
                return settings;
            }
        }
        else if (str.cmp("-c") or str.cmp("--c-style"))
        {
            settings.c_style = true;
        }
        else if (str.cmp("-c++") or str.cmp("--cplusplus"))
        {
            settings.c_style = false;
        }
        else if (str.cmp("-h") or str.cmp("--help"))
        {
            settings.valid = false;
            print_help(args[0]);
            return settings;
        }
        else if (str.cmp("-u") or str.cmp("--uncompressed"))
        {
            settings.uncompressed_data = true;
        }
        else if (str.cmp("-l") or str.cmp("--inline"))
        {
            settings.inline_vars = true;
        }
        else
        {
            settings.valid = false;
            print_err("Unknown option '{s}'\nTry '--help' for additional information\n", .{arg});
            return settings;
        }
    }

    return settings;
}


pub fn int_to_string(str: *string, num: c_int, var_modifier: [] const u8, comptime var_name: [] const u8, comptime var_end: [] const u8) !void
{
    var num_buffer: [20] u8 = undefined; // 20 should never be reached
    const char_size = try std.fmt.bufPrint(&num_buffer, "{d}", .{num});
    try str.concat(var_modifier);
    try str.concat(var_name);
    try str.concat(num_buffer[0..char_size.len]);
    try str.concat(var_end);
}


pub fn variable_modifier(c_style: bool, to_inline: bool) [] const u8
{
    if (c_style)
        return "static const";
    if (to_inline)
        return "inline constexpr";
    return "static constexpr";
}


pub fn main() !void
{
    const allocator = std.heap.c_allocator; // because of stb compatibility (stb calls malloc/free under the hood)
    const args = try std.process.argsAlloc(allocator);
    defer std.process.argsFree(allocator, args);
    const settings = parse_args(args);

    if (!settings.valid)
    {
        return;
    }
    const var_modifier = variable_modifier(settings.c_style, settings.inline_vars);

    var custom_header_content = try string.init_with_contents(allocator, "");
    defer custom_header_content.deinit();

    var file_data: [] u8 = undefined;
    if (settings.uncompressed_data)
    {
        var width: c_int = 0;
        var height: c_int = 0;
        var channel: c_int = 0;
        var s = stb.stbi_load(settings.input_file.ptr, &width, &height, &channel,  0);
        if (s == null)
        {
            print_err("Failed to open file '{s}': {s}", .{ settings.input_file, stb.stbi_failure_reason() });
            return;
        }
        file_data = s[0..@intCast(width*height*channel)];
        try int_to_string(&custom_header_content, width,   var_modifier, " unsigned char sg_File_as_code_width   = ", ";\n");
        try int_to_string(&custom_header_content, height,  var_modifier, " unsigned char sg_File_as_code_height  = ", ";\n");
        try int_to_string(&custom_header_content, channel, var_modifier, " unsigned char sg_File_as_code_channel = ", ";\n\n");    }
    else
    {
        var in_file = std.fs.cwd().openFile(settings.input_file, .{}) catch |err|
        {
            print_err("Failed to open file '{s}': {}\n", .{settings.input_file, err});
            return;
        };

        file_data = try in_file.readToEndAlloc(allocator, (try in_file.stat()).size);
        _ = try in_file.readAll(file_data);
        in_file.close();
    }

    var out_writer: std.fs.File = if (settings.output_file.len == 0) std.io.getStdOut() else std.fs.cwd().createFile(settings.output_file, .{}) catch std.io.getStdOut();
    var buf = std.io.bufferedWriter(out_writer.writer());
    try write_file_header(custom_header_content, buf.writer());
    try write_bytes_format(var_modifier, buf.writer(), file_data);
    try buf.flush();
    defer out_writer.close();
    defer allocator.free(file_data);
}