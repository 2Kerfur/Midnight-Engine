#ifndef LOG_H
#define LOG_H
#include <string>
#include <iostream>
#include "Config.h"
#endif

#ifdef ENGINE_DEBUG
void Log_trace(std::string message);
void Log_info(std::string message);
void Log_warn(std::string message);
void Log_error(std::string message);
void Log_critical(std::string message);

void Log_trace(int message);
void Log_info(int message);
void Log_warn(int message);
void Log_error(int message);
void Log_critical(int message);

void Log_trace(std::string message_1, int message_2);
void Log_info(std::string message_1, int message_2);
void Log_warn(std::string message_1, int message_2);
void Log_error(std::string message_1, int message_2);
void Log_critical(std::string message_1, int message_2);

void Log_trace(std::string message_1, double message_2);
void Log_info(std::string message_1, double message_2);
void Log_warn(std::string message_1, double message_2);
void Log_error(std::string message_1, double message_2);
void Log_critical(std::string message_1, double message_2);
#endif

#ifdef ENGINE_DEBUG
#define LOG_TRACE(message_1, ...)     Log_trace(message_1, __VA_ARGS__)
#define LOG_INFO(message_1, ...)      Log_info(message_1, __VA_ARGS__)
#define LOG_WARN(message_1, ...)       Log_warn(message_1, __VA_ARGS__)
#define LOG_ERROR(message_1, ...)     Log_error(message_1, __VA_ARGS__)
#define LOG_CRITICAL(message_1, ...)   Log_critical(message_1, __VA_ARGS__)
#endif

#ifdef ENGINE_RELEASE
#define LOG_TRACE(message_1, ...)
#define LOG_INFO(message_1, ...)
#define LOG_WARN(message_1, ...)
#define LOG_ERROR(message_1, ...)
#define LOG_CRITICAL(message_1, ...)
#endif
