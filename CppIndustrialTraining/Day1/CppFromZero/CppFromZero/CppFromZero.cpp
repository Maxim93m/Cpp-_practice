#include <iostream>
#include <string>
#include <iomanip> 
#include <windows.h> 

int main() {
    SetConsoleCP(1251);         
    SetConsoleOutputCP(1251);

    std::string equipment_name = "Насос_Главный";  
    float temperature = 25.5f;                     
    int pressure = 100;                            
    bool is_running = true;  
    int humidity = 75;
    float voltage = 380.0f;
    int operating_hours = 500;
    int warnings = 0;
    int alarms = 0;

    std::cout << "====================================================\n";
    std::cout << "              СИСТЕМА МОНИТОРИНГА\n";
    std::cout << "====================================================\n";
    std::cout << "Введите название оборудования: ";
    std::getline(std::cin, equipment_name);
    std::cout << "Введите значение температуры: ";
    std::cin >> temperature;
    std::cout << "Введите значение давления: ";
    std::cin >> pressure;
    std::cout << "Введите значение влажности: ";
    std::cin >> humidity;
    std::cout << "Введите значение напряжения: ";
    std::cin >> voltage;
    std::cout << "Введите значение наработки: ";
    std::cin >> operating_hours;
    std::cout << "\nОборудование:    " << std::left << std::setw(15) << equipment_name << "\n";
    std::cout << "Температура      " << std::left << std::setw(15) << temperature << " °C\n";
    std::cout << "Давление:        " << std::left << std::setw(15) << pressure << " бар\n";
    std::cout << "Состояние:       " << std::left << std::setw(15) << (is_running ? "РАБОТАЕТ" : "ОСТАНОВ") << "\n";
    std::cout << "Влажность:       " << std::left << std::setw(15) << humidity << " %\n";
    std::cout << "Напряжение:      " << std::left << std::setw(15) << voltage << " В\n";
    std::cout << "Наработка:       " << std::left << std::setw(15) << operating_hours << " ч\n";
    // Температура
    if (temperature > 40.0f) {
        std::cout << "\n! АВАРИЯ: Критический перегрев оборудования!\n";
        alarms++;
    }
    else if (temperature > 30.0f) {
        std::cout<< "\n! ПРЕДУПРЕЖДЕНИЕ: Перегрев оборудования!\n";
        warnings++;
    }
    else {
        std::cout << "\nТемпература в норме\n";
    }
    // Давление
    if (pressure > 220) {
        std::cout << "! АВАРИЯ: Критически высокое давление!\n";
        alarms++;
    }
    else if (pressure > 120) {
        std::cout << "! ПРЕДУПРЕЖДЕНИЕ: Высокое давление!\n";
        warnings++;
    }
    else {
        std::cout << "Давление в норме\n";
    }
    // Влажность
    if (humidity > 85) {
        std::cout << "! АВАРИЯ: Высокая вероятность образования конденсата!\n";
        alarms++;
    }
    else if (humidity > 75) {
        std::cout << "! ПРЕДУПРЕЖДЕНИЕ: Риск образования конденсата!\n";
        warnings++;
    }
    else {
        std::cout << "Влажность в норме\n";
    }
    // Напряжение
    if (voltage < 220 || voltage > 100) {
        std::cout << "! АВАРИЯ: Низкое напряжение в сети!\n";
        alarms++;
    }
    else if (voltage < 350 || voltage > 410) {
        std::cout << "! ПРЕДУПРЕЖДЕНИЕ: Авария по напряжению!\n";
        warnings++;
    }
    else {
        std::cout << "Напряжение в норме\n";
    }
    // Наработка
    if (operating_hours > 1000) {
        std::cout << "! АВАРИЯ: Необходимо ТО!\n";
        alarms++;
    }
    else if (operating_hours > 500) {
        std::cout << "! ПРЕДУПРЕЖДЕНИЕ: Необходимо ТО!\n";
        warnings++;
    }
    else {
        std::cout << "Наработка в норме\n";
    }

    std::cout << "\nКоличество предупреждений: " << std::left << std::setw(15) << warnings << "\n";
    std::cout << "Количество аварий:         " << std::left << std::setw(15) << alarms << "\n";

    std::cout << "\nПрограмма завершена.\n";
    std::cout << "Нажмите Enter для выхода...";
    std::cin.get();  

    return 0;
}