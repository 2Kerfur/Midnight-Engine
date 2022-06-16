#include <filesystem>
namespace fs = std::filesystem;

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#ifdef _WIN32 //TODO: Linux implementation for get dir
#include <Windows.h>
std::string GetCurrentDirectory()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");

	return std::string(buffer).substr(0, pos);
}
#endif

#include "RenderSystem.h"
#include "glad/glad.h"
#include "utils/log.h"

#include "GLFW/glfw3.h"
#include "glm/glm.hpp" //math
#include "stb/stb_image.h"

//camera test
#include "Camera.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Texture.h"
#include"Shader.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

#include <iostream>
#include <stdio.h>

#include "freetype/ft2build.h" //TODO: Text rendering implementation
#include FT_FREETYPE_H


// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f
};
std::string vertexCode =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"layout (location = 2) in vec2 aTex;\n"
"out vec3 color;\n"
"out vec2 texCoord;\n"
"uniform mat4 camMatrix;\n"
"void main()\n"
"{\n"
"   gl_Position = camMatrix * vec4(aPos, 1.0);\n"
"   color = aColor;\n"
"   texCoord = aTex;\n"
"}\0";
std::string fragmentCode =
"#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 color;\n"
"in vec2 texCoord;\n"
"uniform sampler2D tex0;\n"
"void main()\n"
"{\n"
"   FragColor = texture(tex0, texCoord);\n"
"}\0";
// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
};

int RenderSystem::Init(int width, int height, GLFWwindow* window)
{
	Render_width = width;
	Render_height = height;
	if (!gladLoadGL())
	{
		
		RENDER_LOG_CRITICAL("Glad OpenGL loading error");
		return 1;
	}
	else
	{
		RENDER_LOG_INFO("Glad OpenGL loaded successfully");
		const GLubyte* render_card = glGetString(GL_RENDERER); //get render card info
		const char* card = reinterpret_cast<const char*>(render_card); //convert it to char
		std::string card_render = card; //convert to string
		RENDER_LOG_INFO("Graphics card model: " + card_render);
		Render_loaded = true;
		glViewport(0, 0, width, height);
		return 0;
	}
	
}
int RenderSystem::CompileShaders()
{
	
	shaderProgram.Create(vertexCode, fragmentCode);
	// Generates Vertex Array Object and binds it
	
	VAO1.Create();
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO1.Create(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO1.Create(indices, sizeof(indices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	//brickTex.Create((parentDir + texPath + "brick.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.Create("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);

	// Creates camera object
	camera.Create(Render_width, Render_height, glm::vec3(0.0f, 0.0f, 2.0f));

	for (int i = 0; Render_UI_Images_count > i; i++)
	{
		if (Render_UI_images[i]->Visible == true)
		{
			Render_UI_images[i]->CompileShaders();
		}
	}
	Shaders_compiled = true;
	
	return 0;
}

void RenderSystem::SetRenderSize(int width, int height)
{
	Render_width = width;
	Render_height = height;
	glViewport(0, 0, width, height);
}
int RenderSystem::AddGameObject(UI_Image* ui_image)
{
	Render_UI_images[Render_UI_Images_count] = ui_image;
	Render_UI_Images_count += 1;
	//CompileShaders(); //TODO: remove this shit
    //obj[Obj_count] = gameObject;
    //Obj_count += 1;
	return 0;
}
float Transp;
void RenderSystem::Render(GLFWwindow* window)
{
	
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//IMGUI
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	ImGui::Begin("Engine Stat");
	
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	Render_UI_images[0]->SetTransparency(Transp);
	ImGui::SliderFloat("float", &Transp, 0.0f, 1.0f);
	ImGui::End();
	//IMGUI


	//LOG_INFO("Screen cleared");
	shaderProgram.Activate();
	camera.Inputs(window);

	camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

	//Binds texture so that is appears in rendering
	brickTex.Bind();
	// Bind the VAO so OpenGL knows to use it
	VAO1.Bind();
	// Draw primitives, number of indices, datatype of indices, index of indices
	glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

	

	for (int i = 0; Render_UI_Images_count > i; i++)
	{
		if (Render_UI_images[i]->Is_Created)
		{
			if (Render_UI_images[i]->Visible)
			{
				Render_UI_images[i]->BindProgram();
				Render_UI_images[i]->Render();
			}
		}
	}

	//IMGUI
	
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	//IMGUI
}
