package fac

import (
	"io"
	"os"
	"fmt"
	"bytes"
	"bufio"
	"image"
	"image/png"
	"image/jpeg"
	"image/color"
	"compress/gzip"
	"compress/zlib"
)


func getDataFromFile(path string) (Parser, error) {
	file, err := os.Open(path)
	if err != nil {
		return Parser{}, fmt.Errorf("Failed to open file '%s': %v", path, err)
	}
	defer file.Close()

	growRate := 0
	fileInfo, err := file.Stat()
	if err == nil {
		growRate = int(fileInfo.Size())
	}

	parser := CreateParser(growRate)
	buffer := make([]byte, 4096)
	for {
		bytesRead, err := file.Read(buffer)
		if err != nil {
			if err == io.EOF {
				break
			}
			return Parser{}, fmt.Errorf("Failed to read from file: ", err)
		}
		parser.ParseChunk(buffer, bytesRead)
	}
	return parser, nil
}


func uncompress(data []byte, algorithm int) ([]byte, error) {
	var compressedReader io.Reader = bytes.NewReader(data)

	switch algorithm {
	case CompressionGzip:
		reader, err := gzip.NewReader(compressedReader)
		if err != nil {
			return nil, fmt.Errorf("Failed to create Gzip reader: %v", err)
		}
		defer reader.Close()
		var decompressed bytes.Buffer
		_, err = io.Copy(&decompressed, reader)
		if err != nil {
			return nil, fmt.Errorf("Failed to decompress Gzip data: %v", err)
		}
		return decompressed.Bytes(), nil
	case CompressionZlib:
		reader, err := zlib.NewReader(compressedReader)
		if err != nil {
			return nil, fmt.Errorf("Failed to create Zlib reader: %v", err)
		}
		defer reader.Close()
		var decompressed bytes.Buffer
		_, err = io.Copy(&decompressed, reader)
		if err != nil {
			return nil, fmt.Errorf("Failed to decompress Zlib data: %v", err)
		}
		return decompressed.Bytes(), nil
	}
	return data, nil
}


func Caf(settings Settings) {
	parser, err := getDataFromFile(settings.InputPath)
	if err != nil {
		fmt.Fprintln(os.Stderr, err)
		return
	}
	data := parser.data.Bytes()
	outputFile := GetOutputFile(settings.OutputPath)
	bufferedWriter := bufio.NewWriter(outputFile)

	if settings.Compression != CompressionNone {
		dataTmp, err := uncompress(data, settings.Compression)
		if err != nil {
			fmt.Fprintln(os.Stderr, err)
			return
		}
		data = dataTmp
	}

	if settings.FileType == FileJPEG || settings.FileType == FilePNG {
		if parser.width == 0 || parser.height == 0 || parser.channel == 0 {
			fmt.Fprintln(os.Stderr, "Failed to parse image properties")
			return
		} else if parser.channel < 3 {
			fmt.Fprintln(os.Stderr, "Image with less than 3 channels not supported")
			return
		}
		img := image.NewRGBA(image.Rect(0, 0, parser.width, parser.height))

		dataLen := len(data)
		for i := 0; i < dataLen; i += parser.channel {
			var alphaValue byte = 255
			if parser.channel == 4 {
				alphaValue = data[i+3]
			}
			img.Set(i / parser.channel % parser.width, i / parser.channel / parser.width, color.RGBA{
				R: data[i],
				G: data[i+1],
				B: data[i+2],
				A: alphaValue,
			})
		}

		if settings.FileType == FilePNG {
			err = png.Encode(bufferedWriter, img)
		} else {
			err = jpeg.Encode(bufferedWriter, img, nil)
		}

		if err != nil {
			fmt.Fprintln(os.Stderr, "Failed to encode image: ", err)
			return
		}
	} else {
		bufferedWriter.Write(data)
	}

	bufferedWriter.Flush()
	if outputFile != os.Stdout {
		outputFile.Close()
	}
}