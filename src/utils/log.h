#ifndef LOG_H
#define LOG_H
#include <string>
#endif

void Log_trace(std::string message);
void Log_info(std::string message);
void Log_warn(std::string message);
void Log_error(std::string message);
void Log_critical(std::string message);

#define LOG_TRACE(message)     Log_trace(message)
#define LOG_INFO(message)      Log_info(message)
#define LOG_WARN(message)       Log_warn(message)
#define LOG_ERROR(message)     Log_error(message)
#define LOG_CRITICAL(message)   Log_critical(message)
