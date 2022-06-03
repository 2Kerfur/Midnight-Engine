#include <iostream>
#include "glad/glad.h"
#include "window/window.h"
#include "utils/log.h"
int main()
{
    Window MainWindow;

    MainWindow.InitWindow(500, 500);

    //if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    //{
    //std::cout << "Failed to initialize GLAD" << std::endl;
    //return -1;
    //}   

    while (!MainWindow.WindowShouldClose())
    {


        MainWindow.ReceiveEvents();
    }
    MainWindow.Close();
    return 0;
}