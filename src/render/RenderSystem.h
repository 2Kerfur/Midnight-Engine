#ifndef RENDERSYSTEM
#define RENDERSYSTEM
#include "Shader.h"
#include "GameObject.h"
#endif

class RenderSystem
{
private:
    bool Render_loaded = false;
    int Render_width = 100;
    int Render_height = 100;
    Shader ourShader;
    GameObject* obj[100];
    int Obj_count = 0;
public:

    int Init(int width, int height);

    int CompileShaders();
    
    void SetRenderSize(int width, int height);

    int Add_Object(GameObject *gameObject);
    int Render();
};