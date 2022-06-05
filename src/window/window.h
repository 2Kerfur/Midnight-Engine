#include "glad/glad.h"

#ifdef _WIN32
#define GLFW_EXPOSE_NATIVE_WIN32

#endif

#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#include "utils/log.h"

#include <string.h>

class Window
{
private:
    bool GL_Loaded = false;
    int Win_width;
    int Win_height;
    std::string Win_name = "Window";
    GLFWwindow* window;

    
public:
    int InitWindow(int window_width, int window_height, std::string window_name);
    
    void SetIcon();

    GLFWwindow* GetWindow();

    void ReceiveEvents();
    void Render();
    int WindowShouldClose();
    int Close();
    int GetWidth();
    int GetHeight();
    int LoadGL();
};