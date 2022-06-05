#include "keyboardEvent.h"
#include "GLFW/glfw3.h"
#include "utils/log.h"
#include "GetKey.h"
#include <iostream>

//TODO: Create OOP based keyboard input system

//auto func = [](GLFWwindow* window, int key, int scancode, int)
    //{
    //    static_cast<KeyboardEventReader*>(glfwGetWindowUserPointer(window))->KeyboardButtonPressed(key);
    //};

//int KeyboardEventReader::Init(GLFWwindow* app_window)
//{
//    window = app_window; //get main window
//    //glfwSetKeyCallback(window, KeyboardEventReader::key_callback);
//    std::cout <<"Init keyboard" << std::endl;
//    
//
//    //glfwSetKeyCallback(window, func);
//    return 0;
//}
//
//void KeyboardEventReader::KeyboardButtonPressed(int key_id)
//{
//    button = GetCharKey(key_id);
//}
//
//void KeyboardEventReader::Update()
//{
//
//}
//
//char KeyboardEventReader::GetPressedButton()
//{
//    return button;
//}
char PressedButton = '0';
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    PressedButton = GetCharKey(key);
}
char GetButton()
{
    return PressedButton;
}

void KeyboardInit(GLFWwindow* window)
{
    glfwSetKeyCallback(window, key_callback);
}