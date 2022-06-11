


#ifndef UI_IMAGE_H
#define UI_IMAGE_H
#include "render/UI/Objects/UI.h"
#include <string>
class UI_Image : public UI
{
private:
	float M_vertices[9] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};
	unsigned int M_indices[6] = {  // note that we start from 0!
		   0, 1, 3,  // first Triangle
		   1, 2, 3   // second Triangle
	};
	unsigned int M_VBO, M_VAO, M_EBO;
	const char* M_vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	const char* M_fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";
	unsigned int M_vertexShader;
	unsigned int M_fragmentShader;
	unsigned int M_shaderProgram;


	bool Is_Created = false;
public:
	std::string obj_name;
	int x_pos = 0;
	int y_pos = 0;
	int obj_width = 0;
	int obj_height = 0;
	bool Visible = true;
	int Create(int xPos, int yPos, int width, int height, std::string name, std::string image_path);
	int CompileShaders();
	int BindProgram();
	int Render();
};
#endif
