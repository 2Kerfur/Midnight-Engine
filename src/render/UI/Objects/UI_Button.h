#ifndef UI_BUTTON_H
#define UI_BUTTON_H
#include "render/UI/Objects/UI.h"
#include "render/Shader.h"
#include <string>

#include"render/VAO.h"
#include"render/VBO.h"
#include"render/EBO.h"

#include "GLFW/glfw3.h"

class UI_Button : public UI
{
private:
	
	float M_vertices[32] = {
		// positions          // colors           // texture coords
		 0.0f,  1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		-0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	};
	unsigned int M_indices[6] = {  // note that we start from 0!
		   0, 1, 3,  // first Triangle
		   1, 2, 3   // second Triangle
	};
	int window_width, window_height;
	int key; //glfw key
	VAO VAO1;
	VBO VBO1;
	EBO EBO1;
	Shader shaderProg;
	GLFWwindow* window;
	unsigned int texture1;

	float GetXPos(float x_position);
	float GetYPos(float x_position);


	unsigned int M_VBO, M_VAO, M_EBO;
	unsigned int M_vertexShader;
	unsigned int M_fragmentShader;
	unsigned int M_shaderProgram;
	float Transparency;
	void(*Button_pressed_callback)(char button);
	void ListenInput();
public:
	
	bool Is_Created = false;
	std::string obj_name;
	int x_pos = 0;
	int y_pos = 0;
	int obj_width = 0;
	int obj_height = 0;
	bool Visible = true;
	int Create(int xPos, int yPos, int width, int height, std::string name, std::string image_path, GLFWwindow* glfw_window);
	void SetPos(float x, float y);
	int CompileShaders();
	void UpdateSize(int width, int height);
	int BindProgram();
	int Render();
	void SetTransparency(float value);
	void SetListener(void (*func)(char pressed));
};

#endif