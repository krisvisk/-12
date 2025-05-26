#pragma once  
// включаем заголовочный файл только один раз
#include <string>

namespace DigitCleaner {
    std::string readInput(); 
    std::pair<std::string, int> removeDigits(const std::string& input, int freq[10]);
    char mostFrequentDigit(const int freq[10]);
    void printResult(const std::string& cleanedStr, int digitCount, char maxDigit);
}
