#include "data_processor.h"
#include <iostream>

ProcessResult process_line(const std::string& line) {
    // TODO: реализовать подсчёт слов, символов и поиск самого длинного слова

    int word_count = 0, char_count = 0;

    if (line[0] == '\0')
    {
        return ProcessResult{ 0, 0, "" };
    }

    int max_len_word = 0, temp_len_word = 0;
    std::string temp_word;
    std::string long_word;
    for (int i = 0; i < line.length(); i++)
    {
        char_count++;
        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\0')
        {
            if (temp_len_word > 0)
            {
                word_count++;
                if (temp_len_word > max_len_word)
                {
                    long_word = temp_word;
                    max_len_word = temp_len_word;
                }
                temp_word = "";
                temp_len_word = 0;
            }
        }
        else
        {
            temp_word += line[i];
            temp_len_word++;
        }
    }

    if (temp_len_word > 0) {
        word_count++;
        if (temp_len_word > max_len_word) {
            long_word = temp_word;
        }
    }

    // std::cout << "len word " << word_count << '\n' << "char_count " << char_count << '\n' << "longest word " << long_word << std::endl;

    return ProcessResult{ word_count, char_count, long_word };

    //return ProcessResult{0, 0, ""};
}