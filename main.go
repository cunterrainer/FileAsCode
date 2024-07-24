// +build !wasm

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
    fmt.Println("        -d   | --decimal           Write bytes in decimal representation")
    fmt.Println("        -b   | --binary            Write bytes as bits e.g. 00000010")
    fmt.Println("        -c   | --char              Write chars to array instead of their value as hex (if printable)")
    fmt.Println("        -c++ | --cplusplus         Use C-Style variable qualifiers (constexpr)")
    fmt.Println("        -h   | --help              Show this info message")
    fmt.Println("        -u   | --uncompress        Write uncompressed data to file (jpeg, png, gif)")
    fmt.Println("        -l   | --inline            Inline the variables (starting from C++17)")
    fmt.Println("        -s   | --shrink            Make the output array as small as possible (Not easy to read)")
    fmt.Println("        -g   | --gzip              Use the gzip compression algorithm to compress data (Default: default compression)")
    fmt.Println("        -z   | --zlib              Use the zlib compression algorithm to compress data (Default: default compression)")
    fmt.Println("        -bs  | --best-speed        Use the compression level for best speed")
    fmt.Println("        -bc  | --best-compression  Use the compression level for best compression")
    fmt.Println("        -p   | --png               Use with '-r' to convert an array to a png (only if array creation with '-u')")
    fmt.Println("        -j   | --jpg               Use with '-r' to convert an array to a jpg (only if array creation with '-u')")
    fmt.Println("        -r   | --reverse           Read a file (e.g. .h/.hpp) containing an array and convert it back")
    fmt.Println("                                   If using the reverse function you have to provide the exact same parameters used")
    fmt.Println("                                   to create the array, e.g. if gzip was use you need to pass the '-g' flag, the")
    fmt.Println("                                   compression level doesn't have to be set. If you want to reverse an uncompressed")
    fmt.Println("                                   array ('-u' flag), use the '--png' or '--jpg' flag to convert to the appropriate")
    fmt.Println("                                   image format. (Jpeg doesn't have transparency)")
}


func parseArgs() (fac.Settings, error) {
    args := os.Args
    argsLen := len(args)
    settings := fac.Settings {
        InputPath: "",
        OutputPath: "",
        CStyle: true,
        Shrink: false,
        Reverse: false,
        StdArray: false,
        InlineVars: false,
        Uncompress: false,
        OutputRep: fac.OutputHex,
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
            settings.OutputRep = fac.OutputChars

        } else if argLower == "-r" || argLower == "--reverse" {
            settings.Reverse = true

        } else if argLower == "-p" || argLower == "--png" {
            settings.FileType = fac.FilePNG

        } else if argLower == "-j" || argLower == "--jpg" {
            settings.FileType = fac.FileJPEG

        } else if argLower == "-u" || argLower == "--uncompressed" {
            settings.Uncompress = true

        } else if argLower == "-d" || argLower == "--decimal" {
            settings.OutputRep = fac.OutputDecimal

        } else if argLower == "-l" || argLower == "--inline" {
            settings.InlineVars = true

        } else if argLower == "-b" || argLower == "--binary" {
            settings.OutputRep = fac.OutputBinary
        
        } else if argLower == "-a" || argLower == "--array" {
            settings.StdArray = true

        } else if argLower == "-s" || argLower == "--shrink" {
            settings.Shrink = true

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

    if settings.Reverse {
        fac.Caf(settings)
    } else {
        fac.Fac(settings)
    }
}