#include "spdlog/spdlog.h"
#define LOG_TRACE(message)     spdlog::trace(message)
#define LOG_INFO(message)      spdlog::info(message)
#define LOG_WARN(message)       spdlog::warn(message)
#define LOG_ERROR(message)     spdlog::error(message)
#define LOG_CRITICAL(message)   spdlog::critical(message)
