#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "GLFW/glfw3.h"

static class KeyboardEventReader 
{
private:
    GLFWwindow* window;
    char button = '0';
    void UpdateButton(char key);
public:
    void KeyboardButtonPressed(int key);
    int Init(GLFWwindow* app_window);
    void Update();
    
    char GetPressedButton();
};
void KeyboardInit(GLFWwindow* window);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

char GetButton();

#endif