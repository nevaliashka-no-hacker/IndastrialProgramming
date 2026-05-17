#pragma once

#include <string>

enum LogLevel {
    INFO,
    WARNING,
    ERROR
};

// Инициализация системы логирования
// filename – если пустая строка, вывод в консоль
void log_init(const std::string& filename = "");

// Запись сообщения с указанным уровнем
void log_message(LogLevel level, const std::string& message);