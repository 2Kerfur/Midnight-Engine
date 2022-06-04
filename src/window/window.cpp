#include "window.h"

int Window::InitWindow(int window_width, int window_height)
{
    Win_width = window_width;
    Win_height = window_height;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(window_width, window_height,
    "Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    HWND Win32Hwnd = nullptr;
    //Win32Hwnd = glfwGetWin32Window(window);
    return 0;
}

int Window::GetWidth() { return Win_width;}
int Window::GetHeight() { return Win_height;}

int Window::Close()
{
    glfwTerminate();
    return 0;
}


int Window::WindowShouldClose()
{
    return glfwWindowShouldClose(window);
}
void Window::ReceiveEvents()
{
    glfwPollEvents();
    glfwGetFramebufferSize(window, &Win_width, &Win_height);
}

int Window::LoadGL()
{
    if(!gladLoadGL())
    {
        LOG_CRITICAL("Glad OpenGL loading error");
        return -1;
    } else
    {
        LOG_INFO("Glad OpenGL loaded successfully");
    }
    
    glViewport(0, 0, Win_width, Win_height);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    return 0;
}