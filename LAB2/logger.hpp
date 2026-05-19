#ifndef LOGGER
#define LOGGER

#include <ctime>
#include <fstream>
#include <iostream>

enum LogLevel { INFO, ERROR, WARNING };

void log_init(const std::string& filename = "");
void log_message(LogLevel level, const std::string& message = "");

#endif  // LOGGER