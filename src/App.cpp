#include <iostream>
#include "window/window.h"

#include "utils/log.h"
#include "render/UI/Objects/UI_Image.h" //ui
#include "render/UI/Objects/UI_Button.h" //ui

#include "render/RenderSystem.h"

#include "window/events/keyboard/keyboardEvent.h"
#include "audio/audio.h"
#include<iostream>

#include "Config.h"

#include<glad/glad.h>
#include<GLFW/glfw3.h>


void getdata(char pressed)
{
    LOG_INFO("Button pressed");
}

//
int main()
{
    //LOG_INIT();
    Window MainWindow;
    MainWindow.InitWindow(1000, 800, "MidnightEngine");
    MainWindow.SetIcon("resources\\images\\icon.png");

    MainWindow.InitEngine();
    //MainWindow.SetFullscreen();

    UI_Image image;
    UI_Button button;
    image.Create(100, 100, 100, 100, "testImage", "testPath");
    button.Create(0,0, 100, 100, "testButton", "testPath", MainWindow.GetWindow());
    button.SetListener(&getdata);

    RenderSystem* engine;
    engine = MainWindow.GetEngine();
    //engine->AddGameObject(&image);
    engine->AddGameObject(&button);


    MainWindow.CompileShaders();
    while (!MainWindow.WindowShouldClose())
    {
        MainWindow.ReceiveEvents();
        MainWindow.Render();
    }
    MainWindow.Close();
    

    return 0;
}
