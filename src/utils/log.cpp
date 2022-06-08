#include "log.h"
#include <string>
#include "spdlog/spdlog.h"

int LoggerInit()
{
    return 0;
}

void Log_trace(std::string message) { spdlog::trace(message); }
void Log_info(std::string message) { spdlog::info(message); }
void Log_warn(std::string message) { spdlog::warn(message); }
void Log_error(std::string message) { spdlog::error(message); }
void Log_critical(std::string message) { spdlog::critical(message); }

