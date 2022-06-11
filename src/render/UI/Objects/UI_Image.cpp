#include "UI_Image.h"
#include "utils/log.h"
#include "glad/glad.h"


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
	glDisable(GL_DEPTH_TEST);
	//-------------
	M_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(M_vertexShader, 1, &M_vertexShaderSource, NULL);
	glCompileShader(M_vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(M_vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(M_vertexShader, 512, NULL, infoLog);
	}

	M_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(M_fragmentShader, 1, &M_fragmentShaderSource, NULL);
	glCompileShader(M_fragmentShader);
	glGetShaderiv(M_fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(M_fragmentShader, 512, NULL, infoLog);
	}
	M_shaderProgram = glCreateProgram();
	glAttachShader(M_shaderProgram, M_vertexShader);
	glAttachShader(M_shaderProgram, M_fragmentShader);
	glLinkProgram(M_shaderProgram);
	glGetProgramiv(M_shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(M_shaderProgram, 512, NULL, infoLog);
	}
	glDeleteShader(M_vertexShader);
	glDeleteShader(M_fragmentShader);
	
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	////-------------
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
	return 0;
}

int UI_Image::Render()
{
	if (Is_Created)
	{
		//-------
		
		//-------
		glUseProgram(M_shaderProgram);
		glBindVertexArray(M_VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		LOG_INFO("Image rendering");
	}
	else
	{
		LOG_ERROR("Object: " + obj_name + " was not created"); 
	}
	return 0;
}
