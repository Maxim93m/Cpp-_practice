#include <iostream>
#include <windows.h>
#include <math.h>

// <---------- ПРОТОТИПЫ ФУНКЦИЙ -------------> //
float getFloatInputValue(const std::string& prompt); // Проверка корректности введёных значений
float getValue(float x, float a, float b, float c); // Решение системы уравнений

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    // Ввод параметров
    float Xn = getFloatInputValue("Введите значение Хн = ");
    float Xk = getFloatInputValue("Введите значение Хк = ");
    float dX = getFloatInputValue("Введите значение dX = ");
    float a = getFloatInputValue("Введите значение a = ");
    float b = getFloatInputValue("Введите значение b = ");
    float c = getFloatInputValue("Введите значение c = ");

    for (float X = Xn; X <= Xk; X++) {
        float F = getValue(X, a, b, c);
        if ((int(a) || int(b)) % (int(a) || int(c)) != 0) {
            std::cout << "| F = " << F << " | " << "X = " << X << " | " << "\n";
        }
        else {
            std::cout << "| F = " << int(F) << " | " << "X = " << X << " | " << "\n";
        }
    }

}
// <---------- ФУНКЦИИ -------------> //
// Решение системы уравнений
float getValue(float x, float a, float b, float c) {
    float value;
    if (x < 5 && c != 0) {
        value = -a * pow(x, 2) - b;
    }
    else if (x > 5 && c == 0) {
        value = (x - a) / c;
    }
    else {
        value = -x / c;
    }
    return value;
}
// Проверка корректности введёных значений
float getFloatInputValue(const std::string& prompt) {
    float value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Ошибка! Введите число!";
        std::cin.clear();
        std::cin.ignore();
    }
    return value;
}