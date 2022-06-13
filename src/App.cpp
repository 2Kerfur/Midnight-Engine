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

//
int main()
{
    LOG_INIT();
    Window MainWindow;
    MainWindow.InitWindow(800, 800, "MidnightEngine");
    MainWindow.SetIcon("resources\\images\\icon.png");

    MainWindow.InitEngine();
    
    UI_Image image;
    image.Create(100, 100, 100, 100, "testImage", "testPath");
    
    
    LOG_CRITICAL("Test");
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
