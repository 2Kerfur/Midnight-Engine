#include <iostream>
#include "window/window.h"
#include "utils/native/FileDialog.h"
#include "utils/native/FolderDialog.h"
#include "utils/log.h"
#include "window/events/keyboard/keyboardEvent.h"

//#include "render/Object.h"
#include "render/UI/Objects/UI.h"

int main()
{
    Window MainWindow;
    MainWindow.InitWindow(500, 500, "MidnightEngine");
    MainWindow.SetIcon("images\\icon.png");

    MainWindow.LoadGL();

    UI TestUi;
    TestUi.Create();

    KeyboardInit(MainWindow.GetWindow());


    MainWindow.CompileShaders();
    while (!MainWindow.WindowShouldClose())
    {
        
        MainWindow.ReceiveEvents();
        MainWindow.Render();
    }
    MainWindow.Close();
    return 0;
}