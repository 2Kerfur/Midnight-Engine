#include <iostream>
#include "window/window.h"
#include "utils/native/FileDialog.h"
#include "utils/native/FolderDialog.h"
#include "utils/log.h"
#include "window/events/keyboard/keyboardEvent.h"

int main()
{
    Window MainWindow;
    MainWindow.InitWindow(500, 500, "MidnightEngine");
    MainWindow.SetIcon("images\\icon.png");

    MainWindow.LoadGL();
    

    KeyboardInit(MainWindow.GetWindow());
    

    MainWindow.CompileShaders();
    while (!MainWindow.WindowShouldClose())
    {
        LOG_INFO(GetButton());
        MainWindow.ReceiveEvents();
        MainWindow.Render();
    }
    MainWindow.Close();
    return 0;
}