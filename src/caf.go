package fac

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"image"
	"image/color"
	_"image/png"
	"image/jpeg"
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


func Caf(settings Settings) {
	parser, err := getDataFromFile(settings.InputPath)
	if err != nil {
		fmt.Fprintln(os.Stderr, err)
		return
	}
	data := parser.data.Bytes()
	outputFile := GetOutputFile(settings.OutputPath)
	bufferedWriter := bufio.NewWriter(outputFile)

	if settings.Uncompress {
		if parser.width == 0 || parser.height == 0 || parser.channel == 0 {
			fmt.Fprintln(os.Stderr, "Failed to parse image properties")
			return
		}
		img := image.NewRGBA(image.Rect(0, 0, parser.width, parser.height))

		dataLen := len(data)
		for i := 0; i < dataLen; i += 3 {
			img.Set(i / parser.channel % parser.width, i / parser.channel / parser.width, color.RGBA{
				R: data[i],
				G: data[i+1],
				B: data[i+2],
				A: 255,
			})
		}

		err = jpeg.Encode(bufferedWriter, img, nil)
		if err != nil {
			fmt.Fprintln(os.Stderr, "Failed to encode png image: ", err)
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