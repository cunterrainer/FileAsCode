#pragma once
#include <string>
#include <algorithm>
#include <vector>

namespace util::string {

    std::vector<std::string> SplitByChar(const std::string& str, const char delim);
    std::vector<std::string> SplitByString(const std::string& str, const std::string& delim);
    static inline std::vector<std::string> Split(const std::string& str, const char delim) { return SplitByChar(str, delim); }
    static inline std::vector<std::string> Split(const std::string& str, const std::string& delim) { return SplitByString(str, delim); }

    std::string ReplaceAllCopy(std::string str, const std::string& from, const std::string& to);
    void ReplaceAll(std::string& str, const std::string& from, const std::string& to);

    void Capitalize(std::string& str);
    std::string CapitalizeCopy(std::string str);


    static inline void RemoveChar(std::string& str, const char c) {
        str.erase(std::remove(str.begin(), str.end(), c), str.end());
    }
    static inline std::string RemoveCharCopy(std::string str, const char c) {
        RemoveChar(str, c);
        return str;
    }


    // lower / uppercase strings
    static inline void Lowercase(std::string& str) {
        std::for_each(str.begin(), str.end(), [](char& c) {c = std::tolower(c);});
    }

    static inline void Uppercase(std::string& str) {
        std::for_each(str.begin(), str.end(), [](char& c) {c = std::toupper(c);});
    }

    static inline std::string LowercaseCopy(std::string str) {
        Lowercase(str);
        return str;
    }

    static inline std::string UppercaseCopy(std::string str) {
        Uppercase(str);
        return str;
    }


    // trim strings
    // trim from start (in place)
    static inline void ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
    }

    // trim from end (in place)
    static inline void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    // trim from both ends (in place)
    static inline void trim(std::string &s) {
        ltrim(s);
        rtrim(s);
    }

    // trim from start (copying)
    static inline std::string ltrimCopy(std::string s) {
        ltrim(s);
        return s;
    }

    // trim from end (copying)
    static inline std::string rtrimCopy(std::string s) {
        rtrim(s);
        return s;
    }

    // trim from both ends (copying)
    static inline std::string trimCopy(std::string s) {
        trim(s);
        return s;
    }

}