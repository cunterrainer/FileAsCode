#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <cstdint>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include "utility/datatypes.h"
#include "utility/iocautil.h"

class Image
{
private:
    int m_Width;
    int m_Height;
    int m_Channels;
    unsigned char* m_Data;
    const std::string& m_FilePath;
    const std::string& m_OutputPath;
public:
    Image(const std::string& filepath, const std::string& outputpath) noexcept : m_FilePath(filepath), m_OutputPath(outputpath) 
        { m_Data = stbi_load(filepath.c_str(), &m_Width, &m_Height, &m_Channels, 0); }
    ~Image() noexcept { stbi_image_free(m_Data); }

    int GetWidth() const noexcept { return m_Width; }
    int GetHeight() const noexcept { return m_Height; }
    int GetChannels() const noexcept { return m_Channels; }
    unsigned char* GetData() const noexcept { return m_Data; }
    const std::string& GetFilePath() const noexcept { return m_FilePath; }
    const std::string& GetOutputPath() const noexcept { return m_OutputPath; }
};


namespace util
{
    static inline std::string RemoveChars(std::string str, const std::string& chars) {
        for (const auto& c : chars) {
            str.erase(std::remove(str.begin(), str.end(), c), str.end());
        }
        return str;
    }

    static inline std::string Capitalize(std::string str)
    {
        str[0] = static_cast<char>(toupper(str[0]));
        return str;
    }
}


namespace Messenger
{
    enum class ExampleType {
        Raw = 0b0001,
        Uncomp = 0b0010
    };

    static inline void WriteImageData(std::ostream& os, const char* constDecl, const std::uint64_t dataSize, const std::string& dataName, const Image& image) noexcept {
        os << constDecl << " int sg_Width = " << image.GetWidth() << ";\n";
        os << constDecl << " int sg_Height = " << image.GetHeight() << ";\n";
        os << constDecl << " int sg_Channels = " << image.GetChannels() << ";\n";
        os << constDecl << " int sg_DataSize = sg_Width * sg_Height * sg_Channels; // " << image.GetWidth() * image.GetHeight() * image.GetChannels() << "\n\n";
    
        os << constDecl << " int " << dataName << "Size = " << dataSize << ";\n";
        os << constDecl << " unsigned char " << dataName << "[" << dataSize << "] =\n{\n\t";
    }

    static constexpr void WriteExample(std::ostream& os, ExampleType mode, bool indent) noexcept {
        char indentChar = indent ? '\t' : ' ';
        if (static_cast<std::uint8_t>(mode) & static_cast<std::uint8_t>(ExampleType::Raw)) {
            os << indentChar << "Example of writing an png file:\n";
            os << indentChar << "Example with raw data (-r) (using stb_image):\n";
            os << indentChar << "\tint width, height, channels;\n";
            os << indentChar << "\tunsigned char* data = stbi_load_from_memory(sg_RawImageData, sg_RawImageDataSize, &width, &height, &channels, 0);\n";
            os << indentChar << "\tstbi_write_png(\"test.png\", sg_Width, sg_Height, sg_Channels, data, sg_Width * sg_Channels\n";
            os << indentChar << "\tstbi_image_free(data);\n\n";
        }
        if(static_cast<std::uint8_t>(mode) & static_cast<std::uint8_t>(ExampleType::Uncomp))
        {
            os << indentChar << "Example with uncompressed (-uc) data (using stb_image):\n";
            os << indentChar << "\tstbi_write_png(\"test.png\", sg_Width, sg_Height, sg_Channels, sg_ImageData, sg_Width * sg_Channels);\n\n";
        }
    }

    static inline void WriteHeaderComment(std::ostream& os, const bool rawVersion, const std::string& filepath, const std::string& dataName) noexcept
    {
        os << "/*\n";
        if(rawVersion) {
            os << "\tThis is the raw data representation of " << filepath << "\n";
            os << "\tRaw means that the data array still has to be loaded into memory before you can use it.\n\n";
            Messenger::WriteExample(os, ExampleType::Raw, true);
        } else {
            os << "\tThis is the uncompressed data representation of " << filepath << "\n";
            os << "\tUncompressed means that the data is already \"loaded\" into memory. That means you can use it the way it is,\n";
            os << "\twithout having to load it into memory first.\n";
            os << "\tThis is useful for large images that have you don't want to load during runtime.\n\n";
            Messenger::WriteExample(os, ExampleType::Uncomp, true);
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

    static inline void PrintHelpMessage(const char* name) noexcept {
        std::cout << "usage " << name << " [options]\n";
        std::cout << "options:\n";
        std::cout << "\t-i [FILE]           : input file\n";
        std::cout << "\t-o [FILE]           : output file\n";
        std::cout << "\t-c                  : create a c-style array from the image\n";
        std::cout << "\t-c++ | -cpp         : create a cpp-style array from the image\n";
        std::cout << "\t-e   | -ex          : show example\n";
        std::cout << "\t-h   | -help        : print this help message\n";
        std::cout << "\t-il  | -l | -inline : inline the variables (only for C++17 and above)\n";
        std::cout << "\t-raw | -r           : write raw data to file (data has to be loaded at runtime)\n";
        std::cout << "\t-uncompressed | -uc : write uncompressed data to file (image has already been loaded into memory)\n";
        std::cout << "\tLoading the uncompressed data is faster, since it doesn't have to\n";
        std::cout << "\tbe loaded into memory at runtime but it will take up more space.\n";
    }
}


namespace Check {
    static inline bool IfstreamIsOpen(const std::ifstream& os, const char* file_name) noexcept
    {
        if(!os.is_open()) {
            std::cout << "Could not open file " << file_name << " \n";
            return false;
        }
        return true;
    }

    static inline bool OfstreamIsOpen(const std::ofstream& os, const char* file_name) noexcept
    {
        if(!os.is_open()) {
            std::cout << "Could not open file " << file_name << " \n";
            return false;
        }
        return true;
    }
}


namespace Write {
    static constexpr inline const char* const sg_CharsToRemove = ".,/\\| +#<>%&!?§$;:-~'";
    static constexpr inline const char* const sg_DataNameSuffix = "Data";

    static std::pair<std::string, std::uint64_t> WriteHeaderAndData(std::ofstream& os, const Image& image, const std::string& prefix, const bool rawVersion, const char* constDecl) noexcept
    {
        const std::string dataName = prefix + util::Capitalize(util::RemoveChars(std::filesystem::path(image.GetFilePath()).replace_extension().filename().string(), sg_CharsToRemove)) + sg_DataNameSuffix;
        Messenger::WriteHeaderComment(os, rawVersion, image.GetFilePath(), dataName);

        const std::uint64_t dataSize = static_cast<std::uint64_t>(image.GetWidth() * image.GetHeight() * image.GetChannels());
        Messenger::WriteImageData(os, constDecl, dataSize, dataName, image);
        return std::make_pair(dataName, dataSize);
    }

    static inline void WriteRelativeSizeAndClose(std::ofstream& outfile, const char* constDecl, const std::pair<std::string, std::uint64_t>& data) noexcept
    {
        outfile << "\n};\n";
        outfile << std::dec << constDecl << " int " << data.first << "RelativeSize = sizeof(" << data.first << ") / sizeof(unsigned char); // " << data.second;
        outfile.close();
    }

    static inline void WriteNumber(std::ofstream& outfile, const int c) noexcept
    {
        // less than 16
        if(c < 0x10)
            outfile << "0x0" << c;
        else
            outfile << "0x" << c;
    }

    static inline bool UncompressedImageToFile(const Image& image, const char* constDecl) noexcept
    {
        std::ofstream outfile(image.GetOutputPath(), std::ios::binary);
        if(!Check::OfstreamIsOpen(outfile, image.GetOutputPath().c_str())) {
            return false;
        }
        std::pair<std::string, std::uint64_t> data = WriteHeaderAndData(outfile, image, "sg_", false, constDecl);

        outfile << std::hex << std::uppercase;
        for (std::uint64_t i = 0; i < data.second; ++i) 
        {
            WriteNumber(outfile, image.GetData()[i]);

            if(i != data.second - 1)
            {
                outfile << ", ";
                if(i % 16 == 15) {
                    outfile << "\n\t";
                }
            }
        }
        WriteRelativeSizeAndClose(outfile, constDecl, data);
        return true;
    }

    static inline bool RawImageToFile(const Image& image, const char* constDecl) noexcept {
        std::ifstream input(image.GetFilePath(), std::ios::binary);
        if(!Check::IfstreamIsOpen(input, image.GetFilePath().c_str()))
            return false;

        std::ofstream outfile(image.GetOutputPath(), std::ios::binary);
        if(!Check::OfstreamIsOpen(outfile, image.GetOutputPath().c_str()))
            return false;

        std::pair<std::string, std::uint64_t> data = WriteHeaderAndData(outfile, image, "sg_Raw", true, constDecl);

        // counts up to 16 inorder to have a formated output
        dt::int8 counter = 0;
        outfile << std::hex << std::uppercase;

        dt::int32 c = input.get();
        if(c == EOF) {
            std::cout << "Could not read from input file: " << image.GetFilePath() << std::endl;
            return false;
        }

        while(c != EOF)
        {
            WriteNumber(outfile, c);

            c = input.get();
            if(c == EOF)
                break;
            outfile << ", ";

            ++counter;
            if(counter == 16) {
                outfile << "\n\t";
                counter = 0;
            }
        }
        WriteRelativeSizeAndClose(outfile, constDecl, data);
        return true;
    }
}

// Handle command line arguments
namespace CLA {
    enum class ArrayType : dt::uint8 {
        CArray = 1,
        CPPArray = 2
    };

    enum class CompressType : dt::uint8 {
        Raw = 1,
        Uncomp = 2
    };

    enum class ErrorType : dt::uint8 {
        None = 0,
        Help = 1,
        Example = 2,
    };

    struct Input {
        std::string inputFile;
        std::string outputFile;
        ArrayType arrayType = ArrayType::CPPArray;
        CompressType writeType = CompressType::Raw;
        ErrorType error = ErrorType::None;
        bool inlineVars = false;
    };

    static inline const Input& HandleInput(const util::io::InputHandler& ih) noexcept {
        static Input input;
        if(ih.IsEmpty() || ih.FindL("-h") || ih.FindL("-help")) {
            input.error = ErrorType::Help;
            return input;
        }

        if(ih.FindL("-e") || ih.FindL("-ex")) {
            input.error = ErrorType::Example;
            Messenger::WriteExample(std::cout, static_cast<Messenger::ExampleType>(static_cast<dt::uint8>(Messenger::ExampleType::Raw) | static_cast<dt::uint8>(Messenger::ExampleType::Uncomp)), false);
            return input;
        }

        if(ih.FindL("-c")) {
            input.arrayType = ArrayType::CArray;
        }
        else if(ih.FindL("-cpp") || ih.FindL("-c++")) {
            input.arrayType = ArrayType::CPPArray;
        }
        

        static const std::vector<std::string> s_ReservedSymbols = {
            "-c", "-cpp", "-c++", "-i", "-o", "-r", "-uc", "-uncompressed", 
            "-il", "-inline", "-l", "-help", "-e", "-ex", "-raw", "-h"  };

        unsigned int location;
        if((location = ih.GetL("-i"))) {
            input.inputFile = ih.GetL(location + 1);
        }
        if(location == 0 || input.inputFile == "" || ih.IsInContainerL(s_ReservedSymbols, input.inputFile)) {
            std::cout << "error: no input file specified\n";
            input.error = ErrorType::Help;
            return input;
        }

        if((location = ih.GetL("-o"))) {
            input.outputFile = ih.GetL(location + 1);
        }
        if(location == 0 || input.outputFile == "" || ih.IsInContainerL(s_ReservedSymbols, input.outputFile)) {
            input.outputFile = input.inputFile + "_c.h";
        }


        if(ih.FindL("-raw") || ih.FindL("-r")) {
            input.writeType = CompressType::Raw;
        }
        else if(ih.FindL("-uncompressed") || ih.FindL("-uc")) {
            input.writeType = CompressType::Uncomp;
        }

        if(ih.FindL("-il") || ih.FindL("-inline") || ih.FindL("-l")) {
            input.inlineVars = true;
        }

        return input;
    }
}


static inline const char* GetConstDeclaration(const CLA::Input& input) noexcept
{
    if (input.arrayType == CLA::ArrayType::CArray)
        return "static const";
    if (input.inlineVars)
        return "static inline constexpr";
    return "static constexpr";
}


int main(int argc, const char** argv) {
    util::io::InputHandler ih(argc, argv);
    const CLA::Input& input = CLA::HandleInput(ih);
    if (input.error == CLA::ErrorType::Help) {
        Messenger::PrintHelpMessage(ih[0].c_str());
        return 1;
    }
    if(input.error == CLA::ErrorType::Example) {
        return 0;
    }
    const char* constDecl = GetConstDeclaration(input);

    const Image image(input.inputFile, input.outputFile);
    return input.writeType == CLA::CompressType::Raw ? !Write::RawImageToFile(image, constDecl) : !Write::UncompressedImageToFile(image, constDecl);
}