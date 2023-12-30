package fac

import (
	"io"
	"os"
	"fmt"
	"image"
	"bufio"
	"bytes"
	"errors"
	"strconv"
	_ "image/gif"
	_ "image/png"
	_ "image/jpeg"
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
	CompressLvl int
}


func writeHeader(w io.Writer, headerVariables string, stdArray bool, compression int) {
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
	if compression == CompressionGzip {
		fmt.Fprintln(w, "//                                                                              //")
		fmt.Fprintln(w, "// Compression: gzip                                                            //")
	} else if compression == CompressionZlib {
		fmt.Fprintln(w, "//                                                                              //")
		fmt.Fprintln(w, "// Compression: zlib                                                            //")
	}
	fmt.Fprintln(w, "//                                                                              //")
	fmt.Fprintln(w, "//////////////////////////////////////////////////////////////////////////////////")
	fmt.Fprintln(w)
	fmt.Fprint(w, headerVariables)
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

	if !stdArray {
		fmt.Fprintf(w, "%s unsigned int sg_File_as_code_size = sizeof(sg_File_as_code) / sizeof(*sg_File_as_code);\n", constVariant)
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


func getImageBytes(img image.Image) ([]byte, int, error) {
	var buf bytes.Buffer
	var channel int

	switch img := img.(type) {
	case *image.RGBA:
		channel = 4
		_, err := buf.Write(img.Pix)
		if err != nil {
			return nil, 0, errors.New("Failed to convert RGBA image to byte array")
		}
	case *image.NRGBA:
		channel = 4
		_, err := buf.Write(img.Pix)
		if err != nil {
			return nil, 0, errors.New("Failed to convert NRGBA image to byte array")
		}
	case *image.Gray:
		channel = 1
		_, err := buf.Write(img.Pix)
		if err != nil {
			return nil, 0, errors.New("Failed to convert Gray image to byte array")
		}
	case *image.Gray16:
		channel = 1
		_, err := buf.Write(img.Pix)
		if err != nil {
			return nil, 0, errors.New("Failed to convert Gray16 image to byte array")
		}
	case *image.CMYK:
		channel = 4
		_, err := buf.Write(img.Pix)
		if err != nil {
			return nil, 0, errors.New("Failed to convert CMYK image to byte array")
		}
	case *image.Paletted:
		channel = 1
		_, err := buf.Write(img.Pix)
		if err != nil {
			return nil, 0, errors.New("Failed to convert Paletted image to byte array")
		}
	default:
		// Create RGB image
		channel = 3
		capacity := img.Bounds().Dx()*img.Bounds().Dy()*3
		buf.Grow(capacity)

		for y := img.Bounds().Min.Y; y < img.Bounds().Max.Y; y++ {
			for x := img.Bounds().Min.X; x < img.Bounds().Max.X; x++ {
				r, g, b, _ := img.At(x, y).RGBA()

				// Normalize the values to the range of 0-255 with rounding
				r = (uint32(r) * 0xFF + 0x7FFF) / 0xFFFF
				g = (uint32(g) * 0xFF + 0x7FFF) / 0xFFFF
				b = (uint32(b) * 0xFF + 0x7FFF) / 0xFFFF

				buf.WriteByte(byte(r))
				buf.WriteByte(byte(g))
				buf.WriteByte(byte(b))
			}
		}
	}

	return buf.Bytes(), channel, nil
}


func readFileUncompressed(path string) ([]byte, int, int, int, error) {
	file, err := os.Open(path)
	if err != nil {
		return nil, 0, 0, 0, fmt.Errorf("Failed to open file '%s': %v", path, err)
	}
	defer file.Close()

	image, _, err := image.Decode(file)
	if err != nil {
		return nil, 0, 0, 0, fmt.Errorf("Failed to decode image: %v", err)
	}

	bytes, channel, err := getImageBytes(image)
	return bytes, channel, image.Bounds().Dx(), image.Bounds().Dy(), err
}


const (
	CompressionNone = iota
	CompressionGzip
	CompressionZlib
)


func compress(input []byte, algorithm int, compressionLevel int) ([]byte, error) {
	var compressed bytes.Buffer
	var writer interface {
		Write(p []byte) (n int, err error)
		Close() error
	}

	switch algorithm {
	case CompressionGzip:
		writer, _ = gzip.NewWriterLevel(&compressed, compressionLevel)
	case CompressionZlib:
		writer, _ = zlib.NewWriterLevel(&compressed, compressionLevel)
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
	var headerVariables string
	constVariant := getConstVariant(settings.CStyle, settings.InlineVars)

	if settings.Uncompress {
		bytes, channel, width, height, err := readFileUncompressed(settings.InputPath)
		if err != nil {
			fmt.Fprintln(os.Stderr, err)
			return
		}
		content = bytes
		headerVariables += constVariant + " unsigned char sg_File_as_code_width   = " + strconv.Itoa(width) + ";\n"
		headerVariables += constVariant + " unsigned char sg_File_as_code_height  = " + strconv.Itoa(height) + ";\n"
		headerVariables += constVariant + " unsigned char sg_File_as_code_channel = " + strconv.Itoa(channel) + ";\n\n"
	} else {
		bytes, err := readFileCompressed(settings.InputPath)
		if err != nil {
			fmt.Fprintln(os.Stderr, err)
			return
		}
		content = bytes
	}

	if settings.Compression != CompressionNone {
		compressedContent, err := compress(content, settings.Compression, settings.CompressLvl)
		if err != nil {
			fmt.Fprintln(os.Stderr, err)
			return
		}
		content = compressedContent
	}

	outputFile := getOutputFile(settings.OutputPath)
	bufferedWriter := bufio.NewWriter(outputFile)

	writeHeader(bufferedWriter, headerVariables, settings.StdArray, settings.Compression)
	writeArray(bufferedWriter, content, constVariant, settings.WriteChars, settings.StdArray)
	fmt.Fprint(bufferedWriter, "#endif // FILE_AS_CODE_H")

	bufferedWriter.Flush()
	if outputFile != os.Stdout {
		outputFile.Close()
	}
}