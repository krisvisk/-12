#include "functions.h"
#include <exception>
#include <iostream>

using namespace DigitCleaner;

int main() {
  try { // Обробка виключень
    int digitFreq[10] = {0}; // Масив для зберігання частоти кожної цифри
    std::string input = readInput(); // Зчитування рядка з вводу користувача
    std::string cleanedStr; // Рядок без цифр
    int digitCount = 0;     // Кількість вилучених цифр

    removeDigits(input, cleanedStr, digitCount,
                 digitFreq); // Видалення цифр з рядка та підрахунок їх частоти
    char maxDigit = mostFrequentDigit(digitFreq); // Цифра з найбільшою частотою
    printResult(cleanedStr, digitCount, maxDigit); // Виведення результатів
  } catch (const std::exception &ex) { // Виведення повідомлення про помилку
    std::cerr << "Помилка: " << ex.what() << std::endl;
    return 1;
  }

  return 0;
}
