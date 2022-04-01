#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "filesystemutil.h"
#include "ioutil.h"

#ifdef UTIL_USE_CPP_17
    #include <optional>
    namespace util::fs {
        std::optional<std::vector<std::string>> ReadFileAsVectorOpt(const std::string& fileName)
        {
            std::vector<std::string> lines;
            std::ifstream file(fileName);
            if(!file)
            {
                std::cout << "File not found: " << fileName << '\n';
                return std::nullopt;
            }

            std::string line;
            while (std::getline(file, line))
            {
                lines.push_back(line);
            }
            file.close();
            return lines;
        }


        std::optional<std::string> ReadFileAsStringOpt(const std::string& fileName)
        {
            std::ifstream file(fileName);
            if(!file)
            {
                std::cout << "File not found: " << fileName << '\n';
                return std::nullopt;
            }

            std::stringstream buffer;
            buffer << file.rdbuf();
            file.close();
            return buffer.str();
        }
    }
#endif


namespace util::fs {

    std::vector<std::string> ReadFileAsVector(const std::string& fileName)
    {
        std::vector<std::string> lines;
        std::ifstream file(fileName);
        if(!file)
        {
            std::cout << "File not found: " << fileName << '\n';
            return lines;
        }

        std::string line;
        while (std::getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
        return lines;
    }


    std::string ReadFileAsString(const std::string& fileName)
    {
        std::ifstream file(fileName);
        if(!file)
        {
            std::cout << "File not found: " << fileName << '\n';
            return "";
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        file.close();
        return buffer.str();
    }


    bool WriteStringToFile(const std::string& fileName, const std::string& content)
    {
        std::ofstream file(fileName);
        if(!file)
        {
            std::cout << "File not found: " << fileName << '\n';
            return false;
        }
        file << content;
        file.close();
        return true;
    }


    std::string GetFileName(const std::string& fileName)
    {
        std::filesystem::path path(fileName);
        return path.replace_extension().filename().string();
        //std::string fileNameWithoutExtension = fileName;
        //size_t lastDot = fileNameWithoutExtension.find_last_of('.');
        //if(lastDot != std::string::npos)
        //{
        //    fileNameWithoutExtension.erase(lastDot);
        //}
        //return fileNameWithoutExtension;
    }

}