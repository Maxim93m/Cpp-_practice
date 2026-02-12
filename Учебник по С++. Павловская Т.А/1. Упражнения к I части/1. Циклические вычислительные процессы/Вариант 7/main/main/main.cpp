#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
#include <iomanip>

// <---------- ПРОТОТИПЫ ФУНКЦИЙ -------------> //
float getFloatInputValue(const std::string& prompt); // Проверка корректности введёных значений
float getValue(float x, float a, float b, float c, int& indxF); // Решение системы уравнений
std::string getFormula(int indx); // Вывод формулы

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
    int Ac = static_cast <int>(a);
    int Bc = static_cast <int>(b);
    int Cc = static_cast <int>(c);
    int indxF;
    std::cout << "\n|   X   |   F   |\n";
    std::cout << "----------------\n";

    int condition = ((Ac | Bc) ^ (Ac | Cc));

    for (float X = Xn; X <= Xk; X +=dX) {
        float F = getValue(X, a, b, c, indxF);
        if (std::isnan(F)) continue;

        if (condition!=0) {
            std::cout << "| X = " << std::setw(5) << X << " | " << std::setw(5) << "F = " << F << " | " << getFormula(indxF) << "\n";
        }
        else {
            std::cout << "| X = " << std::setw(5) << X << " | " << std::setw(5) << "F = " << static_cast <int>(F) << " | " << getFormula(indxF) << "\n";
        }
    }

}
// <---------- ФУНКЦИИ -------------> //
// Вывод формулы
std::string getFormula(int indx) {
    switch (indx) {
    case 1: return  "<------ F = - a * x * x - b";
    case 2: return  "<------ F = (x - a) / x;";
    case 3: return  "<------ F = -x / c";
    default: return  "XXX";
    }
}
// Решение системы уравнений
float getValue(float x, float a, float b, float c, int& indxF) {
    if (x < 5 && c != 0) {
        indxF = 1;
        return -a * x * x - b;
    }
    else if (x > 5 && c == 0) {
        indxF = 2;
        return  (x - a) / x;
    }
    else {
        if (c == 0) {
            return NAN;
        }
        else {
            indxF = 3;
            return  -x / c;
        }
    }
}
// Проверка корректности введёных значений
float getFloatInputValue(const std::string& prompt) {
    float value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Ошибка! Введите число!";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    return value;
}