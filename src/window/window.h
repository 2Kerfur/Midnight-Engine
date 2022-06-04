#include "glad/glad.h"

#ifdef _WIN32
#define GLFW_EXPOSE_NATIVE_WIN32

#endif

#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#include "utils/log.h"

class Window
{
private:
    int Win_width;
    int Win_height;
    char Win_name[128] = "Window";
    GLFWwindow* window;
    
public:
    int InitWindow(int window_width, int window_height);
    
    void ReceiveEvents();
    int WindowShouldClose();
    int Close();
    int GetWidth();
    int GetHeight();
    int LoadGL();
};