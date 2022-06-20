#define IMGUI_IMPL_OPENGL_LOADER_GLAD //set default gl loader for imgui
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Window.h"
#define STB_IMAGE_IMPLEMENTATION

#ifdef _WIN32 
#include <Windows.h> 
#endif

#include "utils/log.h"
#include "Config.h"
#include <string>
#include "stb/stb_image.h"



int Window::InitWindow(int window_width, int window_height, std::string window_name)
{
    Win_width = window_width;
    Win_height = window_height;
    Win_name = window_name;
    
    if (!glfwInit())
    {
        LOG_CRITICAL("GLFW initialization failed");
        return -1;
    }
        
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //set openGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //set only new gl features avalible

    window = glfwCreateWindow(window_width, window_height, Win_name.c_str(), NULL, NULL); //create main window
    
    if (!window)
    {
        LOG_CRITICAL("GLFW window creation failed");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    //IMGUI
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
    io.ConfigFlags |= ImGuiDockNodeFlags_PassthruCentralNode;                                                         //io.ConfigFlags |= ImGuiDockNodeFlags_DockSpace;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(OPENGL_VERSION);
    //IMGUI
    
    return 0;
}

void Window::SetIcon(std::string file_name)
{
#ifdef _WIN32 //TODO: Create set icon implementation for linux
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::string fileLocation = std::string(buffer); //path with .exe
    std::string fileFolderLocation = fileLocation.substr(0, fileLocation.find_last_of("\\/")); //path without .exe only folder
    std::string endFileLocation = fileFolderLocation + "\\" + file_name;
#endif
    
    GLFWimage images[1]; 
    images[0].pixels = stbi_load(endFileLocation.c_str(), &images[0].width, &images[0].height, 0, 4); //load icon from file
    glfwSetWindowIcon(window, 1, images); //set icon
    stbi_image_free(images[0].pixels); //free memory
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
    RenderEngine.SetRenderSize(Win_width, Win_height);
}

void Window::Render()
{
    RenderEngine.Render(window);
    
    glfwSwapBuffers(window);
}

int Window::InitEngine()
{
    int code = RenderEngine.Init(Win_width, Win_height, window);
    if (!code)
    {
        LOG_INFO("Engine successfully initialized. Code: {}", code);
        return 0;
    }
    else
    {
        LOG_INFO("Engine initialization error. Code: {}", code);
        return 1;
    }   
}

int Window::CompileShaders()
{
    int code = RenderEngine.CompileShaders();
    if (!code)
    {
        LOG_INFO("Shader compilation success: {}", code);
        return 0;
    }
    else
    {
        LOG_INFO("Shader compilation failed. Code: {}", code);
        return 1;
    }
}

void Window::SetFullscreen()
{
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate);
    glfwSwapInterval(1); //set fps lock to 60 max fps
    LOG_INFO("GLFW Fullscreen mode activated");
}

RenderSystem* Window::GetEngine()
{
    return &RenderEngine;
};