#include <string>
#include <vector>

#include "stringutil.h"

namespace util::string {

    std::vector<std::string> SplitByString(const std::string& str, const std::string& delim) {
        std::vector<std::string> result;
        std::string::size_type pos = 0;
        std::string::size_type prev = 0;
        while ((pos = str.find(delim, prev)) != std::string::npos) {
            result.push_back(str.substr(prev, pos - prev));
            prev = pos + delim.size();
        }
        result.push_back(str.substr(prev));
        return result;
    }


    std::vector<std::string> SplitByChar(const std::string& str, const char delim) {
        std::vector<std::string> result;
        std::string::size_type pos = 0;
        std::string::size_type prev = 0;
        while ((pos = str.find(delim, prev)) != std::string::npos) {
            result.push_back(str.substr(prev, pos - prev));
            prev = pos + 1;
        }
        result.push_back(str.substr(prev));
        return result;
    }


    std::string ReplaceAllCopy(std::string str, const std::string& from, const std::string& to)
    {
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
        }
        return str;
    }


    void ReplaceAll(std::string& str, const std::string& from, const std::string& to)
    {
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
        }
    }


    void Capitalize(std::string& str)
    {
        if (str.empty())
            return;
        //Lowercase(str);
        str[0] = toupper(str[0]);
    }


    std::string CapitalizeCopy(std::string str)
    {
        Capitalize(str);
        return str;
    }
}