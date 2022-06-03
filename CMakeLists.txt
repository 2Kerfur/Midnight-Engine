cmake_minimum_required(VERSION 3.20)

project(MidnightEngine VERSION 0.1)

add_executable(${PROJECT_NAME} 
    src/window/window.cpp
    src/window/window.h
    src/App.cpp
    src/App.h
)

add_subdirectory(external/glfw)
target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
)
target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw/build/src
)
if (WIN32)
    target_link_libraries(${PROJECT_NAME} glfw3)
endif (WIN32)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} glfw3 X11 dl pthread)
endif (UNIX)
