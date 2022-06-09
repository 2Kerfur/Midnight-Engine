#include "log.h"
#include <string>
#include "spdlog/spdlog.h"

int LoggerInit()
{

    return 0;
}
std::string message;
//string
void Log_trace(std::string message) { spdlog::trace(message); }
void Log_info(std::string message) { spdlog::info(message); }
void Log_warn(std::string message) { spdlog::warn(message); }
void Log_error(std::string message) { spdlog::error(message); }
void Log_critical(std::string message) { spdlog::critical(message); }

//int
void Log_trace(int message) { spdlog::trace(message); }
void Log_info(int message) { spdlog::info(message); }
void Log_warn(int message) { spdlog::warn(message); }
void Log_error(int message) { spdlog::error(message); }
void Log_critical(int message) { spdlog::critical(message); }

//string + int
void Log_trace(std::string message_1, int message_2) {
    message = message_1 + (std::to_string(message_2)); //convert to 1 string
    spdlog::trace(message); }
void Log_info(std::string message_1, int message_2) { //convert to 1 string
    message = message_1 + (std::to_string(message_2));
    spdlog::info(message); }
void Log_warn(std::string message_1, int message_2) { //convert to 1 string
    message = message_1 + (std::to_string(message_2));
    spdlog::warn(message); }
void Log_error(std::string message_1, int message_2) { //convert to 1 string
    message = message_1 + (std::to_string(message_2));
    spdlog::error(message); }
void Log_critical(std::string message_1, int message_2) { 
    message = message_1 + (std::to_string(message_2));
    spdlog::critical(message); }

//string + float
void Log_trace(std::string message_1, double message_2) {
    message = message_1 + (std::to_string(message_2)); //convert to 1 string
    spdlog::trace(message); }
void Log_info(std::string message_1, double message_2) {
    message = message_1 + (std::to_string(message_2)); //convert to 1 string
    spdlog::info(message); }
void Log_warn(std::string message_1, double message_2) {
    message = message_1 + (std::to_string(message_2)); //convert to 1 string
    spdlog::warn(message); }
void Log_error(std::string message_1, double message_2) {
    message = message_1 + (std::to_string(message_2)); //convert to 1 string
    spdlog::error(message); }
void Log_critical(std::string message_1, double message_2) {
    message = message_1 + (std::to_string(message_2)); //convert to 1 string
    spdlog::critical(message); }