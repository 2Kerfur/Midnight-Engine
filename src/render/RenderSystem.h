#ifndef RENDERSYSTEM
#define RENDERSYSTEM
    #include "Shader.h"
    #include "GameObject.h"
    #include "GLFW/glfw3.h"
#include "Shader.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Camera.h"
#include "Texture.h"
#endif

class RenderSystem
{
private:
    bool Render_loaded = false;
    int Render_width = 100;
    int Render_height = 100;
    //Shader ourShader;
    GLFWwindow* render_window;
    
    GameObject* obj[100];
    int Obj_count = 0;

    //rendering objects
    Camera camera;
    VAO VAO1;
    VBO VBO1;
    EBO EBO1;
    Shader shaderProgram;
    Texture brickTex;
public:
    int Init(int width, int height, GLFWwindow* window);

    int CompileShaders();
    
    void SetRenderSize(int width, int height);

    int Add_Object(GameObject *gameObject);
    int Render();
};