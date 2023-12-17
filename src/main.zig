const std = @import("std");

pub fn write_bytes_format(writer: anytype, buffer: []const u8) !void
{
    _ = try writer.write("{\n\t");
    
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
    _ = try writer.write("static const unsigned int sg_File_as_code_size = sizeof(sg_File_as_code) / sizeof(*sg_File_as_code);\n");
    _ = try writer.write("#endif // FILE_AS_CODE_H");
}


pub fn write_file_header(writer: anytype) !void
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
    _ = try writer.write("static const unsigned char sg_File_as_code[] =\n");
}


const Settings = struct {
    input_file: [] const u8 = undefined,
    output_file: [] const u8 = undefined,
    valid: bool = true,
    c_style: bool = true,
    inline_vars: bool = false,
    uncompressed_data: bool = false
};


pub fn print(comptime format: []const u8, args: anytype) void
{
    std.io.getStdOut().writer().print(format, args) catch return;
}


pub fn print_help(path: [] const u8) void
{
    print("Usage: {s} [options]\nOptions:\n", .{path});
    print("        -i   | --input  [FILE]   Input file path\n", .{});
    print("        -o   | --output [FILE]   Output file path\n", .{});
    print("        -c   | --c-style         Create a C-Style array\n", .{});
    print("        -c++ | --cplusplus       Create a C++-Style array\n", .{});
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
        std.io.getStdErr().writer().print("Usage: {s} [options]\nTry '--help' for additional information\n", .{args[0]}) catch return settings;
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

        if ((std.mem.eql(u8, arg, "-i") or std.mem.eql(u8, arg, "--input")))
        {
            if (i + 1 != args.len)
            {
                skip = true;
                settings.input_file = args[i+1];
            }
            else
            {
                settings.valid = false;
                std.io.getStdErr().writer().print("Missing file path after '{s}'\nTry '--help' for additional information\n", .{arg}) catch return settings;
                return settings;
            }
        }
        else if ((std.mem.eql(u8, arg, "-o") or std.mem.eql(u8, arg, "--output")))
        {
            if (i + 1 != args.len)
            {
                skip = true;
                settings.output_file = args[i+1];
            }
            else
            {
                settings.valid = false;
                std.io.getStdErr().writer().print("Missing file path after '{s}'\nTry '--help' for additional information\n", .{arg}) catch return settings;
                return settings;
            }
        }
        else if (std.mem.eql(u8, arg, "-c") or std.mem.eql(u8, arg, "--c-style"))
        {
            settings.c_style = true;
        }
        else if (std.mem.eql(u8, arg, "-c++") or std.mem.eql(u8, arg, "--cplusplus"))
        {
            settings.c_style = false;
        }
        else if (std.mem.eql(u8, arg, "-h") or std.mem.eql(u8, arg, "--help"))
        {
            print_help(args[0]);
            return settings;
        }
        else if (std.mem.eql(u8, arg, "-u") or std.mem.eql(u8, arg, "--uncompressed"))
        {
            settings.uncompressed_data = true;
        }
        else if (std.mem.eql(u8, arg, "-l") or std.mem.eql(u8, arg, "--inline"))
        {
            settings.inline_vars = true;
        }
        else
        {
            settings.valid = false;
            std.io.getStdErr().writer().print("Unknown option '{s}'\nTry '--help' for additional information\n", .{arg}) catch return settings;
            return settings;
        }
    }

    return settings;
}


pub fn main() !void
{
    const allocator = std.heap.page_allocator;
    const args = try std.process.argsAlloc(allocator);
    defer std.process.argsFree(allocator, args);
    const settings = parse_args(args);

    if (!settings.valid)
    {
        return;
    }

    var in_file = try std.fs.cwd().openFile(settings.input_file, .{});
    defer in_file.close();

    const result = try in_file.readToEndAlloc(allocator, (try in_file.stat()).size);
    defer allocator.free(result);
    _ = try in_file.readAll(result);

    var out_writer: std.fs.File = undefined;
    if (settings.output_file.len == 0)
    {
        out_writer = std.io.getStdOut();
    }
    else
    {
        out_writer = try std.fs.cwd().createFile(settings.output_file, .{});
        defer out_writer.close();
    }

    var buf = std.io.bufferedWriter(out_writer.writer());
    try write_file_header(buf.writer());
    try write_bytes_format(buf.writer(), result);
    try buf.flush();
}