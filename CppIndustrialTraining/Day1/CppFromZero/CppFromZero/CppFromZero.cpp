#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");

    std::string equipment_name = "Насос_Главный";  
    float temperature = 25.5f;                     
    int pressure = 100;                            
    bool is_running = true;  
    int humidity = 75;
    float voltage = 380.0f;
    int operating_hours = 500;


    std::cout << "====================================\n";
    std::cout << "МОНИТОРИНГ: " << equipment_name << "\n";
    std::cout << "====================================\n";
    std::cout << "Температура: " << temperature << " °C\n";
    std::cout << "Давление:    " << pressure << " бар\n";
    std::cout << "Состояние:   " << (is_running ? "РАБОТАЕТ" : "ОСТАНОВ") << "\n";
    std::cout << "Влажность: " << humidity << " %\n";
    std::cout << "Напряжение: " << voltage << " В\n";
    std::cout << "Наработка: " << operating_hours << " ч\n";

    if (temperature > 30.0f) {
        std::cout << "\n! ВНИМАНИЕ: Перегрев оборудования!\n";
    }

    if (pressure > 120) {
        std::cout << "! ВНИМАНИЕ: Высокое давление!\n";
    }

    if (humidity > 85) {
        std::cout << "! ВНИМАНИЕ: Конденсат!\n";
    }
    
    if (voltage < 350 || voltage > 410) {
        std::cout << "! АВАРИЯ: Авария по напряжению!\n";
    }

    if (operating_hours > 1000) {
        std::cout << "! ВНИМАНИЕ: Необходимо ТО!\n";
    }

    std::cout << "\nПрограмма завершена.\n";
    std::cout << "Нажмите Enter для выхода...";
    std::cin.get();  

    return 0;
}