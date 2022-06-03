#include <iostream>
#include "window/window.h"
int main()
{
    Window MainWindow;

    MainWindow.InitWindow(500, 500);

    while (!MainWindow.WindowShouldClose())
    {


        MainWindow.ReceiveEvents();
    }
    MainWindow.Close();
    return 0;
}