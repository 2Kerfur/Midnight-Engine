cmake_minimum_required(VERSION 3.20)

project(MidnightEngine VERSION 0.1)

add_executable(${PROJECT_NAME} 
    src/App.cpp
    src/App.h

    #AUDIO
    src/audio/audio.cpp
    src/audio/audio.h

    #WINDOW
    src/window/window.cpp
    src/window/window.h
        #events
        src/window/events/EventSystem.cpp
        src/window/events/EventSystem.h
        src/window/events/windowEvent.cpp
        src/window/events/windowEvent.h
            #keyboard
            src/window/events/keyboard/keyboardEvent.cpp
            src/window/events/keyboard/keyboardEvent.h
            src/window/events/keyboard/GetKey.h
            src/window/events/keyboard/GetKey.cpp
            #mouse
            src/window/events/mouse/mouseEvent.cpp
            src/window/events/mouse/mouseEvent.h
            
    #UTILS
    src/utils/log.cpp
    src/utils/log.h
        #native
        src/utils/native/FileDialog.cpp
        src/utils/native/FileDialog.h
        src/utils/native/FolderDialog.cpp
        src/utils/native/FolderDialog.h

    #RENDER
    src/render/RenderSystem.cpp
    src/render/RenderSystem.h
    src/render/Shader.h
    src/render/Shader.cpp
    src/render/GameObject.cpp
    src/render/GameObject.h
        #ui
        src/render/UI/UI_manager.cpp
        src/render/UI/UI_manager.h
            #objects
            src/render/UI/Objects/UI_Button.cpp
            src/render/UI/Objects/UI_Button.h
            src/render/UI/Objects/UI_Image.cpp
            src/render/UI/Objects/UI_Image.h
            src/render/UI/Objects/UI_Text.cpp
            src/render/UI/Objects/UI_Text.h
            src/render/UI/Objects/UI.cpp
            src/render/UI/Objects/UI.h

    #TOOLS
    src/tools/imgui_test.cpp
    src/tools/imgui_test.h

    #external executables
    external/glad/src/glad.c
)

add_subdirectory(external/glfw)
add_subdirectory(external/spdlog-1.10.0)
target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
    PUBLIC external/spdlog-1.10.0/include
    PUBLIC external/glad/include
    PUBLIC src
    PUBLIC external
    PUBLIC external/imgui
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
