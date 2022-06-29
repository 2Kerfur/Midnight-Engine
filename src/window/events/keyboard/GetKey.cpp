#include "GetKey.h"
#include "GLFW/glfw3.h"

char GetCharKey(int number)
{
    char key;
    if (number == GLFW_KEY_0) key = '0';
    else if (number == GLFW_KEY_1) key = '1';
    else if (number == GLFW_KEY_2) key = '2';
    else if (number == GLFW_KEY_3) key = '3';
    else if (number == GLFW_KEY_4) key = '4';
    else if (number == GLFW_KEY_5) key = '5';
    else if (number == GLFW_KEY_6) key = '6';
    else if (number == GLFW_KEY_7) key = '7';
    else if (number == GLFW_KEY_8) key = '8';
    else if (number == GLFW_KEY_9) key = '9';
    else if (number == GLFW_KEY_SEMICOLON) key = ';';
    else if (number == GLFW_KEY_EQUAL) key = '=';
    else if (number == GLFW_KEY_A) key = 'A';
    else if (number == GLFW_KEY_B) key = 'B';
    else if (number == GLFW_KEY_C) key = 'C';
    else if (number == GLFW_KEY_D) key = 'D';
    else if (number == GLFW_KEY_E) key = 'E';
    else if (number == GLFW_KEY_F) key = 'F';
    else if (number == GLFW_KEY_G) key = 'G';
    else if (number == GLFW_KEY_H) key = 'H';
    else if (number == GLFW_KEY_I) key = 'I';
    else if (number == GLFW_KEY_J) key = 'J';
    else if (number == GLFW_KEY_K) key = 'K';
    else if (number == GLFW_KEY_L) key = 'L';
    else if (number == GLFW_KEY_M) key = 'M';
    else if (number == GLFW_KEY_N) key = 'N';
    else if (number == GLFW_KEY_O) key = 'O';
    else if (number == GLFW_KEY_P) key = 'P';
    else if (number == GLFW_KEY_Q) key = 'Q';
    else if (number == GLFW_KEY_R) key = 'R';
    else if (number == GLFW_KEY_S) key = 'S';
    else if (number == GLFW_KEY_T) key = 'T';
    else if (number == GLFW_KEY_U) key = 'U';
    else if (number == GLFW_KEY_V) key = 'V';
    else if (number == GLFW_KEY_W) key = 'W';
    else if (number == GLFW_KEY_X) key = 'X';
    else if (number == GLFW_KEY_Y) key = 'Y';
    else if (number == GLFW_KEY_Z) key = 'Z';
    else key = '~';
    return key;
}
//if (number == GLFW_KEY_UNKNOWN) 
//if (number == GLFW_KEY_SPACE)
//if (number == GLFW_KEY_APOSTROPHE)
//if (number == GLFW_KEY_COMMA)
//if (number == GLFW_KEY_MINUS)
//if (number == GLFW_KEY_PERIOD)
//if (number == GLFW_KEY_SLASH)

//if (number == GLFW_KEY_LEFT_BRACKET)
//if (number == GLFW_KEY_BACKSLASH)
//if (number == GLFW_KEY_RIGHT_BRACKET)
//if (number == GLFW_KEY_GRAVE_ACCENT)
//if (number == GLFW_KEY_WORLD_1)
//if (number == GLFW_KEY_WORLD_2)
//if (number == GLFW_KEY_ESCAPE)
//if (number == GLFW_KEY_ENTER)
//if (number == GLFW_KEY_TAB)
//if (number == GLFW_KEY_BACKSPACE)
//if (number == GLFW_KEY_INSERT)
//if (number == GLFW_KEY_DELETE)
//if (number == GLFW_KEY_RIGHT)
//if (number == GLFW_KEY_LEFT)
//if (number == GLFW_KEY_DOWN)
//if (number == GLFW_KEY_UP)
//if (number == GLFW_KEY_PAGE_UP)
//if (number == GLFW_KEY_PAGE_DOWN)
//if (number == GLFW_KEY_HOME)
//if (number == GLFW_KEY_END)
//if (number == GLFW_KEY_CAPS_LOCK)
//if (number == GLFW_KEY_SCROLL_LOCK)
//if (number == GLFW_KEY_NUM_LOCK)
//if (number == GLFW_KEY_PRINT_SCREEN)
//if (number == GLFW_KEY_PAUSE)
//if (number == GLFW_KEY_F1)
//if (number == GLFW_KEY_F2)
//if (number == GLFW_KEY_F3)
//if (number == GLFW_KEY_F4)
//if (number == GLFW_KEY_F5)
//if (number == GLFW_KEY_F6)
//if (number == GLFW_KEY_F7)
//if (number == GLFW_KEY_F8)
//if (number == GLFW_KEY_F9)
//if (number == GLFW_KEY_F10)
//if (number == GLFW_KEY_F11)
//if (number == GLFW_KEY_F12)
//if (number == GLFW_KEY_F13)
//if (number == GLFW_KEY_F14)
//if (number == GLFW_KEY_F15)
//if (number == GLFW_KEY_F16)
//if (number == GLFW_KEY_F17)
//if (number == GLFW_KEY_F18)
//if (number == GLFW_KEY_F19)
//if (number == GLFW_KEY_F20)
//if (number == GLFW_KEY_F21)
//if (number == GLFW_KEY_F22)
//if (number == GLFW_KEY_F23)
//if (number == GLFW_KEY_F24)
//if (number == GLFW_KEY_F25)
//if (number == GLFW_KEY_KP_0)
//if (number == GLFW_KEY_KP_1)
//if (number == GLFW_KEY_KP_2)
//if (number == GLFW_KEY_KP_3)
//if (number == GLFW_KEY_KP_4)
//if (number == GLFW_KEY_KP_5)
//if (number == GLFW_KEY_KP_6)
//if (number == GLFW_KEY_KP_7)
//if (number == GLFW_KEY_KP_8)
//if (number == GLFW_KEY_KP_9)
//if (number == GLFW_KEY_KP_DECIMAL)
//if (number == GLFW_KEY_KP_DIVIDE)
//if (number == GLFW_KEY_KP_MULTIPLY)
//if (number == GLFW_KEY_KP_SUBTRACT)
//if (number == GLFW_KEY_KP_ADD)
//if (number == GLFW_KEY_KP_ENTER)
//if (number == GLFW_KEY_KP_EQUAL)
//if (number == GLFW_KEY_LEFT_SHIFT)
//if (number == GLFW_KEY_LEFT_CONTROL)
//if (number == GLFW_KEY_LEFT_ALT)
//if (number == GLFW_KEY_LEFT_SUPER)
//if (number == GLFW_KEY_RIGHT_SHIFT)
//if (number == GLFW_KEY_RIGHT_CONTROL)
//if (number == GLFW_KEY_RIGHT_ALT)
//if (number == GLFW_KEY_RIGHT_SUPER)
//if (number == GLFW_KEY_MENU)
//if (number == GLFW_KEY_LAST)