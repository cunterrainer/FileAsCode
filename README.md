# Image2CArray

## A program to convert an image into a C/C++ style array
In fact not only images can be converted. It can also be used for fonts or any other file format you'd like to have an array of. However when converting a file there
you have two options to choose from, `-r` or `-raw` and 
`-uncompressed` or `-uc`, the raw options can be used for any arbitrary file type, the uncompressed is only
going to work with following types:
 - JPEG baseline & progressive (12 bpc/arithmetic not supported, same as stock IJG lib)
 - PNG 1/2/4/8/16-bit-per-channel
 - TGA (not sure what subset, if a subset)
 - BMP non-1bpp, non-RLE
 - PSD (composited view only, no extra channels, 8/16 bit-per-channel)
 - GIF (*comp always reports as 4-channel)
 - HDR (radiance rgbE format)
 - PIC (Softimage PIC)
 - PNM (PPM and PGM binary only)
