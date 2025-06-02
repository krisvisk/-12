#include "functions.h"
#include <iostream>
#include <cctype>
#include <stdexcept>

namespace DigitCleaner 


    std::string readInput() {// Функція для зчитування рядка з вводу користувача
        std::string input;
        std::cout << "Введіть рядок: ";
        if (!std::getline(std::cin, input)) {
            throw std::runtime_error("Не вдалося зчитати рядок.");
        }
        return input;
    }

    void removeDigits(const std::string& input, std::string& cleanedStr, int& count, int freq[10]) {// Функція для видалення цифр з рядка та підрахунку їх частоти
        cleanedStr.clear();
        count = 0;

        for (char ch : input) {
            if (std::isdigit(static_cast<unsigned char>(ch))) {
                freq[ch - '0']++;
                count++;
            } else {
                cleanedStr += ch;
            }
        }
    }

    char mostFrequentDigit(const int freq[10]) {// Функція для знаходження цифри з найбільшою частотою
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

    void printResult(const std::string& cleanedStr, int digitCount, char maxDigit) {// Функція для виведення результатів
        std::cout << "Рядок без цифр: " << cleanedStr << "\n";
        std::cout << "Кількість вилучених цифр: " << digitCount << "\n";
        std::cout << "Цифра з найбільшою частотою: " << maxDigit << "\n";
    }
}
