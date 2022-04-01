#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "ioutil.h"

//#define UTIL_USE_CPP_17
#ifdef UTIL_USE_CPP_17
    #include <optional>
    namespace util::fs {
        std::optional<std::vector<std::string>> ReadFileAsVectorOpt(const std::string& fileName);
        std::optional<std::string> ReadFileAsStringOpt(const std::string& fileName);
    }
#endif


namespace util::fs {

    std::vector<std::string> ReadFileAsVector(const std::string& fileName);
    std::string ReadFileAsString(const std::string& fileName);
    bool WriteStringToFile(const std::string& fileName, const std::string& content);
    std::string GetFileName(const std::string& fileName);

    // templates
    template <typename T>
    static inline bool WriteContainerToFile(const std::string& fileName, const T& lines)
    {
        std::ofstream file(fileName);
        if(!io::WriteContainerStream(file, lines))
        {
            std::cout << "File not found: " << fileName << '\n';
            return false;
        }
        file.close();
        return true;
    }

}