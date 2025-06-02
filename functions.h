#pragma once
#include <string>

namespace DigitCleaner {
    std::string readInput();
    void removeDigits(const std::string& input, std::string& cleanedStr, int& count, int freq[10]);
    char mostFrequentDigit(const int freq[10]);
    void printResult(const std::string& cleanedStr, int digitCount, char maxDigit);
}
