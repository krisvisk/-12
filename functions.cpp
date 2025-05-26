#include "functions.h"
#include <iostream>
#include <cctype>
#include <stdexcept>  // для std::runtime_error (якщо потрібно)     

namespace DigitCleaner {

    std::string readInput() {// Функція для зчитування рядка з вводу
        std::string input;
        std::cout << "Введіть рядок: ";
        if (!std::getline(std::cin, input)) {
            throw std::runtime_error("Не вдалося зчитати рядок.");
        }
        return input;
    }

    std::pair<std::string, int> removeDigits(const std::string& input, int freq[10]) {
        std::string result;
        int count = 0;

        for (char ch : input) {
            if (std::isdigit(static_cast<unsigned char>(ch))) {
                freq[ch - '0']++;
                count++;
            } else {
                result += ch;
            }
        }

        return { result, count };
    }

    char mostFrequentDigit(const int freq[10]) { // Функція для знаходження цифри з найбільшою частотою
        int maxCount = 0;
        int maxDigit = 0;

        for (int i = 0; i < 10; ++i) {
            if (freq[i] > maxCount) {
                maxCount = freq[i];
                maxDigit = i;
            }
        }

        return static_cast<char>('0' + maxDigit);
    }

    void printResult(const std::string& cleanedStr, int digitCount, char maxDigit) { // Функція для виведення результату
        std::cout << "Рядок без цифр: " << cleanedStr << "\n";
        std::cout << "Кількість вилучених цифр: " << digitCount << "\n";
        std::cout << "Цифра з найбільшою частотою: " << maxDigit << "\n";
    }
}
