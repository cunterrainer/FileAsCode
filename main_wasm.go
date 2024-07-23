// +build wasm

package main

import (
	"syscall/js"	
	fac "github.com/pyvyx/FileAsCode/src"
)

func main() {
	js.Global().Set("FacJS", fac.FacJS())
	js.Global().Set("CafJS", fac.CafJS())
	<-make(chan struct{})
}