# Image2CArray

## A program to convert an image into a C/C++ style array
In fact not only images can be converted. It can also be used for fonts or any other file format you'd like to have an array of. However when converting a file you
have two options to choose from, `-r`/`-raw` and `-uncompressed`/`-uc`, the raw option can be used for any arbitrary file type, the uncompressed is only going to work with following types:
 - JPEG baseline & progressive (12 bpc/arithmetic not supported, same as stock IJG lib)
 - PNG 1/2/4/8/16-bit-per-channel
 - TGA (not sure what subset, if a subset)
 - BMP non-1bpp, non-RLE
 - PSD (composited view only, no extra channels, 8/16 bit-per-channel)
 - GIF (*comp always reports as 4-channel)
 - HDR (radiance rgbE format)
 - PIC (Softimage PIC)
 - PNM (PPM and PGM binary only)

However there is one downside to using a "non compatible" type, the program does also write the width, height and channels of the image into the header file, those numbers will be wrong, but the array and the provided `relative_size` variable are still valid. For more informations use the `-h` flag.

# Build
If you're on windows you can simply use the provided binary that can be found in the release section.  
Build it yourself:
```
git clone https://github.com/pyvyx/Image2CArray.git
cd Image2CArray
```
Visual studio (works aswell for vs2019)  
```
vendor/premake5 vs2022
```
gcc  
```
vendor/premake5 gmake --cc=gcc
```
clang
```
vendor/premake5 gmake --cc=clang
```
gcc/clang
```
make <-j> config=<configuration>
```
Configurations:
 - debug_x86
 - debug_x64 (default, the same as just using `make`)
 - release_x86
 - release_x64

The `-j` flag uses multithreaded compilation and is also optional since the project is quiet small it's pretty fast compiled.
