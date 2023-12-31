package fac

import (
	"bytes"
	"fmt"
	"os"
	"strconv"
	"strings"
)


type Parser struct {
	foundStart bool
	data bytes.Buffer
	remaining string
	width int
	height int
	channel int
}


func CreateParser(growRate int) Parser {
	p := Parser{
		foundStart: false,
		remaining: "",
		width: 0,
		height: 0,
		channel: 0,
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
				byteValue, valueError = strconv.ParseUint(string(block[2:4]), 16, 8)
			} else if block[0] == '0' && block[1] == 'b' {
				byteValue, valueError = strconv.ParseUint(string(block[2:10]), 2, 8)
			} else if block[1] == ',' || block[1] == '}' { // decimal 0 - 9
				byteValue, valueError = strconv.ParseUint(string(block[0:1]), 10, 8)
			} else if block[2] == ',' || block[2] == '}' { // decimal 10 - 99
				byteValue, valueError = strconv.ParseUint(string(block[0:2]), 10, 8)
			} else if block[3] == ',' || block[3] == '}' { // decimal 100 - 255
				byteValue, valueError = strconv.ParseUint(string(block[0:3]), 10, 8)
			}
			break
		}
	}
	return byte(byteValue), found, idx, valueError
}


func getIntVariable(chunk []byte) (uint64, int) {
	size := len(chunk)

	for i := 0; i < size; i++ {
		if chunk[i] != ';' {
			continue
		}

		block := string(chunk[0:i])
		block = strings.ReplaceAll(block, " ", "")
		block = strings.ReplaceAll(block, "\t", "")
		block = strings.ReplaceAll(block, "\n", "")
		block = strings.ReplaceAll(block, "\r", "")
		value, _ := strconv.ParseUint(block, 10, 64)
		return value, i
	}
	return 0, 0
}


func (p* Parser) setImageProperty(value int) {
	if p.width == 0 {
		p.width = value
	} else if p.height == 0 {
		p.height = value
	} else if p.channel == 0 {
		p.channel = value
	}
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

		if !p.foundStart {
			if chunk[i] == '{' {
				p.foundStart = true
			} else if chunk[i] == '=' {
				value, idx := getIntVariable(chunk[i+1:totalSize])
				i += idx
				p.setImageProperty(int(value))
			}
			continue
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