#ifndef LOG_H
#define LOG_H
#include <string>
#include <iostream>
//#include <crtdbg.h> //TODO: This is win only
#include "Config.h"
#endif

#define STATUS_ERROR 1
#define STATUS_OK 0

#ifdef ENGINE_DEBUG //TODO: implement several loggers ex: RENDER, LOADER, PHYSICS, CORE, SHADER
void Log_init();

//void PrintDebugLine();


#define LOG_TEST SPDLOG_LOGGER_INFO(spdlog::get("ENGINE"), "log with source info")

//ENGINE LOG
//string
void engine_log_trace(std::string message);
void engine_log_info(std::string message);
void engine_log_warn(std::string message);
void engine_log_error(std::string message);
void engine_log_critical(std::string message);
//int
void engine_log_trace(int message);
void engine_log_info(int message);
void engine_log_warn(int message);
void engine_log_error(int message);
void engine_log_critical(int message);
//string + int
void engine_log_trace(std::string message_1, int message_2);
void engine_log_info(std::string message_1, int message_2);
void engine_log_warn(std::string message_1, int message_2);
void engine_log_error(std::string message_1, int message_2);
void engine_log_critical(std::string message_1, int message_2);
//string + float
void engine_log_trace(std::string message_1, double message_2);
void engine_log_info(std::string message_1, double message_2);
void engine_log_warn(std::string message_1, double message_2);
void engine_log_error(std::string message_1, double message_2);
void engine_log_critical(std::string message_1, double message_2);

//RENDER LOG
//string
void render_log_trace(std::string message);
void render_log_info(std::string message);
void render_log_warn(std::string message);
void render_log_error(std::string message);
void render_log_critical(std::string message);
//int
void render_log_trace(int message);
void render_log_info(int message);
void render_log_warn(int message);
void render_log_error(int message);
void render_log_critical(int message);
//string + int
void render_log_trace(std::string message_1, int message_2);
void render_log_info(std::string message_1, int message_2);
void render_log_warn(std::string message_1, int message_2);
void render_log_error(std::string message_1, int message_2);
void render_log_critical(std::string message_1, int message_2);
//string + float
void render_log_trace(std::string message_1, double message_2);
void render_log_info(std::string message_1, double message_2);
void render_log_warn(std::string message_1, double message_2);
void render_log_error(std::string message_1, double message_2);
void render_log_critical(std::string message_1, double message_2);

//LOADER LOG
//string
void loader_log_trace(std::string message);
void loader_log_info(std::string message);
void loader_log_warn(std::string message);
void loader_log_error(std::string message);
void loader_log_critical(std::string message);
//int
void loader_log_trace(int message);
void loader_log_info(int message);
void loader_log_warn(int message);
void loader_log_error(int message);
void loader_log_critical(int message);
//string + int
void loader_log_trace(std::string message_1, int message_2);
void loader_log_info(std::string message_1, int message_2);
void loader_log_warn(std::string message_1, int message_2);
void loader_log_error(std::string message_1, int message_2);
void loader_log_critical(std::string message_1, int message_2);
//string + float
void loader_log_trace(std::string message_1, double message_2);
void loader_log_info(std::string message_1, double message_2);
void loader_log_warn(std::string message_1, double message_2);
void loader_log_error(std::string message_1, double message_2);
void loader_log_critical(std::string message_1, double message_2);

//PHYSICS LOG
//string
void physics_log_trace(std::string message);
void physics_log_info(std::string message);
void physics_log_warn(std::string message);
void physics_log_error(std::string message);
void physics_log_critical(std::string message);
//int
void physics_log_trace(int message);
void physics_log_info(int message);
void physics_log_warn(int message);
void physics_log_error(int message);
void physics_log_critical(int message);
//string + int
void physics_log_trace(std::string message_1, int message_2);
void physics_log_info(std::string message_1, int message_2);
void physics_log_warn(std::string message_1, int message_2);
void physics_log_error(std::string message_1, int message_2);
void physics_log_critical(std::string message_1, int message_2);
//string + float
void physics_log_trace(std::string message_1, double message_2);
void physics_log_info(std::string message_1, double message_2);
void physics_log_warn(std::string message_1, double message_2);
void physics_log_error(std::string message_1, double message_2);
void physics_log_critical(std::string message_1, double message_2);

//CORE LOG
//string
void core_log_trace(std::string message);
void core_log_info(std::string message);
void core_log_warn(std::string message);
void core_log_error(std::string message);
void core_log_critical(std::string message);
//int
void core_log_trace(int message);
void core_log_info(int message);
void core_log_warn(int message);
void core_log_error(int message);
void core_log_critical(int message);
//string + int
void core_log_trace(std::string message_1, int message_2);
void core_log_info(std::string message_1, int message_2);
void core_log_warn(std::string message_1, int message_2);
void core_log_error(std::string message_1, int message_2);
void core_log_critical(std::string message_1, int message_2);
//string + float
void core_log_trace(std::string message_1, double message_2);
void core_log_info(std::string message_1, double message_2);
void core_log_warn(std::string message_1, double message_2);
void core_log_error(std::string message_1, double message_2);
void core_log_critical(std::string message_1, double message_2);

//SHADER LOG
//string
void shader_log_trace(std::string message);
void shader_log_info(std::string message);
void shader_log_warn(std::string message);
void shader_log_error(std::string message);
void shader_log_critical(std::string message);
//int
void shader_log_trace(int message);
void shader_log_info(int message);
void shader_log_warn(int message);
void shader_log_error(int message);
void shader_log_critical(int message);
//string + int
void shader_log_trace(std::string message_1, int message_2);
void shader_log_info(std::string message_1, int message_2);
void shader_log_warn(std::string message_1, int message_2);
void shader_log_error(std::string message_1, int message_2);
void shader_log_critical(std::string message_1, int message_2);
//string + float
void shader_log_trace(std::string message_1, double message_2);
void shader_log_info(std::string message_1, double message_2);
void shader_log_warn(std::string message_1, double message_2);
void shader_log_error(std::string message_1, double message_2);
void shader_log_critical(std::string message_1, double message_2);
#endif

#ifdef ENGINE_DEBUG
#define LOG_INIT() Log_init() 

#define LOG_TRACE(message_1, ...)     engine_log_trace(message_1, __VA_ARGS__)
#define LOG_INFO(message_1, ...)      engine_log_info(message_1, __VA_ARGS__)
#define LOG_WARN(message_1, ...)       engine_log_warn(message_1, __VA_ARGS__)
#define LOG_ERROR(message_1, ...)     engine_log_error(message_1, __VA_ARGS__)
#define LOG_CRITICAL(message_1, ...)   engine_log_critical(message_1, __VA_ARGS__)

#define RENDER_LOG_TRACE(message_1, ...)     render_log_trace(message_1, __VA_ARGS__)
#define RENDER_LOG_INFO(message_1, ...)      render_log_info(message_1, __VA_ARGS__)
#define RENDER_LOG_WARN(message_1, ...)       render_log_warn(message_1, __VA_ARGS__)
#define RENDER_LOG_ERROR(message_1, ...)     render_log_error(message_1, __VA_ARGS__)

//#ifdef ON_CRITICAL_DO_ASSERTE
//#define RENDER_LOG_CRITICAL(message_1, ...)   render_log_critical(message_1, __VA_ARGS__);_ASSERTE(0)
//#else
#define RENDER_LOG_CRITICAL(message_1, ...)   render_log_critical(message_1, __VA_ARGS__)
//#endif

#define LOADER_LOG_TRACE(message_1, ...)     loader_log_trace(message_1, __VA_ARGS__)
#define LOADER_LOG_INFO(message_1, ...)      loader_log_info(message_1, __VA_ARGS__)
#define LOADER_LOG_WARN(message_1, ...)       loader_log_warn(message_1, __VA_ARGS__)
#define LOADER_LOG_ERROR(message_1, ...)     loader_log_error(message_1, __VA_ARGS__)

//#ifdef ON_CRITICAL_DO_ASSERTE
//#define LOADER_LOG_CRITICAL(message_1, ...)   loader_log_critical(message_1, __VA_ARGS__);_ASSERTE(0)
//#else 
#define LOADER_LOG_CRITICAL(message_1, ...)   loader_log_critical(message_1, __VA_ARGS__)
//#endif

#define PHYSICS_LOG_TRACE(message_1, ...)     physics_log_trace(message_1, __VA_ARGS__)
#define PHYSICS_LOG_INFO(message_1, ...)      physics_log_info(message_1, __VA_ARGS__)
#define PHYSICS_LOG_WARN(message_1, ...)       physics_log_warn(message_1, __VA_ARGS__)
#define PHYSICS_LOG_ERROR(message_1, ...)     physics_log_error(message_1, __VA_ARGS__)

//#ifdef ON_CRITICAL_DO_ASSERTE
//#define PHYSICS_LOG_CRITICAL(message_1, ...)   physics_log_critical(message_1, __VA_ARGS__);_ASSERTE(0)
//#else
#define PHYSICS_LOG_CRITICAL(message_1, ...)   physics_log_critical(message_1, __VA_ARGS__)
//#endif

#define CORE_LOG_TRACE(message_1, ...)     core_log_trace(message_1, __VA_ARGS__)
#define CORE_LOG_INFO(message_1, ...)      core_log_info(message_1, __VA_ARGS__)
#define CORE_LOG_WARN(message_1, ...)       core_log_warn(message_1, __VA_ARGS__)
#define CORE_LOG_ERROR(message_1, ...)     core_log_error(message_1, __VA_ARGS__)

//#ifdef ON_CRITICAL_DO_ASSERTE
//#define CORE_LOG_CRITICAL(message_1, ...)   core_log_critical(message_1, __VA_ARGS__);_ASSERTE(0)
//#else
#define CORE_LOG_CRITICAL(message_1, ...)   core_log_critical(message_1, __VA_ARGS__)
//#endif

#define SHADER_LOG_TRACE(message_1, ...)     shader_log_trace(message_1, __VA_ARGS__)
#define SHADER_LOG_INFO(message_1, ...)      shader_log_info(message_1, __VA_ARGS__)
#define SHADER_LOG_WARN(message_1, ...)       shader_log_warn(message_1, __VA_ARGS__)
#define SHADER_LOG_ERROR(message_1, ...)     shader_log_error(message_1, __VA_ARGS__)

//#ifdef ON_CRITICAL_DO_ASSERTE
//#define SHADER_LOG_CRITICAL(message_1, ...)   shader_log_critical(message_1, __VA_ARGS__);_ASSERTE(0)
//#else
#define SHADER_LOG_CRITICAL(message_1, ...)   shader_log_critical(message_1, __VA_ARGS__)
//#endif

#endif

#ifdef ENGINE_RELEASE
#define LOG_INIT()

#define LOG_TRACE(message_1, ...)
#define LOG_INFO(message_1, ...)   
#define LOG_WARN(message_1, ...)  
#define LOG_ERROR(message_1, ...)
#define LOG_CRITICAL(message_1, ...)

#define RENDER_LOG_TRACE(message_1, ...)   
#define RENDER_LOG_INFO(message_1, ...)    
#define RENDER_LOG_WARN(message_1, ...)     
#define RENDER_LOG_ERROR(message_1, ...)    
#define RENDER_LOG_CRITICAL(message_1, ...)

#define LOADER_LOG_TRACE(message_1, ...)    
#define LOADER_LOG_INFO(message_1, ...)     
#define LOADER_LOG_WARN(message_1, ...)     
#define LOADER_LOG_ERROR(message_1, ...)    
#define LOADER_LOG_CRITICAL(message_1, ...) 

#define PHYSICS_LOG_TRACE(message_1, ...)  
#define PHYSICS_LOG_INFO(message_1, ...)  
#define PHYSICS_LOG_WARN(message_1, ...)  
#define PHYSICS_LOG_ERROR(message_1, ...)  
#define PHYSICS_LOG_CRITICAL(message_1, ...)

#define CORE_LOG_TRACE(message_1, ...)    
#define CORE_LOG_INFO(message_1, ...)      
#define CORE_LOG_WARN(message_1, ...)       
#define CORE_LOG_ERROR(message_1, ...)     
#define CORE_LOG_CRITICAL(message_1, ...)   

#define SHADER_LOG_TRACE(message_1, ...)    
#define SHADER_LOG_INFO(message_1, ...)     
#define SHADER_LOG_WARN(message_1, ...)     
#define SHADER_LOG_ERROR(message_1, ...)    
#define SHADER_LOG_CRITICAL(message_1, ...) 

#endif