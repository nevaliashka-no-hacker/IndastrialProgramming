#pragma once

#include <string>

// Структура для хранения результата обработки строки
struct ProcessResult {
    int word_count;
    int char_count;
    std::string longest_word;
};

// Обрабатывает строку и возвращает результат
ProcessResult process_line(const std::string& line);