#define NOMINMAX
#include <iostream>
#include <string>
#include <iomanip> 
#include <windows.h> 
#include <limits>

int main() {
    SetConsoleCP(1251);         
    SetConsoleOutputCP(1251);

    std::string equipment_name = "Насос_Главный";  
    float temperature = 25.5f;                     
    int pressure = 100;       
    float vibration = 75.3;
    int moto_hours = 500;
    int filter_input;
    bool state_filter;
    bool is_running;  
 
    int warnings = 0;
    int alarms = 0;

    std::cout << "====================================================\n";
    std::cout << "    СИСТЕМА МОНИТОРИНГА КОМПРЕССОРНОЙ УСТАНОВКИ     \n";
    std::cout << "====================================================\n";
    std::cout << "\nВведите название оборудования: ";
    std::getline(std::cin, equipment_name);
    // Ввод значений
    std::cout << "Введите значение температуры масла: ";
    while (!(std::cin >> temperature)) {
        std::cout << "Ошибка! Введите число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Введите значение давления воздуха: ";
    while (!(std::cin >> pressure)) {
        std::cout << "Ошибка! Введите число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Введите значение уровня вибрации: ";
    while (!(std::cin >> vibration)) {
        std::cout << "Ошибка! Введите число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Введите значение моточасов: ";
    while (!(std::cin >> moto_hours)) {
        std::cout << "Ошибка! Введите число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Введите значение состояния фильтра: ";
    while (!(std::cin >> filter_input) || (filter_input != 0 && filter_input != 1)) {
        std::cout << "Ошибка! Введите число 0 - Загрязнён или 1 - Чистый): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    state_filter = (filter_input == 1);
    // Очистка буфера
    std::cin.ignore(1000, '\n');

    // Температура масла
    if (temperature <= 35 || temperature >= 70) {
        std::cout << "\n! АВАРИЯ: Критическое значения температуры!\n";
        alarms++;
    }
    else if ((temperature > 60 && temperature < 70) || (temperature > 35  && temperature < 40)) {
        std::cout<< "\n! ПРЕДУПРЕЖДЕНИЕ: Недопустимое значение температуры!\n";
        warnings++;
    }
    else {
        std::cout << "\nТемпература в норме\n"; // 40-60 °C
    }
    // Давление воздуха
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
    // Уровень вибраций
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
    // Моточасы
    if (moto_hours > 800) {
        std::cout << "! АВАРИЯ: Необходимо ТО!\n";
        alarms++;
    }
    else if (moto_hours >= 500) {
        std::cout << "! ПРЕДУПРЕЖДЕНИЕ: Необходимо ТО!\n";
        warnings++;
    }
    else {
        std::cout << "Наработка в норме\n";
    }
    // Состояние фильтра 
    if (state_filter != 1) {
        std::cout << "! АВАРИЯ: Фильтр загрязнён!\n";
        alarms++;
    }
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
    std::cout << "\nКоличество предупреждений: " << std::left << std::setw(15) << warnings << "\n";
    std::cout << "Количество аварий:         " << std::left << std::setw(15) << alarms << "\n";
    std::cout << std::left
        << std::setw(30) << "\nОборудование:" << std::setw(20) << equipment_name << "\n"
        << std::setw(30) << "Состояние установки:" << std::setw(20) << (is_running ? "РАБОТАЕТ" : "ОСТАНОВ") << "\n"
        << std::setw(30) << "Температура масла:" << std::setw(20) << temperature << " °C\n"
        << std::setw(30) << "Давление воздуха:" << std::setw(20) << pressure << " бар\n"
        << std::setw(30) << "Уровень вибраций:" << std::setw(20) << vibration << " мм/с\n"
        << std::setw(30) << "Моточасы:" << std::setw(20) << moto_hours << " ч\n"
        << std::setw(30) << "Состояние фильтра:" << std::setw(20) << (state_filter ? "ЧИСТЫЙ" : "ЗАГРЯЗНЁН") << "\n";

    std::cout << "\nПрограмма завершена.\n";
    std::cout << "Нажмите Enter для выхода...";
    std::cin.get();  
    return 0;
}