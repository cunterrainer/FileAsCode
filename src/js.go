package fac

import (
	"fmt"
	"syscall/js"
    "compress/flate"
)

func FacJS() js.Func {
	jsonFunc := js.FuncOf(func(this js.Value, args[]js.Value) any{
		if len(args) != 11 {
			return "Invalid no of arguments"
		}

		settings := Settings{
			InputPath:   args[0].String(),
			CStyle:      args[1].Bool(),
			Shrink:      args[2].Bool(),
			Reverse:     args[3].Bool(),
			StdArray:    args[4].Bool(),
			InlineVars:  args[5].Bool(),
			Uncompress:  args[6].Bool(),
			FileType:    args[7].Int(),
			OutputRep:   args[8].Int(),
			Compression: args[9].Int(),
			CompressLvl: args[10].Int(),
		}

		if settings.FileType == 0 {
			settings.FileType = FilePNG
		} else {
			settings.FileType = FileJPEG
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

		// For demonstration purposes, print the settings
		fmt.Println(settings)

		return "Test";
	});
	return jsonFunc
}