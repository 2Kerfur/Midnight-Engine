#include <filesystem>
namespace fs = std::filesystem;

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


// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f
};

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
		LOG_CRITICAL("Glad OpenGL loading error");
		return -1;
	}
	else
	{
		LOG_INFO("Glad OpenGL loaded successfully");
		Render_loaded = true;
		return 0;
	}
    render_window = window;
	glViewport(0, 0, width, height);
}

int RenderSystem::CompileShaders() //TODO: Fix image color from black & white to colorfull
{
	shaderProgram.Create("default.vert", "default.frag");
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

	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	//std::string texPath = "/resources/images/textures/";
	LOG_INFO(parentDir);
	// Texture
	//brickTex.Create((parentDir + texPath + "brick.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.Create((parentDir + "brick.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);
	glEnable(GL_DEPTH_TEST);

	// Creates camera object
	camera.Create(Render_width, Render_height, glm::vec3(0.0f, 0.0f, 2.0f));
	Shaders_compiled = true;
	return 0;
}

void RenderSystem::SetRenderSize(int width, int height)
{
	Render_width = width;
	Render_height = height;
	glViewport(0, 0, width, height);
}
int RenderSystem::Add_Object(GameObject *gameObject)
{
    //obj[Obj_count] = gameObject;
    //Obj_count += 1;
	return 0;
}

void RenderSystem::Render()
{
	if (Render_loaded && Shaders_compiled)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//LOG_INFO("Screen cleared");
		shaderProgram.Activate();

		// Handles camera inputs
		//camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

		// Binds texture so that is appears in rendering
		brickTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
		// Swap the back buffer with he front buffer
	}
    
}
