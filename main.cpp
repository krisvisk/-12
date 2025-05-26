#include "functions.h"
#include <iostream>
#include <exception>

int main() {
    try {
        int digitFreq[10] = {0};
        std::string input = DigitCleaner::readInput();
        auto [cleanedStr, digitCount] = DigitCleaner::removeDigits(input, digitFreq);
        char maxDigit = DigitCleaner::mostFrequentDigit(digitFreq);
        DigitCleaner::printResult(cleanedStr, digitCount, maxDigit);
    }
    catch (const std::exception& ex) {
        std::cerr << "Помилка: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
