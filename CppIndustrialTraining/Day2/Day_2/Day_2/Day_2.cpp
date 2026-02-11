#define NOMINMAX
#include <iostream>
#include <string>
#include <iomanip> 
#include <windows.h> 
#include <limits>

// Прототипы функций
float getFloatInput(const std::string& prompt); // Прототип функции для проверки ввода вещественных значений параметров
int getIntInput(const std::string& prompt); // Прототип функции для проверки ввода целочисленных значений параметров
int getFilterInput(const std::string& prompt); // Прототип функции для проверки ввода значения фильтра
void checkValueTemperature(float temperature, int& warnings, int& alarms); // Прототип функции для проверки значения температуры
void checkValuePressure(int pressure, int& warnings, int& alarms); // Прототип функции для проверки значения давления
void checkValueVibration(float vibration, int& warnings, int& alarms); // Прототип функции для проверки значения уровня вибрации
void checkValueMotoHours(int hours, int& warnings, int& alarms); // Прототип функции для проверки значения моточасов
void checkStateFilter(bool state, int& alarms); // Функция для проверки состояния фильтра
void printTable(int warnings, int alarms, const std::string& name,
                bool isRunning, float temp, int press, float vibr, int hours, bool stateFilter); // Функция для отображения таблицы

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string equipment_name = "Насос_Главный";
    bool is_running;

    int warnings = 0;
    int alarms = 0;

    std::cout << "====================================================\n";
    std::cout << "    СИСТЕМА МОНИТОРИНГА КОМПРЕССОРНОЙ УСТАНОВКИ     \n";
    std::cout << "====================================================\n";
    std::cout << "\nВведите название оборудования: ";
    std::getline(std::cin, equipment_name);
    // Ввод значений
    float temperature = getFloatInput("Введите значение температуры масла: ");
    int pressure = getIntInput("Введите значение давления воздуха: ");
    float vibration = getFloatInput("Введите значение уровня вибрации: ");
    int moto_hours = getIntInput("Введите значение моточасов: ");
    int filter_input = getFilterInput("Введите значение состояния фильтра: "); 
    bool state_filter = (filter_input == 1);
    // Очистка буфера
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Проверка значений параметров
    checkValueTemperature(temperature, warnings, alarms); // Tемпературa масла
    checkValuePressure(pressure, warnings, alarms); // Давление воздуха
    checkValueVibration(vibration, warnings, alarms); // Уровень вибраций
    checkValueMotoHours(moto_hours, warnings, alarms); // Моточасы
    checkStateFilter(moto_hours, alarms); // Состояние фильтра 
    
    is_running = (alarms == 0);

    if (alarms > 0) {
        std::cout << "\nОСТАНОВКА! Требуется вмешательство\n";
    }
    else if (alarms == 0 && warnings > 0) {
        std::cout << "\nВНИМАНИЕ! Плановое обслуживание\n";
    }
    else {
        std::cout << "\nНОРМАЛЬНАЯ РАБОТА\n";
    }
    
    // Отображение значений параметров
    printTable(warnings, alarms, equipment_name, is_running, temperature, pressure, vibration, moto_hours, state_filter);

    std::cout << "\nПрограмма завершена.\n";
    std::cout << "Нажмите Enter для выхода...";
    std::cin.get();
    return 0;
}

// Функция для проверки ввода вещественных значений параметров
float getFloatInput(const std::string& prompt) {
    float value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Ошибка! Введите число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

// Функция для проверки ввода целочисленных значений параметров
int getIntInput(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Ошибка! Введите число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

// Функция для проверки ввода значения фильтра
int getFilterInput(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value) || (value != 0 && value != 1)) {
        std::cout << "Ошибка! Введите число 0 - Загрязнён или 1 - Чистый): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

// Функция для проверки значения температуры
void checkValueTemperature(float temperature, int& warnings, int& alarms) {
    if (temperature <= 35 || temperature >= 70) {
        std::cout << "\n! АВАРИЯ: Критическое значения температуры!\n";
        alarms++;
    }
    else if ((temperature > 60 && temperature < 70) || (temperature > 35 && temperature < 40)) {
        std::cout << "\n! ПРЕДУПРЕЖДЕНИЕ: Недопустимое значение температуры!\n";
        warnings++;
    }
    else {
        std::cout << "\nТемпература в норме\n"; // 40-60 °C
    }
}

// Функция для проверки значения давления
void checkValuePressure(int pressure, int& warnings, int& alarms) {
    if (pressure < 5 || pressure > 9) {
        std::cout << "! АВАРИЯ: Критическое давление!\n";
        alarms++;
    }
    else if (pressure < 6 || pressure > 8) {
        std::cout << "! ПРЕДУПРЕЖДЕНИЕ: Давление вне нормы!\n";
        warnings++;
    }
    else {
        std::cout << "Давление в норме\n";
    }
}

// Функция для проверки значения уровня вибрации
void checkValueVibration(float vibration, int& warnings, int& alarms) {  
    if (vibration > 6) {
        std::cout << "! АВАРИЯ: Высокий уровень вибрации!\n";
        alarms++;
    }
    else if (vibration > 4 && vibration <= 6) {
        std::cout << "! ПРЕДУПРЕЖДЕНИЕ: Повышенный уровень вибрации!\n";
        warnings++;
    }
    else {
        std::cout << "Уровень вибрации в норме\n";
    }
}

// Функция для проверки значения моточасов
void checkValueMotoHours(int hours, int& warnings, int& alarms) {
    if (hours > 800) {
        std::cout << "! АВАРИЯ: Необходимо ТО!\n";
        alarms++;
    }
    else if (hours >= 500) {
        std::cout << "! ПРЕДУПРЕЖДЕНИЕ: Необходимо ТО!\n";
        warnings++;
    }
    else {
        std::cout << "Наработка в норме\n";
    }
}

// Функция для проверки состояния фильтра
void checkStateFilter(bool state, int& alarms) {
    if (state) {
        std::cout << "! АВАРИЯ: Фильтр загрязнён!\n";
        alarms++;
    }
}

// Функция для отображения таблицы
void printTable(int warnings, int alarms, const std::string& name,
                bool isRunning, float temp, int press, float vibr, int hours, bool stateFilter) {
    std::cout << "\nКоличество предупреждений: " << std::left << std::setw(15) << warnings << "\n";
    std::cout << "Количество аварий:         " << std::left << std::setw(15) << alarms << "\n";
    std::cout << std::left
        << std::setw(30) << "\nОборудование:" << std::setw(20) << name << "\n"
        << std::setw(30) << "Состояние установки:" << std::setw(20) << (isRunning ? "РАБОТАЕТ" : "ОСТАНОВ") << "\n"
        << std::setw(30) << "Температура масла:" << std::setw(20) << temp << " °C\n"
        << std::setw(30) << "Давление воздуха:" << std::setw(20) << press << " бар\n"
        << std::setw(30) << "Уровень вибраций:" << std::setw(20) << vibr << " мм/с\n"
        << std::setw(30) << "Моточасы:" << std::setw(20) << hours << " ч\n"
        << std::setw(30) << "Состояние фильтра:" << std::setw(20) << (stateFilter ? "ЧИСТЫЙ" : "ЗАГРЯЗНЁН") << "\n";
}