#include <iostream>
#include "window/window.h"
#include "utils/native/FileDialog.h"
#include "utils/native/FolderDialog.h"
#include "utils/log.h"

const GLuint WIDTH = 500, HEIGHT = 500;
int main()
{
    Window MainWindow;

    MainWindow.InitWindow(500, 500, "MidnightEngine");

    MainWindow.LoadGL();
    MainWindow.SetIcon();
    while (!MainWindow.WindowShouldClose())
    {


        MainWindow.ReceiveEvents();
        MainWindow.Render();
    }
    MainWindow.Close();
    return 0;
}