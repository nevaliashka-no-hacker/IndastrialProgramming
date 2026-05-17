#include "ui.h"
#include "data_processor.h"
#include "logger.h"
#include <fstream>
#include <iostream>

void run_analysis(const std::string& filepath) {
    // TODO: открыть файл, построчно читать,
    // вызывать process_line, логировать результаты

    std::string message;

    std::ifstream file(filepath);
    if (!file.is_open())
    {
        log_message(ERROR, "No open " + filepath);
        return;
    }

    log_message(INFO, "Start analys");

    std::string line;
    int num_line = 0;
    while (std::getline(file, line))
    {
        ProcessResult result = process_line(line);
        num_line++;

        std::string message_results = "Results " + std::to_string(num_line) + " string: \tWords : " +
            std::to_string(result.word_count) + "\tChars : " + std::to_string(result.char_count) +
            "\tLongest word: ";

        if (!result.longest_word.empty())
        {
            message_results += result.longest_word + "\n";
        }
        else
        {
            message_results += "None\n";
        }
        std::cout << message_results << std::endl;
    }

    log_message(INFO, "Finish analys");
}