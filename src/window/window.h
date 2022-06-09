#ifdef _WIN32
#define GLFW_EXPOSE_NATIVE_WIN32

#endif
#ifndef WINDOWH
#define WINDOWH
    #include "render/RenderSystem.h"
    #include "GLFW/glfw3.h"
    #include "GLFW/glfw3native.h"
    #include <string.h>
#endif

class Window
{
private:
    bool GL_Loaded = false;
    int Win_width;
    int Win_height;
    std::string Win_name = "Window";
    GLFWwindow* window;
    RenderSystem RenderEngine;
public:
    int InitWindow(int window_width, int window_height, std::string window_name);
    
    void SetIcon(std::string file_name);

    GLFWwindow* GetWindow();
    void ReceiveEvents();
    void Render();


    int WindowShouldClose();
    int InitEngine();
    int Close();
    int GetWidth();

    int GetHeight();
};