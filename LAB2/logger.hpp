#ifndef LOGGER
#define LOGGER 

#include <iostream>
#include <ctime>
#include <fstream>

enum LogLevel 
{
    INFO, 
    ERROR
}

void log_init(const std::string& filename = "");
void log_message(LogLevel level, const std::string& message = "");

#endif // LOGGER