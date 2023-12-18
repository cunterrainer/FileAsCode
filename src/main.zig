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


pub fn write_file_header(content: string, hash_name: [] const u8, hash_value: [] const u8, writer: anytype) !void
{
    // /*
    //      FileAsCode exporter
    //
    //      more infos and bug-reports: https://github.com/pyvyx/FileAsCode
    //
    //      sha256: b3f7b214e1b1966d723513b309ff9eb10d4a31f7321b275005c6b52e
    // */

    _ = try writer.write("#ifndef FILE_AS_CODE_H\n");
    _ = try writer.write("#define FILE_AS_CODE_H\n");
    _ = try writer.write("/*\n\tFileAsCode exporter\n\n");
    _ = try writer.write("\tmore infos and bug-reports: https://github.com/pyvyx/FileAsCode\n");
    if (hash_name.len > 0)
    {
        _ = try writer.print("\n\t{s}: {s}\n", .{ hash_name, hash_value });
    }
    _ = try writer.write("*/\n\n");
    _ = try writer.write(content.buffer.?[0..content.size]);
}


const Settings = struct {
    input_file: [] const u8 = "",
    output_file: [] const u8 = "",
    valid: bool = true,
    c_style: bool = true,
    hash_variable: bool = false,
    hash_function: HashFunctions = HashFunctions.Sha256,
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
    print("        -u   | --uncompressed    Write uncompressed data to file (jpeg, png, tga, gmp, psd, gif, hdr, pic, pnm)\n", .{});
    print("        -l   | --inline          Inline the variables (starting from C++17)\n", .{});
    print("        --no-hash                Don't include a hash in top comment (e.g. if file is very large)\n", .{});
    print("        --hash [function]        Include the hash of the file as variable (Default Sha256)\n", .{});
    print("                                 Supported functions are: md5, sha1,\n", .{});
    print("                                 sha224, sha256, sha384, sha512, sha512-256,\n", .{});
    print("                                 sha3-224, sha3-256, sha3-384, sha3-512\n", .{});
    print("                                 If '--uncompressed' is set the hash is going to be of the uncompressed data\n", .{});
}


const HashFunctions = enum {
    None,
    MD5,
    Sha1,
    Sha224,
    Sha256,
    Sha384,
    Sha512,
    Sha512_256,
    Sha3_224,
    Sha3_256,
    Sha3_384,
    Sha3_512
};


pub fn generate_hash_functions_map() !std.StringHashMap(HashFunctions)
{
    // md5, sha1, sha2-224, sha2-256, sha2-384, sha2-512, sha2-512-256, sha3-224, sha3-256, sha3-384, sha3-512
    var hash_functions_map = std.StringHashMap(HashFunctions).init(std.heap.page_allocator);
    try hash_functions_map.put("md5", HashFunctions.MD5);
    try hash_functions_map.put("sha1", HashFunctions.Sha1);
    try hash_functions_map.put("sha224", HashFunctions.Sha224);
    try hash_functions_map.put("sha256", HashFunctions.Sha256);
    try hash_functions_map.put("sha384", HashFunctions.Sha384);
    try hash_functions_map.put("sha512", HashFunctions.Sha512);
    try hash_functions_map.put("sha512-256", HashFunctions.Sha512_256);
    try hash_functions_map.put("sha3-224", HashFunctions.Sha3_224);
    try hash_functions_map.put("sha3-256", HashFunctions.Sha3_256);
    try hash_functions_map.put("sha3-384", HashFunctions.Sha3_384);
    try hash_functions_map.put("sha3-512", HashFunctions.Sha3_512);
    return hash_functions_map;
}


pub fn parse_args(args: [][] u8) !Settings
{
    var hash_functions_map = try generate_hash_functions_map();
    defer hash_functions_map.deinit();

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
        else if (str.cmp("--no-hash"))
        {
            settings.hash_variable = false;
            settings.hash_function = HashFunctions.None;
        }
        else if (str.cmp("--hash"))
        {
            if (i + 1 == args.len)
            {
                settings.valid = false;
                print_err("Missing hash function after '{s}'\nTry '--help' for additional information\n", .{arg});
                return settings;
            }

            const hash_function = hash_functions_map.get(args[i+1]);
            if (hash_function) |v|
            {
                skip = true;
                settings.hash_function = v;
                settings.hash_variable = true;
            }
            else
            {
                settings.valid = false;
                print_err("Invalid hash function '{s}'\n", .{ args[i+1] });
                print_err("Supported functions are: md5, sha1, sha224, sha256, sha384, sha512, sha512-256, sha3-224, sha3-256, sha3-384, sha3-512\nTry '--help' for additional information\n", .{});
                return settings;
            }
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


pub fn memset(buffer: [] u8, size: usize, elem: u8) []u8
{
    for (0..size) |i|
    {
        buffer[i] = elem;
    }
    return buffer;
}


pub fn hash(buffer: [] const u8, out_buffer: [] u8, hash_function: HashFunctions, hash_name: *string) !usize
{
    var length: usize = 0;
    var out_buffer_int: [64] u8 = undefined;
    switch(hash_function)
    {
        .MD5 => {
            try hash_name.concat("md5");
            length = std.crypto.hash.Md5.digest_length;
            std.crypto.hash.Md5.hash(buffer, out_buffer_int[0..std.crypto.hash.Md5.digest_length], .{});
        },
        .Sha1 => {
            try hash_name.concat("sha1");
            length = std.crypto.hash.Sha1.digest_length;
            std.crypto.hash.Sha1.hash(buffer, out_buffer_int[0..std.crypto.hash.Sha1.digest_length], .{});
        },
        .Sha224 => {
            try hash_name.concat("sha224");
            length = std.crypto.hash.sha2.Sha224.digest_length;
            std.crypto.hash.sha2.Sha224.hash(buffer, out_buffer_int[0..std.crypto.hash.sha2.Sha224.digest_length], .{});
        },
        .Sha256 => {
            try hash_name.concat("sha256");
            length = std.crypto.hash.sha2.Sha256.digest_length;
            std.crypto.hash.sha2.Sha256.hash(buffer, out_buffer_int[0..std.crypto.hash.sha2.Sha256.digest_length], .{});
        },
        .Sha384 => {
            try hash_name.concat("sha384");
            length = std.crypto.hash.sha2.Sha384.digest_length;
            std.crypto.hash.sha2.Sha384.hash(buffer, out_buffer_int[0..std.crypto.hash.sha2.Sha384.digest_length], .{});
        },
        .Sha512 => {
            try hash_name.concat("sha512");
            length = std.crypto.hash.sha2.Sha512.digest_length;
            std.crypto.hash.sha2.Sha512.hash(buffer, out_buffer_int[0..std.crypto.hash.sha2.Sha512.digest_length], .{});
        },
        .Sha512_256 => {
            try hash_name.concat("sha512_256");
            length = std.crypto.hash.sha2.Sha512256.digest_length;
            std.crypto.hash.sha2.Sha512256.hash(buffer, out_buffer_int[0..std.crypto.hash.sha2.Sha512256.digest_length], .{});
        },
        .Sha3_224 => {
            try hash_name.concat("sha3_224");
            length = std.crypto.hash.sha3.Sha3_224.digest_length;
            std.crypto.hash.sha3.Sha3_224.hash(buffer, out_buffer_int[0..std.crypto.hash.sha3.Sha3_224.digest_length], .{});
        },
        .Sha3_256 => {
            try hash_name.concat("sha3_256");
            length = std.crypto.hash.sha3.Sha3_256.digest_length;
            std.crypto.hash.sha3.Sha3_256.hash(buffer, out_buffer_int[0..std.crypto.hash.sha3.Sha3_256.digest_length], .{});
        },
        .Sha3_384 => {
            try hash_name.concat("sha3_384");
            length = std.crypto.hash.sha3.Sha3_384.digest_length;
            std.crypto.hash.sha3.Sha3_384.hash(buffer, out_buffer_int[0..std.crypto.hash.sha3.Sha3_384.digest_length], .{});
        },
        .Sha3_512 => {
            try hash_name.concat("sha3_512");
            length = std.crypto.hash.sha3.Sha3_512.digest_length;
            std.crypto.hash.sha3.Sha3_512.hash(buffer, out_buffer_int[0..std.crypto.hash.sha3.Sha3_512.digest_length], .{});
        },
        .None => {}
    }

    var idx: usize = 0;
    for (0..length) |i|
    {
        _ = std.fmt.bufPrint(out_buffer[idx..idx+2], "{x:0>2}", .{out_buffer_int[i]}) catch memset(out_buffer[idx..idx+2], 2, '0');
        idx += 2;
    }

    return length*2;
}


pub fn uncompress_data(allocator: std.mem.Allocator, path: [] const u8, header_content: *string, var_modifier: [] const u8) !?[] u8
{
    var width: c_int = 0;
    var height: c_int = 0;
    var channel: c_int = 0;
    const s = stb.stbi_load(path.ptr, &width, &height, &channel,  0);
    if (s == null)
    {
        print_err("Failed to open file '{s}': {s}\n", .{ path, stb.stbi_failure_reason() });
        return null;
    }
    // We have to copy the image data, otherwise we would be freeing file_data of type [] u8 instead of [*c] u8 which can cause segfaults
    const data = try allocator.alloc(u8, @intCast(width*height*channel));
    std.mem.copyForwards(u8, data, s[0..@intCast(width*height*channel)]);
    stb.stbi_image_free(s);
    try int_to_string(header_content, width,   var_modifier, " unsigned char sg_File_as_code_width   = ", ";\n");
    try int_to_string(header_content, height,  var_modifier, " unsigned char sg_File_as_code_height  = ", ";\n");
    try int_to_string(header_content, channel, var_modifier, " unsigned char sg_File_as_code_channel = ", ";\n\n");
    return data;
}


pub fn app() !void
{
    const allocator = std.heap.page_allocator;
    const args = try std.process.argsAlloc(allocator);
    defer std.process.argsFree(allocator, args);
    const settings = try parse_args(args);

    if (!settings.valid)
    {
        return;
    }
    const var_modifier = variable_modifier(settings.c_style, settings.inline_vars);

    var custom_header_content = try string.init_with_contents(allocator, "");
    defer custom_header_content.deinit();

    var file_data: [] u8 = undefined;
    if (!settings.uncompressed_data)
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
    else
    {
        const data_opt = try uncompress_data(allocator, settings.input_file, &custom_header_content, var_modifier);
        if (data_opt) |v| { file_data = v; }
        else return;
    }

    var hash_name: string = string.init(allocator);
    defer hash_name.deinit();
    var hash_length : usize = 0;
    var hash_out_buffer: [128] u8 = undefined;
    if (settings.hash_function != HashFunctions.None)
    {
        hash_length = try hash(file_data, &hash_out_buffer, settings.hash_function, &hash_name);

        if (settings.hash_variable)
        {
            try custom_header_content.concat(var_modifier);
            if (!settings.c_style)
                try custom_header_content.concat(" const"); // otherwise e.g. static constexpr char* a = "Hello world"; (forbidden not const char*)
            try custom_header_content.concat(" char* sg_File_as_code_");
            try custom_header_content.concat(hash_name.str());
            try custom_header_content.concat(" = \"");
            try custom_header_content.concat(hash_out_buffer[0..hash_length]);
            try custom_header_content.concat("\";\n\n");
        }
    }

    var out_writer: std.fs.File = if (settings.output_file.len == 0) std.io.getStdOut() else std.fs.cwd().createFile(settings.output_file, .{}) catch std.io.getStdOut();
    var buf = std.io.bufferedWriter(out_writer.writer());
    try write_file_header(custom_header_content, hash_name.str(), hash_out_buffer[0..hash_length], buf.writer());
    try write_bytes_format(var_modifier, buf.writer(), file_data);
    try buf.flush();
    defer out_writer.close();
    defer allocator.free(file_data);
}


pub fn main() !void
{
    app() catch |e| {
        try std.io.getStdErr().writer().print("Unhandled exception occured: {}\n", .{ e });
    };
}