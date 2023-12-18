# File as code

## A program to convert files into C arrays
Raw conversion supports every single file type, that conversion to just get the binary representation of a file as an array. Uncompressed files `-u` or `--uncompressed` are currenty only supported for following image formats:  
 - JPEG baseline & progressive (12 bpc/arithmetic not supported, same as stock IJG lib)
 - PNG 1/2/4/8/16-bit-per-channel
 - TGA (not sure what subset, if a subset)
 - BMP non-1bpp, non-RLE
 - PSD (composited view only, no extra channels, 8/16 bit-per-channel)
 - GIF (*comp always reports as 4-channel)
 - HDR (radiance rgbE format)
 - PIC (Softimage PIC)
 - PNM (PPM and PGM binary only)

# Build
If you're on windows you can simply use the provided binary that can be found in the release section.  
Build it yourself:
```
git clone https://github.com/pyvyx/FileAsCode.git
```
```
cd FileAsCode
```

```
zig build -Doptimize=ReleaseFast
```