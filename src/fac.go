package fac

import (
	"os"
	"io"
	"fmt"
	"bufio"
)


type Settings struct {
    InputPath  string
    OutputPath string
    CStyle     bool
    StdArray   bool
    WriteChars bool
    InlineVars bool
    Uncompress bool
}


func writeHeader(w io.Writer) {
	fmt.Fprintln(w, "#ifndef FILE_AS_CODE_H")
	fmt.Fprintln(w, "#define FILE_AS_CODE_H")
	fmt.Fprintln(w, "//////////////////////////////////////////////////////////////////////////////////")
	fmt.Fprintln(w, "//                                                                              //")
	fmt.Fprintln(w, "// FileAsCode exporter                                                          //")
	fmt.Fprintln(w, "//                                                                              //")
	fmt.Fprintln(w, "// more infos and bug-reports: github.com/pyvyx/FileAsCode                      //")
	fmt.Fprintln(w, "//                                                                              //")
	fmt.Fprintln(w, "//////////////////////////////////////////////////////////////////////////////////")
	fmt.Fprintln(w)
}


func writeByteAsChar(w io.Writer, b byte) {
	switch b {
	case '\n':
		fmt.Fprint(w, "'\\n'")
	case '\r':
		fmt.Fprint(w, "'\\r'")
	case '\t':
		fmt.Fprint(w, "'\\t'")
	case '\\':
		fmt.Fprint(w, "'\\\\'")
	case '\'':
		fmt.Fprint(w, "'\\''")
	case '"':
		fmt.Fprint(w, "'\\\"'")
	case 0:
		fmt.Fprint(w, "'\\0'")
	default:
		if (b > 31 && b < 127) { // printable
			fmt.Fprintf(w, " '%c'", b)
		} else {
			fmt.Fprintf(w, "0x%02X", b)
		}
	}
}


func writeArray(w io.Writer, bytes []byte, constVariant string, writeChar bool, stdArray bool) {
	bytesLen := len(bytes)

	if stdArray {
		fmt.Fprintf(w, "%s std::array<unsigned char, %d> sg_File_as_code =\n{\n\t", constVariant, bytesLen)
	} else {
		fmt.Fprintf(w, "%s unsigned char sg_File_as_code[] =\n{\n\t", constVariant)
	}

	for i, b := range bytes {
		processed := i + 1

		if processed == bytesLen {
			if writeChar {
				writeByteAsChar(w, b)
				fmt.Fprint(w, "\n};\n")
			} else {
				fmt.Fprintf(w, "0x%02X\n};\n", b)
			}
		} else if processed % 16 == 0 {
			if writeChar {
				writeByteAsChar(w, b)
				fmt.Fprint(w, ",\n\t")
			} else {
				fmt.Fprintf(w, "0x%02X,\n\t", b)
			}
		} else {
			if writeChar {
				writeByteAsChar(w, b)
				fmt.Fprintf(w, ", ")
			} else {
				fmt.Fprintf(w, "0x%02X, ", b)
			}
		}
	}
}


func getConstVariant(cstyle bool, inline bool) string {
	if cstyle {
		return "static const"
	} else if inline {
		return "inline constexpr"
	}
	return "static constexpr"
}


func Fac(settings Settings) {
	content, err := os.ReadFile(settings.InputPath)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Failed to open file '%s': %v", settings.InputPath, err)
		return
	}
	
	bufferedWriter := bufio.NewWriter(os.Stdout)

	writeHeader(bufferedWriter)
	writeArray(bufferedWriter, content, getConstVariant(settings.CStyle, settings.InlineVars), settings.WriteChars, settings.StdArray)
	fmt.Fprint(bufferedWriter, "#endif // FILE_AS_CODE_H")
	bufferedWriter.Flush()
}