#include "UI_Image.h"
#include "utils/log.h"
#include "glad/glad.h"
#include "render/Shader.h"
#include <iostream>



int UI_Image::Create(int xPos, int yPos, 
	int width, int height,
	std::string name, std::string image_path)
{

	x_pos = xPos;
	y_pos = yPos;
	obj_width = width;
	obj_height = height;
	obj_name = name;

	//-------------

	////-------------

	Is_Created = true;
	return 0;
}

int UI_Image::CompileShaders()
{
	shaderProg.Create(vertexCode, fragmentCode);
	return 0;
}

int UI_Image::BindProgram()
{
	glGenVertexArrays(1, &M_VAO);
	glGenBuffers(1, &M_VBO);
	glGenBuffers(1, &M_EBO);
	glBindVertexArray(M_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, M_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(M_vertices), M_vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, M_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(M_indices), M_indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	return 0;
}

int UI_Image::Render()
{
	if (Is_Created)
	{
		glClear(GL_DEPTH_BUFFER_BIT);
		shaderProg.Activate();
		glBindVertexArray(M_VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		//Delete buffers
		glDeleteVertexArrays(1, &M_VAO);
		glDeleteBuffers(1, &M_VBO);
		glDeleteBuffers(1, &M_EBO);

		//std::string filename = __FILE__;
		//std::cout << __FILE__ << " Line = " << __LINE__ << std::endl;
	
	}
	else
	{
		
		LOG_ERROR("Object: " + obj_name + " was not created"); 
	}
	return 0;
}
