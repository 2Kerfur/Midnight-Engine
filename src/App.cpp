#include <iostream>
#include "window/window.h"

#include "utils/log.h"
#include "render/UI/Objects/UI_Image.h" //ui
#include "render/RenderSystem.h"

#include "window/events/keyboard/keyboardEvent.h"
#include "audio/audio.h"
#include<iostream>

#include "Config.h"

#include<glad/glad.h>
#include<GLFW/glfw3.h>


int main()
{
    Window MainWindow;
    MainWindow.InitWindow(500, 500, "MidnightEngine");
    MainWindow.SetIcon("resources\\images\\icon.png");

    MainWindow.InitEngine();

    UI_Image image;
    image.Create(100, 100, 100, 100, "testImage", "testPath");
    
    //Engine.AddGameObject()
    //KeyboardInit(MainWindow.GetWindow());

    //Audio TestAudio;
    //TestAudio.EnginePlaySound("resources\\sounds\\bruh.wav");
    RenderSystem* engine;
    engine = MainWindow.GetEngine();
    engine->AddGameObject(&image);
    while (!MainWindow.WindowShouldClose())
    {
        MainWindow.ReceiveEvents();
        MainWindow.Render();
    }
    MainWindow.Close();

    return 0;
}
