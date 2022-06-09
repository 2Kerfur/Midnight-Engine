#include "window.h"
#define STB_IMAGE_IMPLEMENTATION

#ifdef _WIN32 
#include <Windows.h>
#endif

#include "utils/log.h"
#include <string>
#include "stb/stb_image.h"
int Window::InitWindow(int window_width, int window_height, std::string window_name)
{
    Win_width = window_width;
    Win_height = window_height;
    Win_name = window_name;
    
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(window_width, window_height, Win_name.c_str(), NULL, NULL); //create main window
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    return 0;
}
void Window::SetIcon(std::string file_name)
{
#ifdef _WIN32 //TODO: Create set icon implementation for linux
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::string fileLocation = std::string(buffer); //path with .exe
    std::string fileFolderLocation = fileLocation.substr(0, fileLocation.find_last_of("\\/")); //path without .exe only folder
    std::string endFileLocation = fileFolderLocation + "\\" + file_name;
#endif
    
    GLFWimage images[1]; 
    images[0].pixels = stbi_load(endFileLocation.c_str(), &images[0].width, &images[0].height, 0, 4);
    glfwSetWindowIcon(window, 1, images); 
    stbi_image_free(images[0].pixels);
}
int Window::GetWidth() { return Win_width;}
int Window::GetHeight() { return Win_height;}
int Window::Close()
{
    glfwTerminate();
    return 0;
}
GLFWwindow* Window::GetWindow()
{
    return window;
}
int Window::WindowShouldClose()
{
    return glfwWindowShouldClose(window);
}
void Window::ReceiveEvents()
{
    glfwPollEvents();
    glfwGetFramebufferSize(window, &Win_width, &Win_height);
    RenderEngine.SetRenderSize(Win_width, Win_height);
}

void Window::Render()
{
    RenderEngine.Render(window);
    glfwSwapBuffers(window);
}

int Window::InitEngine()
{
    RenderEngine.Init(Win_width, Win_height, window);
    RenderEngine.CompileShaders();
    return 0;
}