#include "ui.h"
#include "logger.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

    if (argc > 1) {
        // первый аргумент - файл для логов
        log_init(argv[1]);  
    } else {
        // без аргументов - консоль
        log_init();         
    }
    
    std::string path;
    //std::cout << "Введите путь к текстовому файлу: ";
    std::cout << "Enter the path to the test file: ";
    std::getline(std::cin, path);

    if (path.empty()) {
        //log_message(ERROR, "Путь не указан");
        log_message(ERROR, "Path not specified");
        return 1;
    }

    run_analysis(path);
    return 0;
}