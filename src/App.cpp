#include <iostream>
#include "window/window.h"
#include "utils/log.h"
#include "window/events/keyboard/keyboardEvent.h"
#include "audio/audio.h"

//#include "render/UI/Objects/UI_Image.h"

int main()
{
    Window MainWindow;
    MainWindow.InitWindow(500, 500, "MidnightEngine");
    MainWindow.SetIcon("resources\\images\\icon.png");

    MainWindow.InitEngine();

    KeyboardInit(MainWindow.GetWindow());

    Audio TestAudio;
    TestAudio.EnginePlaySound("resources\\sounds\\bruh.wav");
    
    //UI_Image TestImage;
    //TestImage.Create();
    //MainWindow.EngineAddObj(TestImage);

    while (!MainWindow.WindowShouldClose())
    {
        MainWindow.ReceiveEvents();
        MainWindow.Render();
    }
    MainWindow.Close();
    return 0;
}