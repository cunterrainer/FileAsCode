#include <iostream>
#include <fstream>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include "utility/datatypes.h"
#include "utility/iocautil.h"
#include "utility/filesystemutil.h"
#include "utility/stringutil.h"

class Image
{
private:
    dt::int32 m_Width, m_Height, m_Channels;
    unsigned char* m_Data;
    const std::string& m_FilePath;
    const std::string& m_OutputPath;
public:
    Image(const std::string& filepath, const std::string& outputpath) : m_FilePath(filepath), m_OutputPath(outputpath) {
        m_Data = stbi_load(filepath.c_str(), &m_Width, &m_Height, &m_Channels, 0);
    }
    ~Image() { stbi_image_free(m_Data); }

    dt::int32 GetWidth() const { return m_Width; }
    dt::int32 GetHeight() const { return m_Height; }
    dt::int32 GetChannels() const { return m_Channels; }
    unsigned char* GetData() const { return m_Data; }
    const std::string& GetFilePath() const { return m_FilePath; }
    const std::string& GetOutputPath() const { return m_OutputPath; }
    void WriteData(std::ostream& os, const std::string& constDecl, const std::size_t dataSize, const std::string& dataName) const {
        os << constDecl << " int sg_Width = " << m_Width << ";\n";
        os << constDecl << " int sg_Height = " << m_Height << ";\n";
        os << constDecl << " int sg_Channels = " << m_Channels << ";\n";
        os << constDecl << " int sg_DataSize = sg_Width * sg_Height * sg_Channels; //" << m_Width * m_Height * m_Channels << "\n\n";
    
        os << constDecl << " int " << dataName << "Size = " << dataSize << ";\n";
        os << constDecl << " unsigned char " << dataName << "[" << dataSize << "] =\n{\n\t";
    }
};


#define WRITE_RAW_EX 0b0001
#define WRITE_UNCOMP_EX 0b0010
void WriteExample(std::ostream& os, dt::int8 mode, bool indent) {
    char indentChar = indent ? '\t' : ' ';
    if(mode & WRITE_RAW_EX) {
        os << indentChar << "Example of writing an png file:\n";
        os << indentChar << "Example with raw data (-r) (using stb_image):\n";
        os << indentChar << "\tint width, height, channels;\n";
        os << indentChar << "\tunsigned char* data = stbi_load_from_memory(sg_RawImageData, sg_RawImageDataSize, &width, &height, &channels, 0);\n";
        os << indentChar << "\tstbi_write_png(\"test.png\", sg_Width, sg_Height, sg_Channels, data, sg_Width * sg_Channels\n";
        os << indentChar << "\tstbi_image_free(data);\n\n";
    }
    if(mode & WRITE_UNCOMP_EX)
    {
        os << indentChar << "Example with uncompressed (-uc) data (using stb_image):\n";
        os << indentChar << "\tstbi_write_png(\"test.png\", sg_Width, sg_Height, sg_Channels, sg_ImageData, sg_Width * sg_Channels);\n\n";
    }
}


void WriteHeaderComment(std::ostream& os, const bool rawVersion, const std::string& filepath, const std::string& dataName) {
    os << "/*\n";
    if(rawVersion) {
        os << "\tThis is the raw data representation of " << filepath << "\n";
        os << "\tRaw means that the data array still has to be loaded into memory before you can use it.\n\n";
        WriteExample(os, WRITE_RAW_EX, true);
    } else {
        os << "\tThis is the uncompressed data representation of " << filepath << "\n";
        os << "\tUncompressed means that the data is already \"loaded\" into memory. That means you can use it the way it is,\n";
        os << "\twithout having to load it into memory first.\n";
        os << "\tThis is useful for large images that have you don't want to load during runtime.\n\n";
        WriteExample(os, WRITE_UNCOMP_EX, true);
    }
    os << "\tsg_Width    = The width of the image\n";
    os << "\tsg_Height   = The height of the image\n";
    os << "\tsg_Channels = The number of channels of the image\n";
    os << "\tsg_DataSize = The size of the data array after loading it into memory\n\n";
    os << "\t" << dataName << "Size = size of the data array\n";
    os << "\t" << dataName << "     = The data array\n";
    os << "\t" << dataName << "RelativeSize(At the bottom) = The size of the data array relative to it's type size and the number of values\n";
    os << "*/\n\n";
}


bool WriteUncompressedImageToFile(const Image& image, const std::string& constDecl) {
    std::ofstream outfile(image.GetOutputPath());
    if(!outfile.is_open()) {
        std::cout << "Could not open file " << image.GetOutputPath() << " for writing.\n";
        return false;
    }
    std::string dataName = "sg_" + util::string::CapitalizeCopy(util::string::RemoveCharCopy(util::fs::GetFileName(image.GetFilePath()), '.')) + "Data";
    WriteHeaderComment(outfile, false, image.GetFilePath(), dataName);

    std::size_t dataSize = image.GetWidth() * image.GetHeight() * image.GetChannels();
    image.WriteData(outfile, constDecl, dataSize, dataName);

    outfile << std::hex << std::uppercase;
    
    for (std::size_t i = 0; i < dataSize; i++) {
        int c = image.GetData()[i];
        if(c < 0x10)
            outfile << "0x0" << c;
        else
            outfile << "0x" << c;

        if(i == dataSize - 1)
            continue;

        outfile << ", ";

        if(i % 16 == 15) {
            outfile << "\n\t";
        }
    }
    outfile << "\n};\n";
    outfile << constDecl << " int " << dataName << "RelativeSize = sizeof(" << dataName << ") / sizeof(unsigned char);";
    outfile.close();
    return true;
}


bool WriteRawImageToFile(const Image& image, const std::string& constDecl) {
    std::ifstream input(image.GetFilePath(), std::ifstream::ate | std::ios::binary);
    if(!input.is_open()) {
        std::cout << "Could not open input file: " << image.GetFilePath() << std::endl;
        return false;
    }
    std::ofstream output(image.GetOutputPath(), std::ios::binary);
    if(!output.is_open()) {
        std::cout << "Could not open output file: " << image.GetOutputPath() << std::endl;
        return false;
    }
    std::string dataName = "sg_Raw" + util::string::CapitalizeCopy(util::string::RemoveCharCopy(util::fs::GetFileName(image.GetFilePath()), '.')) + "Data";
    WriteHeaderComment(output, true, image.GetFilePath(), dataName);

    dt::uint64 fileSize = input.tellg();
    image.WriteData(output, constDecl, fileSize, dataName);

    dt::int8 counter = 0;
    output << std::hex << std::uppercase;
    input.seekg(0);
    dt::int32 c = input.get();

    if(c == EOF) {
        std::cout << "Could not read from input file: " << image.GetFilePath() << std::endl;
        return false;
    }

    while(c != EOF)
    {
        // less than 16
        if(c < 0x10)
            output << "0x0" << c;
        else
            output << "0x" << c;

        c = input.get();
        if(c == EOF)
            break;
        output << ", ";

        ++counter;
        if(counter == 16) {
            output << "\n\t";
            counter = 0;
        }
    }
    output << "\n};\n";
    output << constDecl << " int " << dataName << "RelativeSize = sizeof(" << dataName << ") / sizeof(unsigned char);";
    output.close();
    return true;
}


// Handle command line arguments
void PrintHelpMessage(const char* name) {
    std::cout << "usage " << name << " [options]\n";
    std::cout << "options:\n";
    std::cout << "\t-e   | -ex          : show example\n";
    std::cout << "\t-c                  : create a c-style array from the image\n";
    std::cout << "\t-c++ | -cpp         : create a cpp-style array from the image\n";
    std::cout << "\t-h   | -help        : print this help message\n";
    std::cout << "\t-i [FILE]           : input file\n";
    std::cout << "\t-o [FILE]           : output file\n";
    std::cout << "\t-raw | -r           : write raw data to file (data has to be loaded at runtime)\n";
    std::cout << "\t-uncompressed | -uc : write uncompressed data to file (image has already been loaded into memory)\n";
    std::cout << "\tLoading the uncompressed data is faster, since it doesn't have to\n";
    std::cout << "\tbe loaded into memory at runtime but it will take up more space.\n";
}


#define CARRAY   1
#define CPPARRAY 2
#define RAW      3
#define UNCOMP   4
#define HELP     5
#define EXAMPLE  6
struct Input {
    std::string inputFile;
    std::string outputFile;
    dt::int8 arrayType = CPPARRAY;
    dt::int8 writeType = RAW;
    dt::int8 error = 0;
};

Input HandleInput(util::io::InputHandler ih) {
    Input input;
    if (ih.contains_l("-h") || ih.contains_l("-help")) {
        input.error = HELP;
        return input;
    }
    if(ih.contains_l("-e") || ih.contains_l("-ex")) {
        input.error = EXAMPLE;
        WriteExample(std::cout, WRITE_RAW_EX | WRITE_UNCOMP_EX, false);
        return input;
    }

    if(ih.contains_l("-c")) {
        input.arrayType = CARRAY;
    }
    else if(ih.contains_l("-cpp") || ih.contains_l("-c++")) {
        input.arrayType = CPPARRAY;
    }

    if(ih.contains_l("-i")) {
        int location = ih.location_l("-i");
        if(ih.size() > location + 1) {
            input.inputFile = ih[location + 1];
            if(input.inputFile == "-c" || input.inputFile == "-cpp" || input.inputFile == "-c++" || input.inputFile == "-o" || input.inputFile == "-i") {
                input.error = true;
                return input;
            }
        }
        else {
            std::cout << "error: no input file specified\n";
            input.error = true;
            return input;
        }
    }
    else {
        std::cout << "error: no input file specified\n";
        input.error = true;
        return input;
    }

    if(ih.contains_l("-o")) {
        int location = ih.location_l("-o");
        if(ih.size() > location + 1) {
            input.outputFile = ih[location + 1];
        }
        else {
            input.outputFile = input.inputFile + "_c.h";
        }
    }
    else {
            input.outputFile = input.inputFile + "_c.h";
    }

    if(ih.contains_l("-raw") || ih.contains_l("-r")) {
        input.writeType = RAW;
    }
    else if(ih.contains_l("-uncompressed") || ih.contains_l("-uc")) {
        input.writeType = UNCOMP;
    }

    return input;
}


int main(int argc, char** argv) {
    util::io::InputHandler ih(argc, argv);
    Input input = HandleInput(ih);
    if (input.error == HELP) {
        PrintHelpMessage(ih[0].c_str());
        return 1;
    }
    if(input.error == EXAMPLE) {
        return 0;
    }
    std::string constDecl = input.arrayType == CARRAY ? "static inline const" : "static inline constexpr";

    Image image(input.inputFile, input.outputFile);
    if(input.writeType == RAW) {
        if(!WriteRawImageToFile(image, constDecl))
            return 1;
    }
    else {
        if(!WriteUncompressedImageToFile(image, constDecl))
            return 1;
    }

    return 0;
}