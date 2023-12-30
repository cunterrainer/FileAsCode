package main

import (
    "os"
    "fmt"
    "errors"
    "strings"
    "compress/flate"

    fac "github.com/pyvyx/FileAsCode/src"
)


func printHelp(path string) {
    fmt.Printf("Usage: %s [options]\nOptions:\n", path)
    fmt.Println("        -i   | --input  [FILE]     Input file path")
    fmt.Println("        -o   | --output [FILE]     Output file path")
    fmt.Println("        -a   | --array             Use a std::array instead of a C-Style array")
    fmt.Println("        -c   | --char              Write chars to array instead of their value as hex (if printable)")
    fmt.Println("        -c++ | --cplusplus         Use C-Style variable qualifiers (constexpr)")
    fmt.Println("        -h   | --help              Show this info message")
    fmt.Println("        -u   | --uncompress        Write uncompressed data to file (jpeg, png, gif)")
    fmt.Println("        -l   | --inline            Inline the variables (starting from C++17)")
    fmt.Println("        -g   | --gzip              Use the gzip compression algorithm to compress data")
    fmt.Println("        -z   | --zlib              Use the zlib compression algorithm to compress data")
    fmt.Println("        -bs  | --best-speed        Use the compression level for best speed")
    fmt.Println("        -bc  | --best-compression  Use the compression level for best compression")
    fmt.Println("                                   If neither '-bs' nor '-bc' is set default compression is used")
}


func parseArgs() (fac.Settings, error) {
    args := os.Args
    argsLen := len(args)
    settings := fac.Settings {
        InputPath: "",
        OutputPath: "",
        CStyle: true,
        StdArray: false,
        WriteChars: false,
        InlineVars: false,
        Uncompress: false,
        Compression: fac.CompressionNone,
        CompressLvl: flate.DefaultCompression,
    }

    skip := false
    for i, arg := range args[1:] {
        if skip {
            skip = false
            continue
        }

        argLower := strings.ToLower(arg)

        if argLower == "-h" || argLower == "--help" {
            printHelp(args[0])
            return settings, errors.New("")

        } else if argLower == "-c++" || argLower == "--cplusplus" {
            settings.CStyle = false

        } else if argLower == "-c" || argLower == "--char" {
            settings.WriteChars = true

        } else if argLower == "-u" || argLower == "--uncompressed" {
            settings.Uncompress = true

        } else if argLower == "-l" || argLower == "--inline" {
            settings.InlineVars = true

        } else if argLower == "-a" || argLower == "--array" {
            settings.StdArray = true

        } else if argLower == "-g" || argLower == "--gzip" {
            settings.Compression = fac.CompressionGzip

        } else if argLower == "-z" || argLower == "--zlib" {
            settings.Compression = fac.CompressionZlib

        } else if argLower == "-bs" || argLower == "--best-speed" {
            settings.CompressLvl = flate.BestSpeed
            
        } else if argLower == "-bc" || argLower == "--best-compression" {
            settings.CompressLvl = flate.BestCompression

        } else if argLower == "-i" || argLower == "--input" {
            if i + 2 < argsLen {
                skip = true
                settings.InputPath = args[i+2]
            } else {
                return settings, fmt.Errorf("Missing file path after '%s'\nTry '--help' for additional information\n", arg)
            }
        } else if argLower == "-o" || argLower == "--output" {
            if i + 2 < argsLen {
                skip = true
                settings.OutputPath = args[i+2]
            } else {
                return settings, fmt.Errorf("Missing file path after '%s'\nTry '--help' for additional information\n", arg)
            }
        } else {
            return settings, fmt.Errorf("Unknown option '%s'\nTry '--help' for additional information\n", arg)

        }
	}

    if len(settings.InputPath) == 0 {
        return settings, fmt.Errorf("Usage: %s [options]\nTry '--help' for additional information\n", args[0])
    }

    return settings, nil
}


func main() {

    settings, err := parseArgs()
    if err != nil {
        fmt.Fprint(os.Stderr, err)
        return
    }

    fac.Fac(settings)
}