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
    return 0;
}

int Window::GetWidth()
{
    return Win_width;
}
int Window::GetHeight()
{
    return Win_height;
}

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
}