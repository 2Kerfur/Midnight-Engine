#include "UI_Image.h"
#include "utils/log.h"
#include "glad/glad.h"
#include "render/Shader.h"
#include <iostream>

#include "utils/loader/ResourceLoader.h"

int UI_Image::Create(int xPos, int yPos, 
	int width, int height,
	std::string name, std::string image_path)
{

	x_pos = xPos;
	y_pos = yPos;
	obj_width = width;
	obj_height = height;
	obj_name = name;

	Is_Created = true;
	return 0;
}
void UI_Image::SetPos(float x, float y)
{
	//M_vertices[0] = x;
	//M_vertices[1] = y;
}

void UI_Image::SetTransparency(float value)
{
	if (0 <= value <= 1)
	{
		Transparency = value;
		GLint nAlphaLocation = glGetUniformLocation(shaderProg.ID, "AlphaValue");
		glUniform1f(nAlphaLocation, Transparency);
	}
}

int UI_Image::CompileShaders()
{
	shaderProg.Create(
		LoadShader("default_ui.vert"),
		LoadShader("default_ui.frag"));
	return 0;
}

int UI_Image::BindProgram()
{
	//VAO1.Bind();
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
		glEnable(GL_BLEND); //to render transparent images
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glClear(GL_DEPTH_BUFFER_BIT);
		shaderProg.Activate();
		glBindVertexArray(M_VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		//Delete buffers
		glDeleteVertexArrays(1, &M_VAO);
		glDeleteBuffers(1, &M_VBO);
		glDeleteBuffers(1, &M_EBO);

		glDisable(GL_BLEND);
	}
	else
	{
		
		RENDER_LOG_ERROR("Object: " + obj_name + " was not created"); 
	}
	return 0;
}
