#include "window.h"
#define STB_IMAGE_IMPLEMENTATION

#ifdef _WIN32
#include <Windows.h>
#endif

#include <string>
#include <iostream>
#include "stb/stb_image.h"

#include "glm/glm.hpp" //math
int Window::InitWindow(int window_width, int window_height, std::string window_name)
{
    Win_width = window_width;
    Win_height = window_height;
    Win_name = window_name;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(window_width, window_height, Win_name.c_str(), NULL, NULL); //create main window
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    return 0;
}
void Window::SetIcon(std::string file_name)
{
#ifdef _WIN32 //TODO: Create set icon implementation for linux
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::string fileLocation = std::string(buffer); //with .exe
    std::string fileFolderLocation = fileLocation.substr(0, fileLocation.find_last_of("\\/")); //without .exe only folder
    std::string endFileLocation = fileFolderLocation + "\\" + file_name;
#endif
    
    GLFWimage images[1]; 
    images[0].pixels = stbi_load(endFileLocation.c_str(), &images[0].width, &images[0].height, 0, 4);
    glfwSetWindowIcon(window, 1, images); 
    stbi_image_free(images[0].pixels);
}
int Window::GetWidth() { return Win_width;}
int Window::GetHeight() { return Win_height;}

int Window::Close()
{
    glfwTerminate();
    return 0;
}

GLFWwindow* Window::GetWindow()
{
    return window;
}

int Window::WindowShouldClose()
{
    return glfwWindowShouldClose(window);
}
void Window::ReceiveEvents()
{
    glfwPollEvents();

    glfwGetFramebufferSize(window, &Win_width, &Win_height);
    if (GL_Loaded)
    {
        glViewport(0, 0, Win_width, Win_height);
    }
}
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";
unsigned int vertexShader;
int success;
char infoLog[512];
unsigned int fragmentShader;
unsigned int shaderProgram;

float vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,  // first Triangle
    1, 2, 3   // second Triangle
};
unsigned int VBO, VAO, EBO;
void Window::Render()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO); 
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDeleteShader(shaderProgram);
    glfwSwapBuffers(window);
}

void Window::CompileShaders()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //-------------------------
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        //std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        //std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        //std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


int Window::LoadGL()
{
    if(!gladLoadGL())
    {
        LOG_CRITICAL("Glad OpenGL loading error");
        return -1;
    } else
    {
        LOG_INFO("Glad OpenGL loaded successfully");
        GL_Loaded = true;
    }
    glViewport(0, 0, Win_width, Win_height);
    return 0;
}