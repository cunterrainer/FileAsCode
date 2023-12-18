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

# Prebuilt Binaries

For your convenience, prebuilt binaries are available in the `bin/` folder. These binaries are compiled for Windows and Linux operating systems.

## Version Compatibility

Please note that the prebuilt binaries may be associated with a specific version of FileAsCode. Ensure that you are using a compatible version to avoid potential compatibility issues. If needed, you can also build the program from source following the instructions in the Build section.

If you encounter any platform-specific issues or have questions about the prebuilt binaries, feel free to reach out on the [GitHub repository](https://github.com/pyvyx/FileAsCode/issues).


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
zig build -Doptimize=ReleaseSafe
```

# Troubleshooting

If you encounter any issues while building or using FileAsCode with Zig, here are some troubleshooting steps you can follow:

## Zig Compiler Issues

1. **Zig API Changes:**
    - If the program can't compile due to breaking API changes in Zig, make sure you are using a compatible version of the Zig compiler. FileAsCode was developed using version `0.12.0-dev.1830+779b8e259` Zig, and newer versions might introduce breaking changes. Check the [Zig GitHub repository](https://github.com/ziglang/zig) for information on the latest stable release or the [Zig download page](https://ziglang.org/download/) to download a different version

2. **Missing Zig Compiler:**
    - Ensure that you have Zig installed on your system. You can download Zig from the [official Zig website](https://ziglang.org/download/).

3. **Platform Compatibility:**
    - Verify that your platform is supported by Zig. Some platforms might not have pre-built Zig binaries available. Refer to the Zig documentation for information on supported platforms.

## Switching to C++ Version

If you encounter persistent issues with the Zig version or your platform lacks Zig support, you can try the C++ version available in the `cpp` branch. The C++ version has a similar set of features, albeit with slight differences. Follow these steps to switch to the C++ version:

1. **Switch to the `cpp` Branch:**
    - Execute the following commands to switch to the `cpp` branch:

     ```bash
     git checkout cpp
     ```

2. **Build the C++ Version:**
    - Follow the instructions from the [cpp readme](https://github.com/pyvyx/FileAsCode/tree/cpp).