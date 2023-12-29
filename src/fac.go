package fac

import (
	"io"
	"os"
	"fmt"
	"bufio"
	"bytes"
	"image"
	"errors"
	"image/draw"
	_ "image/gif"
	_ "image/jpeg"
	_ "image/png"
	"compress/gzip"
	"compress/zlib"
)


type Settings struct {
	InputPath  string
	OutputPath string
	CStyle     bool
	StdArray   bool
	WriteChars bool
	InlineVars bool
	Uncompress bool
	Compression int
}


func writeHeader(w io.Writer, stdArray bool) {
	fmt.Fprintln(w, "#ifndef FILE_AS_CODE_H")
	fmt.Fprintln(w, "#define FILE_AS_CODE_H")
	if stdArray {
		fmt.Fprintln(w, "#include <array>")
	}
	fmt.Fprintln(w, "//////////////////////////////////////////////////////////////////////////////////")
	fmt.Fprintln(w, "//                                                                              //")
	fmt.Fprintln(w, "// FileAsCode exporter                                                          //")
	fmt.Fprintln(w, "//                                                                              //")
	fmt.Fprintln(w, "// more infos and bug-reports: https://github.com/pyvyx/FileAsCode              //")
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
		if b > 31 && b < 127 { // printable
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
		} else if processed%16 == 0 {
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
	if cstyle && inline {
		return "inline const"
	} else if cstyle {
		return "static const"
	} else if inline {
		return "inline constexpr"
	}
	return "static constexpr"
}


func getOutputFile(outputPath string) *os.File {
	if outputPath == "" {
		return os.Stdout
	}

	file, err := os.Create(outputPath)
	if err != nil {
		return os.Stdout
	}
	return file
}


func readFileCompressed(path string) ([]byte, error) {
	content, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("Failed to open file '%s': %v", path, err)
	}
	return content, nil
}


func getImageBytes(img image.Image) ([]byte, error) {
	var buf bytes.Buffer

	switch img := img.(type) {
	case *image.RGBA:
		_, err := buf.Write(img.Pix)
		if err != nil {
			return nil, errors.New("Failed to convert RGBA image to byte array")
		}
	case *image.NRGBA:
		_, err := buf.Write(img.Pix)
		if err != nil {
			return nil, errors.New("Failed to convert NRGBA image to byte array")
		}
	case *image.Gray:
		_, err := buf.Write(img.Pix)
		if err != nil {
			return nil, errors.New("Failed to convert Gray image to byte array")
		}
	case *image.Gray16:
		_, err := buf.Write(img.Pix)
		if err != nil {
			return nil, errors.New("Failed to convert Gray16 image to byte array")
		}
	case *image.CMYK:
		_, err := buf.Write(img.Pix)
		if err != nil {
			return nil, errors.New("Failed to convert CMYK image to byte array")
		}
	case *image.Paletted:
		_, err := buf.Write(img.Pix)
		if err != nil {
			return nil, errors.New("Failed to convert Paletted image to byte array")
		}
	default:
		// convert it to RGBA
		rgba := image.NewRGBA(img.Bounds())
		draw.Draw(rgba, rgba.Bounds(), img, image.Point{}, draw.Over)
		if _, err := buf.Write(rgba.Pix); err != nil {
			return nil, fmt.Errorf("Failed to convert to RGBA image, unsupported image format: %T", img)
		}
	}

	return buf.Bytes(), nil
}


func readFileUncompressed(path string) ([]byte, error) {
	file, err := os.Open(path)
	if err != nil {
		return nil, fmt.Errorf("Failed to open file '%s': %v", path, err)
	}
	defer file.Close()

	image, _, err := image.Decode(file)
	if err != nil {
		return nil, fmt.Errorf("Failed to decode image: %v", err)
	}
	return getImageBytes(image)
}


const (
	CompressionNone = iota
	CompressionGzip
	CompressionZlib
)


func compress(input []byte, algorithm int) ([]byte, error) {
	var compressed bytes.Buffer
	var writer interface {
		Write(p []byte) (n int, err error)
		Close() error
	}

	switch algorithm {
	case CompressionGzip:
		writer = gzip.NewWriter(&compressed)
	case CompressionZlib:
		writer = zlib.NewWriter(&compressed)
	}

	_, err := writer.Write(input)
	if err != nil {
		return nil, fmt.Errorf("Failed to compress data: %v", err)
	}

	err = writer.Close()
	if err != nil {
		return nil, fmt.Errorf("Failed to close compress writer: %v", err)
	}

	return compressed.Bytes(), nil
}


func Fac(settings Settings) {
	var content []byte
	if settings.Uncompress {
		bytes, err := readFileUncompressed(settings.InputPath)
		if err != nil {
			fmt.Fprintln(os.Stderr, err)
			return
		}
		content = bytes
	} else {
		bytes, err := readFileCompressed(settings.InputPath)
		if err != nil {
			fmt.Fprintln(os.Stderr, err)
			return
		}
		content = bytes
	}


	if settings.Compression != CompressionNone {
		compressedContent, err := compress(content, settings.Compression)
		if err != nil {
			fmt.Fprintln(os.Stderr, err)
			return
		}
		content = compressedContent
	}


	outputFile := getOutputFile(settings.OutputPath)
	bufferedWriter := bufio.NewWriter(outputFile)

	writeHeader(bufferedWriter, settings.StdArray)
	writeArray(bufferedWriter, content, getConstVariant(settings.CStyle, settings.InlineVars), settings.WriteChars, settings.StdArray)
	fmt.Fprint(bufferedWriter, "#endif // FILE_AS_CODE_H")

	bufferedWriter.Flush()
	if outputFile != os.Stdout {
		outputFile.Close()
	}
}
