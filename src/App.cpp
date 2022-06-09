#include <iostream>
#include "window/window.h"
#include "utils/log.h"
#include "window/events/keyboard/keyboardEvent.h"
#include "audio/audio.h"
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>


int main()
{
    Window MainWindow;
    MainWindow.InitWindow(500, 500, "MidnightEngine");
    MainWindow.SetIcon("resources\\images\\icon.png");

    MainWindow.InitEngine();
    //KeyboardInit(MainWindow.GetWindow());

    //Audio TestAudio;
    //TestAudio.EnginePlaySound("resources\\sounds\\bruh.wav");


    while (!MainWindow.WindowShouldClose())
    {
        MainWindow.ReceiveEvents();
        MainWindow.Render();
    }
    MainWindow.Close();

    return 0;
}