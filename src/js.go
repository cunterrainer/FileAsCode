package fac

import (
	"fmt"
	"image"
	"bytes"
	"bufio"
	"strconv"
	"syscall/js"
	_ "image/gif"
	_ "image/png"
	_ "image/jpeg"
    "compress/flate"
)


func parseSettings(args[]js.Value) Settings {
	settings := Settings{
		CStyle:      args[1].Bool(),
		Shrink:      args[2].Bool(),
		StdArray:    args[3].Bool(),
		InlineVars:  args[4].Bool(),
		Uncompress:  args[5].Bool(),
		OutputRep:   args[6].Int(),
		Compression: args[7].Int(),
		CompressLvl: args[8].Int(),
	}

	//if settings.FileType == 0 {
	//	settings.FileType = FilePNG
	//} else {
	//	settings.FileType = FileJPEG
	//}

	settings.OutputRep += OutputHex
	settings.Compression += CompressionNone
	
	if settings.CompressLvl == 0 {
		settings.CompressLvl = flate.DefaultCompression
	} else if settings.CompressLvl == 1 {
		settings.CompressLvl = flate.BestSpeed
	} else {
		settings.CompressLvl = flate.BestCompression
	}
	return settings
}


func readBinaryUncompressed(data []byte) ([]byte, int, int, int, error) {
	image, _, err := image.Decode(bytes.NewReader(data))
	if err != nil {
		return nil, 0, 0, 0, fmt.Errorf("Failed to decode image: %v", err)
	}

	bytes, channel, err := getImageBytes(image)
	return bytes, channel, image.Bounds().Dx(), image.Bounds().Dy(), err
}


type DomWriter struct {
	element js.Value
	buffer  *bytes.Buffer
}

// Write writes bytes to the buffer.
func (w *DomWriter) Write(p []byte) (n int, err error) {
	return w.buffer.Write(p)
}

// Flush writes the buffer content to the DOM element and resets the buffer.
func (w *DomWriter) Flush() error {
	w.element.Set("value", w.buffer.String())
	w.buffer.Reset()
	return nil
}

func newDomWriter(element js.Value) *DomWriter {
	return &DomWriter{
		element: element,
		buffer:  new(bytes.Buffer),
	}
}


func FacJS() js.Func {
	jsonFunc := js.FuncOf(func(this js.Value, args[]js.Value) any{
		binaryData := args[0]
		data := make([]byte, binaryData.Get("length").Int())
		js.CopyBytesToGo(data, binaryData)
		settings := parseSettings(args)


		var content []byte
		var headerVariables string
		constVariant := getConstVariant(settings.CStyle, settings.InlineVars)
		
		if settings.Uncompress {
			bytes, channel, width, height, err := readBinaryUncompressed(data)
			if err != nil {
				return err.Error()
			}
			content = bytes
			intType := getIntType(settings.StdArray)
			headerVariables += constVariant + " " + intType + " sg_File_as_code_width   = " + strconv.Itoa(width) + ";\n"
			headerVariables += constVariant + " " + intType + " sg_File_as_code_height  = " + strconv.Itoa(height) + ";\n"
			headerVariables += constVariant + " " + intType + " sg_File_as_code_channel = " + strconv.Itoa(channel) + ";\n\n"
		} else {
			// binary already in compressed format
			content = data
		}


		if settings.Compression != CompressionNone {
			compressedContent, err := compress(content, settings.Compression, settings.CompressLvl)
			if err != nil {
				return err.Error()
			}
			content = compressedContent
		}


		jsDoc := js.Global().Get("document")
		if !jsDoc.Truthy() {
			return "Unable to get document object"
		}

		testOutputArea := jsDoc.Call("getElementById", "textOutput")
		if !testOutputArea.Truthy() {
			return "Unable to get output text area"
		}


		domWriter := newDomWriter(testOutputArea)
		bufferedWriter := bufio.NewWriter(domWriter)

		writeHeader(bufferedWriter, headerVariables, settings.StdArray, settings.Compression)
		writeArray(bufferedWriter, content, constVariant, settings.OutputRep, settings.StdArray, settings.Shrink)
		fmt.Fprint(bufferedWriter, "#endif // FILE_AS_CODE_H")

		bufferedWriter.Flush()
		domWriter.Flush()
		return ""
	});
	return jsonFunc
}