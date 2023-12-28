package fac

import "fmt"


type Settings struct {
    InputPath  string
    OutputPath string
    CStyle     bool
    StdArray   bool
    WriteChars bool
    InlineVars bool
    Uncompress bool
}


func Test(settings Settings) {
	fmt.Printf("Input: %s\n", settings.InputPath);
}