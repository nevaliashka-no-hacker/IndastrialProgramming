#include "logger.h"
#include <iostream>
#include <ctime>
#include <fstream>

bool is_open_file = false;
std::ofstream log_file;

void log_init(const std::string& filename) {
    // TODO: если filename не пуст, открыть файл для записи
    // иначе настроить вывод в консоль
    std::string message;
    if (filename[0] == '\0')
    {
        log_message(INFO, "No file for logging. Logging to console");
        is_open_file = false;
    }
    else
    {
        //std::ifstream file(filename);
        
        log_file.open(filename, std::ios::out | std::ios::app);
        if (log_file.is_open())
        {
            is_open_file = true;
            log_message(INFO, "Logging to file");
        }
        else
        {
            log_message(ERROR, "No open" + filename);
        }
    }

}

void log_message(LogLevel level, const std::string& message) {
    // TODO: сформировать строку с временной меткой и уровнем,
    // записать в файл или в консоль

    std::string level_str;
    switch (level)
    {
        case LogLevel::INFO:
            level_str = "INFO";
            break;
        case LogLevel::ERROR:
            level_str = "ERROR";
            break;
        case LogLevel::WARNING:
            level_str = "WARNING";
            break;
        default:
            level_str = "UNKNOWN";
            break;
    }

    std::time_t now = std::time(nullptr);
    std::tm* t = std::localtime(&now);
    char time_buf[20];
    std::strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", t);

    if (is_open_file)
    {
        log_file << time_buf << ": " << level_str << ': ' << message << std::endl;
    }
    else
    {
        std::cout << time_buf << " " << level_str << ' ' << message << std::endl;
    }
}