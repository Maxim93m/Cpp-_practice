#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <iomanip>

// <------- ПРОТОТИПЫ ФУНКЦИЙ -------------> //
float getFloatValue(const std::string& propmt); // Проверка ввода вещественных значений
int getIntValue(const std::string& prompt); // Проверка ввода целочисленных значений


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int n = 5;
    float arr[n];
    int arrInt[n];
    
    // Заполнение массива числами
    for (int i = 0; i < n; i++) {
        std::string strInput = "Введите значение " + std::to_string(i) + "-го элемента массива: ";
        arr[i] = getFloatValue(strInput);
    }

    // Ввод значений [a, b]
    int a = getIntValue("\nВведите значение a = ");
    int b = getIntValue("Введите значение b = ");
    std::cout << "Интервал значений [" << a << " , " << b << "]\n";
  
    // Номер максимального по модулю значения элемента
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(arr[i]) > fabs(arr[maxIndex])) {
            maxIndex = i;
        }
    }
    std::cout << "\nНомер максимального по модулю значения: i = " << maxIndex << "\n";

    // Сумма элементов после первого положительного элемента
    float sum = 0;
    int firstIndex = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            firstIndex = i + 1;
            flag = true;
            break;
        }
    }
    for (int i = firstIndex; i < n; i++) {
        if (flag) {
            sum += arr[i];
        }
    }
    std::cout << "\nСумма значений элементов после первого положительного значения элемента: sum = " << sum << "\n";
    // Расположить элементы чтобы целая часть лежала в интервале от [a, b]
   /* for (int i = 0; i < n; i++) {
        arr[i] = static_cast <int>(arr[i]);
    }*/
    for (int i = 0; i < n; i++) {
        arr[i] = static_cast <int>(arr[i]);
        if (arr[i] >= a && arr[i] <= b) {
            arrInt[i] = arr[i];
            std::cout << "\n i = " << arrInt[i] << "\n";
        }
        else {

        }
    }
    
}

// <------- ФУНКЦИИ -------------> //
// Проверка ввода вещественных значений
float getFloatValue(const std::string& prompt) {
    float value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Ошибка! Введите число!";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    return value;
}
// Проверка ввода целочисленных значений
int getIntValue(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Ошибка! Введите число!";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    return value;
}