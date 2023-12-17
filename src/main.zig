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
    _ = try writer.write("static const unsigned char sg_File_as_code =\n");
}


pub fn main() !void
{
    const allocator = std.heap.page_allocator;

    const args = try std.process.argsAlloc(allocator);
    defer std.process.argsFree(allocator, args);

    if (args.len == 1)
    {
        std.debug.print("Please provide a path", .{});
        return;
    }

    var file = try std.fs.cwd().openFile(args[0], .{});
    defer file.close();

    const result = try file.readToEndAlloc(allocator, (try file.stat()).size);
    defer allocator.free(result);
    _ = try file.readAll(result);

    var write = try std.fs.cwd().createFile("result.txt", .{});
    defer write.close();

    var buf = std.io.bufferedWriter(write.writer());
    try write_file_header(buf.writer());
    try write_bytes_format(buf.writer(), result);
    try buf.flush();
}