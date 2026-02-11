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
    float vibration = 75.3;
    int moto_hours = 500;
    bool state_filter = true;
    bool is_running = true;  
 
    int warnings = 0;
    int alarms = 0;

    std::cout << "====================================================\n";
    std::cout << "    СИСТЕМА МОНИТОРИНГА КОМПРЕССОРНОЙ УСТАНОВКИ     \n";
    std::cout << "====================================================\n";
    std::cout << "\nВведите название оборудования: ";
    std::getline(std::cin, equipment_name);
    std::cout << "Введите значение температуры масла: ";
    std::cin >> temperature;
    std::cout << "Введите значение давления воздуха: ";
    std::cin >> pressure;
    std::cout << "Введите значение уровня вибрации: ";
    std::cin >> vibration;
    std::cout << "Введите значение моточасов: ";
    std::cin >> moto_hours;

    // Очистка буфера
    std::cin.ignore(1000, '\n');
    
    std::cout << std::left
        << std::setw(25) << "\nОборудование:" << std::setw(10) << equipment_name << "\n"
        << std::setw(25) << "Состояние установки:" << std::setw(10) << (is_running ? "РАБОТАЕТ" : "ОСТАНОВ") << "\n"
        << std::setw(25) << "Температура масла:" << std::setw(10) << temperature << " °C\n"
        << std::setw(25) << "Давление воздуха:" << std::setw(10) << pressure << " бар\n"
        << std::setw(25) << "Уровень вибраций:" << std::setw(10) << vibration << " мм/с\n"
        << std::setw(25) << "Моточасы:" << std::setw(10) << moto_hours << " ч\n"
        << std::setw(25) << "Состояние фильтра:" << std::setw(10) << (state_filter ? "ЧИСТЫЙ" : "ЗАГРЯЗНЁН") << "\n"; 
    
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
        std::cout << "\nТемпература в норме\n";
    }
    // Давление воздуха
    if (pressure <= 5 || pressure >= 9) {
        std::cout << "! АВАРИЯ: Критически высокое давление!\n";
        alarms++;
    }
    else if ((pressure > 5 && pressure < 6) || (pressure > 8 && pressure < 9)) {
        std::cout << "! ПРЕДУПРЕЖДЕНИЕ: Высокое давление!\n";
        warnings++;
    }
    else {
        std::cout << "Давление в норме\n";
    }
    // Уровень вибраций
    if (vibration >= 6) {
        std::cout << "! АВАРИЯ: Высокий уровень вибрации!\n";
        alarms++;
    }
    else if (vibration > 4 && vibration < 6) {
        std::cout << "! ПРЕДУПРЕЖДЕНИЕ: Повышенный уровень вибрации!\n";
        warnings++;
    }
    else {
        std::cout << "Уровень вибрации в норме\n";
    }
    // Моточасы
    if (moto_hours >= 800) {
        std::cout << "! АВАРИЯ: Необходимо ТО!\n";
        alarms++;
    }
    else if (moto_hours > 500 && moto_hours < 800) {
        std::cout << "! ПРЕДУПРЕЖДЕНИЕ: Необходимо ТО!\n";
        warnings++;
    }
    else {
        std::cout << "Наработка в норме\n";
    }

    std::cout << "\nКоличество предупреждений: " << std::left << std::setw(15) << warnings << "\n";
    std::cout << "Количество аварий:         " << std::left << std::setw(15) << alarms << "\n";

    if (alarms > 0) {
        std::cout << "ОСТАНОВКА! Требуется вмешательство\n";
        is_running = false;
    }
    else if (alarms == 0 && warnings > 0) {
        std::cout << "ВНИМАНИЕ! Плановое обслуживание\n";
        is_running = false;
    }
    else {
        std::cout << "НОРМАЛЬНАЯ РАБОТА\n";
    }

    std::cout << "\nПрограмма завершена.\n";
    std::cout << "Нажмите Enter для выхода...";
    std::cin.get();  

    return 0;
}