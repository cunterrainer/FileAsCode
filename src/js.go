package fac

import (
	"fmt"
	"image"
	"bytes"
	"bufio"
	"strconv"
	"syscall/js"
	"image/png"
	"image/jpeg"
	"image/color"
	_ "image/gif"
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

func (w *DomWriter) Bytes() []byte {
	return w.buffer.Bytes()
}

func newDomWriter(element js.Value) *DomWriter {
	return &DomWriter{
		element: element,
		buffer:  new(bytes.Buffer),
	}
}


func FacJS() js.Func {
	facFunc := js.FuncOf(func(this js.Value, args[]js.Value) any{
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
	return facFunc
}


// caf
func parseFile(data []byte) Parser {
	parser := CreateParser(len(data))
	chunkSize := 4096
	for start := 0; start < len(data); start += chunkSize {
		end := start + chunkSize
		if end > len(data) {
			end = len(data)
		}
		parser.ParseChunk(data[start:end], end-start)
	}
	return parser
}


func CafJS() js.Func {
	cafFunc := js.FuncOf(func(this js.Value, args[]js.Value) any{
		settings := Settings{
			FileType: args[1].Int(),
			Compression: args[2].Int(),
		}

		if settings.FileType == 1 {
			settings.FileType = FilePNG
		} else if settings.FileType == 2 {
			settings.FileType = FileJPEG
		}


		fileDataJS := args[0]
		fileData := make([]byte, fileDataJS.Get("length").Int())
		js.CopyBytesToGo(fileData, fileDataJS)
		parser := parseFile(fileData);

		data := parser.data.Bytes()
		var outputBuffer bytes.Buffer
		bufferedWriter := bufio.NewWriter(&outputBuffer)

		if settings.Compression != CompressionNone {
			dataTmp, err := uncompress(data, settings.Compression)
			if err != nil {
				//fmt.Fprintln(os.Stderr, err)
				return err.Error()
			}
			data = dataTmp
		}

		if settings.FileType == FileJPEG || settings.FileType == FilePNG {
			if parser.width == 0 || parser.height == 0 || parser.channel == 0 {
				//fmt.Fprintln(os.Stderr, "Failed to parse image properties")
				return "Failed to parse image properties"
			} else if parser.channel < 3 {
				//fmt.Fprintln(os.Stderr, "Image with less than 3 channels not supported")
				return "Image with less than 3 channels not supported"
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

			var err error
			if settings.FileType == FilePNG {
				err = png.Encode(bufferedWriter, img)
			} else {
				err = jpeg.Encode(bufferedWriter, img, nil)
			}

			if err != nil {
				//fmt.Fprintln(os.Stderr, "Failed to encode image: ", err)
				return "Failed to encode image: "
			}
		} else {
			bufferedWriter.Write(data)
		}

		bufferedWriter.Flush()

		byteArray := outputBuffer.Bytes()
		uint8Array := js.Global().Get("Uint8Array").New(len(byteArray))
		js.CopyBytesToJS(uint8Array, byteArray)
		return uint8Array
	});
	return cafFunc;
}