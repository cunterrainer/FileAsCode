#pragma once
#include <random>
#include <algorithm>
#include <cfloat>
#include <string>
#include <cstdint>

namespace util::number {

    // Decimal to binary conversion
    template <typename T = std::uint32_t>
    static inline T DecimalToBinary(T decimal) {
        T binary = 0;
        T power = 1;

        while (decimal > 0) {
            T last_digit = decimal % 2;
            decimal /= 2;
            binary += last_digit * power;
            power *= 10;
        }

        return binary;
    }

    template <typename T = std::uint32_t>
    static inline std::string DecimalToBinaryString(T decimal) {
        return std::to_string(DecimalToBinary<T>(decimal));
    }

    template <typename T = std::uint32_t>
    static inline T DecimalStringToBinary(const std::string& decimal) {
        return DecimalToBinary<T>(std::stoull(decimal));
    }

    template <typename T = std::uint32_t>
    static inline std::string DecimalStringToBinaryString(const std::string& decimal) {
        return std::to_string(DecimalStringToBinary<T>(decimal));
    }


    // Hexadecimal to decimal conversion
    template <typename T = std::uint32_t>
    static inline std::string DecimalToHexadecimal(T decimal)
    {
        std::string hexadecimal = "";
        T temp = 0;

        while (decimal != 0)
        {
            temp = decimal % 16;

            if (temp < 10)
                hexadecimal += std::to_string(temp);
            else if (temp == 10)
                hexadecimal += 'A';
            else if (temp == 11)
                hexadecimal += 'B';
            else if (temp == 12)
                hexadecimal += 'C';
            else if (temp == 13)
                hexadecimal += 'D';
            else if (temp == 14)
                hexadecimal += 'E';
            else if (temp == 15)
                hexadecimal += 'F';

            decimal /= 16;
        }

        std::reverse(hexadecimal.begin(), hexadecimal.end());
        return hexadecimal;
    }


    // Binary to decimal conversion
    template <typename T = std::uint32_t>
    static inline T BinaryToDecimal(T binary) {
        T decimal = 0;
        T power = 1;

        while (binary > 0) {
            T last_digit = binary % 10;
            binary /= 10;
            decimal += last_digit * power;
            power *= 2;
        }

        return decimal;
    }

    template <typename T = std::uint32_t>
    static inline std::string BinaryToDecimalString(T binary) {
        return std::to_string(BinaryToDecimal<T>(binary));
    }

    template <typename T = std::uint32_t>
    static inline T BinaryStringToDecimal(const std::string& binary) {
        T decimal = 0;
        T power = 1;

        for (std::int64_t i = binary.length() - 1; i >= 0; i--) {
            T last_digit = binary[i] - '0';
            decimal += last_digit * power;
            power *= 2;
        }

        return decimal;
    }

    template <typename T = std::uint32_t>
    static inline std::string BinaryStringToDecimalString(const std::string& binary) {
        return std::to_string(BinaryStringToDecimal<T>(binary));
    }


    // Random number generator
    template <typename T>
    static inline T GetRandomNumber(const T min, const T max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<T> dis(min, max);
        return dis(gen);
    }

    // floating point numbers
    template <>
    inline std::float_t GetRandomNumber<std::float_t>(const std::float_t min, const std::float_t max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<std::float_t> dis(min, max);
        return dis(gen);
    }

    template <>
    inline std::double_t GetRandomNumber<std::double_t>(const std::double_t min, const std::double_t max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<std::double_t> dis(min, max);
        return dis(gen);
    }

    template <>
    inline long double GetRandomNumber<long double>(const long double min, const long double max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<long double> dis(min, max);
        return dis(gen);
    }

}