package fac

import (
	"bufio"
	"fmt"
	"io"
	"os"
)


func getDataFromFile(path string) ([]byte, error) {
	file, err := os.Open(path)
	if err != nil {
		return nil, fmt.Errorf("Failed to open file '%s': %v", path, err)
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
			return nil, fmt.Errorf("Failed to read from file: ", err)
		}
		parser.ParseChunk(buffer, bytesRead)
	}
	return parser.data.Bytes(), nil
}


func Caf(settings Settings) {
	data, err := getDataFromFile(settings.InputPath)
	if err != nil {
		fmt.Fprintln(os.Stderr, err)
		return
	}

	outputFile := GetOutputFile(settings.OutputPath)
	bufferedWriter := bufio.NewWriter(outputFile)
	bufferedWriter.Write(data)
	bufferedWriter.Flush()
	if outputFile != os.Stdout {
		outputFile.Close()
	}
}