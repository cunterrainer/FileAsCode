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

However there is one downside to using a "non compatible" type, the program does also write the width, height and channels of the image into the header file, those numbers will be wrong, but the array is still valid aswell as the provided `relative_size` variable.
