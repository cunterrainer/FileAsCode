package fac

import (
	"bufio"
	"bytes"
	"compress/gzip"
	"compress/zlib"
	"errors"
	"fmt"
	"image"
	_ "image/gif"
	_ "image/jpeg"
	_ "image/png"
	"io"
	"os"
	"strconv"
)

type Settings struct {
	InputPath   string
	OutputPath  string
	CStyle      bool
	Shrink      bool
	Reverse     bool
	StdArray    bool
	InlineVars  bool
	Uncompress  bool
	FileType    int
	OutputRep   int
	Compression int
	CompressLvl int
}

const (
	CompressionNone = iota
	CompressionGzip
	CompressionZlib

	OutputHex // default
	OutputChars
	OutputBinary
	OutputDecimal

	FilePNG
	FileJPEG
)

func writeHeader(w io.Writer, headerVariables string, stdArray bool, compression int) {
	fmt.Fprintln(w, "#ifndef FILE_AS_CODE_H")
	fmt.Fprintln(w, "#define FILE_AS_CODE_H")
	if stdArray {
		fmt.Fprintln(w, "#include <array>")
		fmt.Fprintln(w, "#include <cstdint>")
	}
	fmt.Fprintln(w, "//////////////////////////////////////////////////////////////////////////////////")
	fmt.Fprintln(w, "//                                                                              //")
	fmt.Fprintln(w, "// FileAsCode exporter                                                          //")
	fmt.Fprintln(w, "//                                                                              //")
	fmt.Fprintln(w, "// more infos and bug-reports: https://github.com/cunterrainer/FileAsCode       //")
	fmt.Fprintln(w, "//                                                                              //")
	fmt.Fprintln(w, "// or try out the web version: https://cunterrainer.github.io/FileAsCode/       //")
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

func writeArray(w io.Writer, bytes []byte, constVariant string, outputRep int, stdArray bool, shrink bool) {
	bytesLen := len(bytes)

	if stdArray {
		fmt.Fprintf(w, "%s std::array<std::uint8_t, %d> sg_File_as_code =\n{\n", constVariant, bytesLen)
	} else {
		fmt.Fprintf(w, "%s unsigned char sg_File_as_code[] =\n{\n", constVariant)
	}

	if !shrink {
		fmt.Fprintf(w, "\t")
	}

	nextLineMod := 16
	if outputRep == OutputBinary {
		nextLineMod = 8
	} else if outputRep == OutputDecimal {
		nextLineMod = 19
	}

	for i, b := range bytes {
		processed := i + 1

		if shrink {
			if processed == bytesLen {
				fmt.Fprintf(w, "%d\n};\n", b)
			} else {
				fmt.Fprintf(w, "%d,", b)
			}
		} else if processed == bytesLen {
			if outputRep == OutputChars {
				writeByteAsChar(w, b)
				fmt.Fprint(w, "\n};\n")
			} else if outputRep == OutputBinary {
				fmt.Fprintf(w, "0b%08b\n};\n", b)
			} else if outputRep == OutputDecimal {
				fmt.Fprintf(w, "%3d\n};\n", b)
			} else {
				fmt.Fprintf(w, "0x%02X\n};\n", b)
			}
		} else if processed%nextLineMod == 0 {
			if outputRep == OutputChars {
				writeByteAsChar(w, b)
				fmt.Fprint(w, ",\n\t")
			} else if outputRep == OutputBinary {
				fmt.Fprintf(w, "0b%08b,\n\t", b)
			} else if outputRep == OutputDecimal {
				fmt.Fprintf(w, "%3d,\n\t", b)
			} else {
				fmt.Fprintf(w, "0x%02X,\n\t", b)
			}
		} else {
			if outputRep == OutputChars {
				writeByteAsChar(w, b)
				fmt.Fprintf(w, ", ")
			} else if outputRep == OutputBinary {
				fmt.Fprintf(w, "0b%08b, ", b)
			} else if outputRep == OutputDecimal {
				fmt.Fprintf(w, "%3d, ", b)
			} else {
				fmt.Fprintf(w, "0x%02X, ", b)
			}
		}
	}

	if !stdArray {
		fmt.Fprintf(w, "%s unsigned long long sg_File_as_code_size = sizeof(sg_File_as_code) / sizeof(*sg_File_as_code);\n", constVariant)
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

func getIntType(stdArray bool) string {
	if stdArray {
		return "std::size_t"
	} else {
		return "unsigned int"
	}
}

func GetOutputFile(outputPath string) *os.File {
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
		capacity := img.Bounds().Dx() * img.Bounds().Dy() * 3
		buf.Grow(capacity)

		for y := img.Bounds().Min.Y; y < img.Bounds().Max.Y; y++ {
			for x := img.Bounds().Min.X; x < img.Bounds().Max.X; x++ {
				r, g, b, _ := img.At(x, y).RGBA()

				// Normalize the values to the range of 0-255 with rounding
				r = (uint32(r)*0xFF + 0x7FFF) / 0xFFFF
				g = (uint32(g)*0xFF + 0x7FFF) / 0xFFFF
				b = (uint32(b)*0xFF + 0x7FFF) / 0xFFFF

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
		intType := getIntType(settings.StdArray)
		headerVariables += constVariant + " " + intType + " sg_File_as_code_width   = " + strconv.Itoa(width) + ";\n"
		headerVariables += constVariant + " " + intType + " sg_File_as_code_height  = " + strconv.Itoa(height) + ";\n"
		headerVariables += constVariant + " " + intType + " sg_File_as_code_channel = " + strconv.Itoa(channel) + ";\n\n"
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

	outputFile := GetOutputFile(settings.OutputPath)
	bufferedWriter := bufio.NewWriter(outputFile)

	writeHeader(bufferedWriter, headerVariables, settings.StdArray, settings.Compression)
	writeArray(bufferedWriter, content, constVariant, settings.OutputRep, settings.StdArray, settings.Shrink)
	fmt.Fprint(bufferedWriter, "#endif // FILE_AS_CODE_H")

	bufferedWriter.Flush()
	if outputFile != os.Stdout {
		outputFile.Close()
	}
}
