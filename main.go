package main

import (
    "os"
    "fmt"
    "errors"
    "strings"

    fac "github.com/pyvyx/FileAsCode/src"
)


func printHelp(path string) {
    fmt.Printf("Usage: %s [options]\nOptions:\n", path);
    fmt.Println("        -i   | --input  [FILE]   Input file path");
    fmt.Println("        -o   | --output [FILE]   Output file path");
    fmt.Println("        -s   | --std             Use a std::array instead of a C-Style array");
    fmt.Println("        -c   | --char            Write chars to array instead of their value as hex (if printable)");
    fmt.Println("        -c++ | --cplusplus       Use C-Style variable qualifiers (constexpr)");
    fmt.Println("        -h   | --help            Show this info message");
    fmt.Println("        -u   | --uncompress      Write uncompressed data to file (jpeg, png, tga, gmp, psd, gif, hdr, pic, pnm)");
    fmt.Println("        -l   | --inline          Inline the variables (starting from C++17)");
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

        } else if argLower == "-s" || argLower == "--std" {
            settings.StdArray = true

        } else if argLower == "-i" || argLower == "--input" {
            if i + 2 < argsLen {
                skip = true
                settings.InputPath = args[i+2]
            } else {
                return settings, fmt.Errorf("Missing file path after '%s'\nTry '--help' for additional information", arg)
            }
        } else if argLower == "-o" || argLower == "--output" {
            if i + 2 < argsLen {
                skip = true
                settings.OutputPath = args[i+2]
            } else {
                return settings, fmt.Errorf("Missing file path after '%s'\nTry '--help' for additional information", arg)
            }
        } else {
            return settings, fmt.Errorf("Unknown option '%s'\nTry '--help' for additional information", arg)

        }
	}

    if len(settings.InputPath) == 0 {
        return settings, fmt.Errorf("Usage: %s [options]\nTry '--help' for additional information", args[0])
    }

    return settings, nil
}


func main() {

    settings, err := parseArgs()
    if err != nil {
        fmt.Fprintln(os.Stderr, err)
        return
    }

    fac.Fac(settings)
}