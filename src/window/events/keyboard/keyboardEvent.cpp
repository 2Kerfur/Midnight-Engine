#include "keyboardEvent.h"
#include "GLFW/glfw3.h"
#include "utils/log.h"
#include "GetKey.h"
#include <iostream>

//void KeyboardEventReader::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
    //std::cout <<"Some key callback" << std::endl;
    //if (key == GLFW_KEY_E && action == GLFW_PRESS)
        //LOG_INFO("Button_E pressed");
    
//}
auto func = [](GLFWwindow* window, int key, int scancode, int)
    {
        static_cast<KeyboardEventReader*>(glfwGetWindowUserPointer(window))->KeyboardButtonPressed(key);
    };

int KeyboardEventReader::Init(GLFWwindow* app_window)
{
    window = app_window; //get main window
    //glfwSetKeyCallback(window, KeyboardEventReader::key_callback);
    std::cout <<"Init keyboard" << std::endl;
    

    //glfwSetKeyCallback(window, func);
    glfwSetMouseButtonCallback(window, func);
    return 0;
}

void KeyboardEventReader::KeyboardButtonPressed(int key_id)
{
    button = GetCharKey(key_id);
}

void KeyboardEventReader::Update()
{

}

char KeyboardEventReader::GetPressedButton()
{
    return button;
}
