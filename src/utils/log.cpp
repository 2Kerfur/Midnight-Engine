#include "log.h"
#include <string>
#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h" // must be included
#include "spdlog/sinks/stdout_sinks.h"
#include <spdlog/sinks/stdout_color_sinks.h>
#include "spdlog/sinks/dup_filter_sink.h" //TODO: implement anti spam filter for messages

#include "spdlog/pattern_formatter.h"

bool LoggerInit = false;
//std::shared_ptr<spdlog::logger> render_console;
auto engine_console = spdlog::stdout_color_mt("ENGINE");
auto render_console = spdlog::stdout_color_mt("RENDER");
auto loader_console = spdlog::stdout_color_mt("LOADER");
auto physics_console = spdlog::stdout_color_mt("PHYSICS");
auto core_console = spdlog::stdout_color_mt("CORE");
auto shader_console = spdlog::stdout_color_mt("SHADER");

//spdlog::register_logger(core_console);
//LoggerInit = true;
std::string message;
void Log_init()
{
    
    
    
}
//ENGINE
    //string
    void engine_log_trace(std::string message) { engine_console->trace(message); }
    void engine_log_info(std::string message) { engine_console->info(message); }
    void engine_log_warn(std::string message) { engine_console->warn(message); }
    void engine_log_error(std::string message) { engine_console->error(message); }
    void engine_log_critical(std::string message) { engine_console->critical(message); }
    //int
    void engine_log_trace(int message) { engine_console->trace(message); }
    void engine_log_info(int message) { engine_console->info(message); }
    void engine_log_warn(int message) { engine_console->warn(message); }
    void engine_log_error(int message) { engine_console->error(message); }
    void engine_log_critical(int message) { engine_console->critical(message); }
    //string + int
    void engine_log_trace(std::string message_1, int message_2) { engine_console->trace(message_1, message_2); }
    void engine_log_info(std::string message_1, int message_2) { engine_console->info(message_1, message_2); }
    void engine_log_warn(std::string message_1, int message_2) { engine_console->warn(message_1, message_2); }
    void engine_log_error(std::string message_1, int message_2) { engine_console->error(message_1, message_2); }
    void engine_log_critical(std::string message_1, int message_2) { engine_console->critical(message_1, message_2); }
    //string + float
    void engine_log_trace(std::string message_1, double message_2) { engine_console->trace(message_1, message_2); }
    void engine_log_info(std::string message_1, double message_2) { engine_console->info(message_1, message_2); }
    void engine_log_warn(std::string message_1, double message_2) { engine_console->warn(message_1, message_2); }
    void engine_log_error(std::string message_1, double message_2) { engine_console->error(message_1, message_2); }
    void engine_log_critical(std::string message_1, double message_2) { engine_console->critical(message_1, message_2); }

//RENDER
    //string
    void render_log_trace(std::string message) { render_console->trace(message); }
    void render_log_info(std::string message) { render_console->info(message); }
    void render_log_warn(std::string message) { render_console->warn(message); }
    void render_log_error(std::string message) { render_console->error(message); }
    void render_log_critical(std::string message) { render_console->critical(message); }
    //intrender
    void render_log_trace(int message) { render_console->trace(message); }
    void render_log_info(int message) { render_console->info(message); }
    void render_log_warn(int message) { render_console->warn(message); }
    void render_log_error(int message) { render_console->error(message); }
    void render_log_critical(int message) { render_console->critical(message); }
    //strrenderint
    void render_log_trace(std::string message_1, int message_2) { render_console->trace(message_1, message_2); }
    void render_log_info(std::string message_1, int message_2) { render_console->info(message_1, message_2); }
    void render_log_warn(std::string message_1, int message_2) { render_console->warn(message_1, message_2); }
    void render_log_error(std::string message_1, int message_2) { render_console->error(message_1, message_2); }
    void render_log_critical(std::string message_1, int message_2) { render_console->critical(message_1, message_2); }
    //strrenderfloat
    void render_log_trace(std::string message_1, double message_2) { render_console->trace(message_1, message_2); }
    void render_log_info(std::string message_1, double message_2) { render_console->info(message_1, message_2); }
    void render_log_warn(std::string message_1, double message_2) { render_console->warn(message_1, message_2); }
    void render_log_error(std::string message_1, double message_2) { render_console->error(message_1, message_2); }
    void render_log_critical(std::string message_1, double message_2) { render_console->critical(message_1, message_2); }

//LOADER
    //string
    void loader_log_trace(std::string message) { loader_console->trace(message); }
    void loader_log_info(std::string message) { loader_console->info(message); }
    void loader_log_warn(std::string message) { loader_console->warn(message); }
    void loader_log_error(std::string message) { loader_console->error(message); }
    void loader_log_critical(std::string message) { loader_console->critical(message); }
    //intloader
    void loader_log_trace(int message) { loader_console->trace(message); }
    void loader_log_info(int message) { loader_console->info(message); }
    void loader_log_warn(int message) { loader_console->warn(message); }
    void loader_log_error(int message) { loader_console->error(message); }
    void loader_log_critical(int message) { loader_console->critical(message); }
    //strloaderint
    void loader_log_trace(std::string message_1, int message_2) { loader_console->trace(message_1, message_2); }
    void loader_log_info(std::string message_1, int message_2) { loader_console->info(message_1, message_2); }
    void loader_log_warn(std::string message_1, int message_2) { loader_console->warn(message_1, message_2); }
    void loader_log_error(std::string message_1, int message_2) { loader_console->error(message_1, message_2); }
    void loader_log_critical(std::string message_1, int message_2) { loader_console->critical(message_1, message_2); }
    //strloaderfloat
    void loader_log_trace(std::string message_1, double message_2) { loader_console->trace(message_1, message_2); }
    void loader_log_info(std::string message_1, double message_2) { loader_console->info(message_1, message_2); }
    void loader_log_warn(std::string message_1, double message_2) { loader_console->warn(message_1, message_2); }
    void loader_log_error(std::string message_1, double message_2) { loader_console->error(message_1, message_2); }
    void loader_log_critical(std::string message_1, double message_2) { loader_console->critical(message_1, message_2); }

//PHYSICS
    void physics_log_trace(std::string message) { physics_console->trace(message); }
    void physics_log_info(std::string message) { physics_console->info(message); }
    void physics_log_warn(std::string message) { physics_console->warn(message); }
    void physics_log_error(std::string message) { physics_console->error(message); }
    void physics_log_critical(std::string message) { physics_console->critical(message); }
    //intphysics
    void physics_log_trace(int message) { physics_console->trace(message); }
    void physics_log_info(int message) { physics_console->info(message); }
    void physics_log_warn(int message) { physics_console->warn(message); }
    void physics_log_error(int message) { physics_console->error(message); }
    void physics_log_critical(int message) { physics_console->critical(message); }
    //strphysicsint
    void physics_log_trace(std::string message_1, int message_2) { physics_console->trace(message_1, message_2); }
    void physics_log_info(std::string message_1, int message_2) { physics_console->info(message_1, message_2); }
    void physics_log_warn(std::string message_1, int message_2) { physics_console->warn(message_1, message_2); }
    void physics_log_error(std::string message_1, int message_2) { physics_console->error(message_1, message_2); }
    void physics_log_critical(std::string message_1, int message_2) { physics_console->critical(message_1, message_2); }
    //strphysicsfloat
    void physics_log_trace(std::string message_1, double message_2) { physics_console->trace(message_1, message_2); }
    void physics_log_info(std::string message_1, double message_2) { physics_console->info(message_1, message_2); }
    void physics_log_warn(std::string message_1, double message_2) { physics_console->warn(message_1, message_2); }
    void physics_log_error(std::string message_1, double message_2) { physics_console->error(message_1, message_2); }
    void physics_log_critical(std::string message_1, double message_2) { physics_console->critical(message_1, message_2); }

//CORE
    void core_log_trace(std::string message) { render_console->trace(message); }
    void core_log_info(std::string message) { core_console->info(message); }
    void core_log_warn(std::string message) { core_console->warn(message); }
    void core_log_error(std::string message) { core_console->error(message); }
    void core_log_critical(std::string message) { core_console->critical(message); }
    //intcore
    void core_log_trace(int message) { core_console->trace(message); }
    void core_log_info(int message) { core_console->info(message); }
    void core_log_warn(int message) { core_console->warn(message); }
    void core_log_error(int message) { core_console->error(message); }
    void core_log_critical(int message) { core_console->critical(message); }
    //strcoreint
    void core_log_trace(std::string message_1, int message_2) { core_console->trace(message_1, message_2); }
    void core_log_info(std::string message_1, int message_2) { core_console->info(message_1, message_2); }
    void core_log_warn(std::string message_1, int message_2) { core_console->warn(message_1, message_2); }
    void core_log_error(std::string message_1, int message_2) { core_console->error(message_1, message_2); }
    void core_log_critical(std::string message_1, int message_2) { core_console->critical(message_1, message_2); }
    //strcorefloat
    void core_log_trace(std::string message_1, double message_2) { core_console->trace(message_1, message_2); }
    void core_log_info(std::string message_1, double message_2) { core_console->info(message_1, message_2); }
    void core_log_warn(std::string message_1, double message_2) { core_console->warn(message_1, message_2); }
    void core_log_error(std::string message_1, double message_2) { core_console->error(message_1, message_2); }
    void core_log_critical(std::string message_1, double message_2) { core_console->critical(message_1, message_2); }

//SHADER
    void shader_log_trace(std::string message) { shader_console->trace(message); }
    void shader_log_info(std::string message) { shader_console->info(message); }
    void shader_log_warn(std::string message) { shader_console->warn(message); }
    void shader_log_error(std::string message) { shader_console->error(message); }
    void shader_log_critical(std::string message) { shader_console->critical(message); }
    //intshader
    void shader_log_trace(int message) { shader_console->trace(message); }
    void shader_log_info(int message) { shader_console->info(message); }
    void shader_log_warn(int message) { shader_console->warn(message); }
    void shader_log_error(int message) { shader_console->error(message); }
    void shader_log_critical(int message) { shader_console->critical(message); }
    //strshaderint
    void shader_log_trace(std::string message_1, int message_2) { shader_console->trace(message_1, message_2); }
    void shader_log_info(std::string message_1, int message_2) { shader_console->info(message_1, message_2); }
    void shader_log_warn(std::string message_1, int message_2) { shader_console->warn(message_1, message_2); }
    void shader_log_error(std::string message_1, int message_2) { shader_console->error(message_1, message_2); }
    void shader_log_critical(std::string message_1, int message_2) { shader_console->critical(message_1, message_2); }
    //strshaderfloat
    void shader_log_trace(std::string message_1, double message_2) { shader_console->trace(message_1, message_2); }
    void shader_log_info(std::string message_1, double message_2) { shader_console->info(message_1, message_2); }
    void shader_log_warn(std::string message_1, double message_2) { shader_console->warn(message_1, message_2); }
    void shader_log_error(std::string message_1, double message_2) { shader_console->error(message_1, message_2); }
    void shader_log_critical(std::string message_1, double message_2) { shader_console->critical(message_1, message_2); }
