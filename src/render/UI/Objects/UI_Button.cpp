#include "UI_Button.h"
#include "utils/log.h"
#include "glad/glad.h"
#include "render/Shader.h"

#include <iostream>
#include "stb/stb_image.h"
#include "utils/loader/ResourceLoader.h"
#include "GLFW/glfw3.h"


//void key_callback(GLFWwindow* window, int input_key, int scancode, int action, int mods)
//{
	//key = input_key;
	//double xpos, ypos;
	//int state = glfwGetKey(window, GLFW_MOUSE_BUTTON_1);
	//glfwGetCursorPos(window, &xpos, &ypos);
	//if ((x_pos < xpos) && (xpos < x_pos + obj_width))
	//{
	//	if ((y_pos < ypos) && (ypos < y_pos + obj_height))
	//	{
	//		if (state == GLFW_PRESS)
	//		{
	//			Button_pressed_callback('d');
	//		}
	//	}
	//}
//}
int UI_Button::Create(int xPos, int yPos,
	int width, int height,
	std::string name, std::string image_path,
	GLFWwindow* glfw_window)
{
	x_pos = xPos;
	y_pos = yPos;
	obj_width = width;
	obj_height = height;
	obj_name = name;
	window = glfw_window;

	//  4|----------------|1
	//	 |				  |
	//   |				  |
	//   |				  |
	//   | 				  |
	//   | 				  |
	//  3|----------------|2
	glfwGetWindowSize(window, &window_width, &window_height);
	//top right (1)
	M_vertices[0] = xPos; //x //TODO: working ui placement
	M_vertices[1]; //y

	//buttom right (2)
	M_vertices[8]; 
	M_vertices[9];

	//bottom left (3)
	M_vertices[16];
	M_vertices[17];

	//top left (4)
	M_vertices[24];
	M_vertices[25];

	//glfwSetKeyCallback(window, UI_Button::ListenInput());

	Is_Created = true;
	return 0;
}

void UI_Button::SetPos(float x, float y)
{

}

int UI_Button::CompileShaders()
{
	shaderProg.Create(
		LoadShader("default_ui.vert"),
		LoadShader("default_ui.frag"));
	//load texture
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	// The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
	unsigned char* data = stbi_load(
		"D:/DEV/MY_GITHUB/Midnight-Engine/build/Release/resources/images/textures/button.png", &width, &height, &nrChannels, 0);
	if (data)
	{
		//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	return 0;
}

int UI_Button::BindProgram()
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	return 0;
}

int UI_Button::Render(GLFWwindow* main_window)
{
	window = main_window;
	if (Is_Created)
	{
		glEnable(GL_BLEND); //to render transparent images
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glClear(GL_DEPTH_BUFFER_BIT);
		//
		shaderProg.Activate();
		glBindTexture(GL_TEXTURE_2D, texture1);
		glBindVertexArray(M_VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		//Delete buffers
		glDeleteVertexArrays(1, &M_VAO);
		glDeleteBuffers(1, &M_VBO);
		glDeleteBuffers(1, &M_EBO);
		ListenInput();
	}
	else
	{
		RENDER_LOG_ERROR("Object: " + obj_name + " was not created");
	}
	return 0;
}
void UI_Button::SetTransparency(float value)
{
	
	//if (0 <= value <= 1)
	//{
	//	Transparency = value;
	//	GLint nAlphaLocation = glGetUniformLocation(shaderProg.ID, "AlphaValue");
	//	glUniform1f(nAlphaLocation, Transparency);
	//}
}
void UI_Button::ListenInput()
{
	double xpos, ypos;
	int state = glfwGetKey(window, GLFW_MOUSE_BUTTON_1);
	glfwGetCursorPos(window, &xpos, &ypos);
	key = glfwGetMouseButton(window, key);

	if ((x_pos < xpos) && (xpos < x_pos + obj_width))
	{
		if ((y_pos < ypos) && (ypos < y_pos + obj_height))
		{
			if (key)
			{
				Button_pressed_callback('d');
			}
		}
	} 
}

void UI_Button::SetListener(void(*func)(char pressed))
{
	Button_pressed_callback = func;
}
