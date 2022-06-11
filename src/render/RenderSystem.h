#ifndef RENDERSYSTEM
#define RENDERSYSTEM
    #include "Shader.h"
    #include "render/UI/Objects/UI_Image.h"    
    //#include "GameObject.h"
    #include "GLFW/glfw3.h"
    
    #include "Shader.h"
    #include "VBO.h"
    #include "VAO.h"
    #include "EBO.h"
    #include "Camera.h"
    #include "Texture.h"
    
class RenderSystem
{
private:
    bool Render_loaded = false;
    bool Shaders_compiled = false;
    int Render_width = 500;
    int Render_height = 500;
    //Shader ourShader;
    GLFWwindow* render_window;
    
    /*GameObject* obj[100];
    int Obj_count = 0;*/

    //rendering objects
    Camera camera;
    VAO VAO1;
    VBO VBO1;
    EBO EBO1;
    Shader shaderProgram;
    Texture brickTex;

    //GameObjects to render
    UI_Image *Render_UI_images[100];
    int Render_UI_Images_count = 0;
public:
    
    int Init(int width, int height, GLFWwindow* window);

    int CompileShaders();
    
    void SetRenderSize(int width, int height);

    int AddGameObject(UI_Image *gameObject);
    
    void Render(GLFWwindow *window);
};

#endif