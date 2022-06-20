cmake_minimum_required(VERSION 3.20)

project(MidnightEngine VERSION 0.1)
find_package(OpenGL REQUIRED)


if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

add_executable(${PROJECT_NAME} 
    src/App.cpp
    src/App.h
    src/Config.h

    #AUDIO
    src/audio/audio.cpp
    src/audio/audio.h

    #WINDOW
    src/window/Window.cpp
    src/window/Window.h
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
        #loader
        src/utils/loader/ResourceLoader.cpp
        src/utils/loader/ResourceLoader.h
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
    
    #new update
    src/render/Camera.cpp
    src/render/Camera.h

    src/render/EBO.h
    src/render/EBO.cpp
    src/render/Texture.cpp
    src/render/Texture.h
    src/render/VAO.cpp
    src/render/VAO.h
    src/render/VBO.cpp
    src/render/VBO.h
        #actors
        src/render/Actors/Mesh.cpp
        src/render/Actors/Mesh.h
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
    #spdlog
    #"spdlog/sinks/stdout_sinks.h"
    external/spdlog-1.10.0/include/spdlog/sinks/stdout_sinks.h
    external/spdlog-1.10.0/include/spdlog/spdlog.h
    external/spdlog-1.10.0/include/spdlog/sinks/stdout_color_sinks.h

    #tools/imgui_test.cpp
    #tools/imgui_test.h

    #external executables
    external/glad/src/glad.c
    external/freetype/ft2build.h

    #imgui
        external/imgui/imconfig.h
        external/imgui/imgui.cpp
        external/imgui/imgui.h
        external/imgui/imgui_demo.cpp
        external/imgui/imgui_draw.cpp

        external/imgui/imgui_impl_glfw.cpp
        external/imgui/imgui_impl_glfw.h
        external/imgui/imgui_impl_opengl3.cpp
        external/imgui/imgui_impl_opengl3.h
        external/imgui/imgui_internal.h

        external/imgui/imgui_tables.cpp
        external/imgui/imgui_widgets.cpp
        external/imgui/imstb_rectpack.h
        external/imgui/imstb_textedit.h
        external/imgui/imstb_truetype.h
        external/imgui/imgui_impl_opengl3_loader.h

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
    PUBLIC external/freetype
)
target_link_directories(${PROJECT_NAME}
    PRIVATE external/freetype
    PRIVATE external/glfw/build/src
    PRIVATE external/freetype
)
if (WIN32)
    target_link_libraries(${PROJECT_NAME} glfw3 ${OPENGL_LIBRARY} freetype)
endif (WIN32)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} glfw3 X11 dl pthread)
endif (UNIX)
