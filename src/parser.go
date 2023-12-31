package fac

import (
	"os"
	"fmt"
	"bytes"
	"strconv"
	"strings"
)


type Parser struct {
	foundEnd   bool
	foundStart bool
	data bytes.Buffer
	remaining string
}


func CreateParser(growRate int) Parser {
	p := Parser{
		foundEnd: false,
		foundStart: false,
	}
	if growRate > 0 {
		p.data.Grow(growRate)
	}
	return p
}


func getNextValue(rest []byte) (byte, bool, int, error) {
	var byteValue uint64
	var valueError error = nil
	idx := 0
	found := false
	size := len(rest)
	for i := 0; i < size; i++ {

		if rest[i] == '\'' {
			found = true
			var block string
			if rest[i + 1] == '\\' {
				block = string(rest[i+1:i+3])
				switch (block[1]) {
				case '0': byteValue = 0
				case 'n': byteValue = '\n'
				case 'r': byteValue = '\r'
				case 't': byteValue = '\t'
				case '\\': byteValue = '\\'
				case '"': byteValue = '"'
				case '\'': byteValue = '\''
				}
				idx = i+4
			} else {
				block = string(rest[i+1:i+2])
				byteValue = uint64(block[0])
				idx = i+3
			}
			break
		} else if rest[i] == ',' || rest[i] == '}' {
			idx = i
			found = true
			block := string(rest[0:i+1]) // to include either , or } to safely access index 1
			block = strings.ReplaceAll(block, " ", "")
			block = strings.ReplaceAll(block, "\t", "")
			block = strings.ReplaceAll(block, "\n", "")
			block = strings.ReplaceAll(block, "\r", "")
			if block[0] == '0' && block[1] == 'x' {
				block = string(block[2:4])
				byteValue, valueError = strconv.ParseUint(block, 16, 8)
				//return string(block[2:4]), i
			} else if block[0] == '0' && block[1] == 'b' {
				block = string(block[2:10])
				byteValue, valueError = strconv.ParseUint(block, 2, 8)
				//return string(block[2:10]), i
			} else if block[1] == ',' || block[1] == '}' { // decimal 0 - 9
				block = string(block[0:1])
				byteValue, valueError = strconv.ParseUint(block, 10, 8)
				//return string(block[0:1]), i
			} else if block[2] == ',' || block[2] == '}' { // decimal 10 - 99
				block = string(block[0:2])
				byteValue, valueError = strconv.ParseUint(block, 10, 8)
				//return string(block[0:2]), i
			} else if block[3] == ',' || block[3] == '}' { // decimal 100 - 255
				block = string(block[0:3])
				byteValue, valueError = strconv.ParseUint(block, 10, 8)
				//return string(block[0:3]), i
			}
			break
			//return "block", i
		}
	}
	return byte(byteValue), found, idx, valueError
}


func (p* Parser) ParseChunk(fileData []byte, fileDataSize int) {
	chunk := append([]byte(p.remaining), fileData[0:fileDataSize]...)
	totalSize := len(p.remaining) + fileDataSize
	p.remaining = ""

	for i := 0; i < totalSize; i++ {
		if totalSize - i <= 20 { // 20 because the longest entry can be 10 bytes (0b00000000) + , + spaces etc.
			p.remaining = string(chunk[i:totalSize])
			return
		}

		if !p.foundStart || p.foundEnd {
			if chunk[i] == '{' {
				p.foundStart = true
			}
			continue
		}

		if chunk[i] == '}' {
			p.foundEnd = true
			return
		}

		value, found, idx, err := getNextValue(chunk[i:totalSize])
		if !found {
			return
		} else if err != nil {
			fmt.Fprintf(os.Stderr, "Failed to parse byte: %v\n", err)
			continue
		}
		p.data.WriteByte(value)
		i += idx
	}
}