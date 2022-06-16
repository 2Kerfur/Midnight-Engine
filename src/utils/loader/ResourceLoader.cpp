#include "ResourceLoader.h"
#include<stb/stb_image.h>
#include "utils/log.h"
#include <fstream>
#include <filesystem>

#ifdef _WIN32 //TODO: Linux implementation for get dir
#include <Windows.h>
std::string GetCurrentDir()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");

	return std::string(buffer).substr(0, pos);
}
#endif

std::string LoadShader(std::string path) //TODO: Create linux implementation
{
	std::string Shader;
	std::string finalPath;
	std::string parentDir = GetCurrentDir();
	std::replace(parentDir.begin(), parentDir.end(), '\\', '/');
	std::string texPath = "/resources/shaders/";
	finalPath = (parentDir + texPath + path);

	std::string file_content;
	std::getline(std::ifstream(finalPath), file_content, '\0');
	
	return file_content;
}

//LoadFiles in /resources/images/textures/ dir 
unsigned char* LoadTexture(std::string path, 
	int *width, int *height, int *numColch)
{
	std::string finalPath;
	std::string parentDir = GetCurrentDir();
	std::replace(parentDir.begin(), parentDir.end(), '\\', '/');
	std::string texPath = "/resources/images/textures/";
	finalPath = (parentDir + texPath + path);

	const char* image = finalPath.c_str();
	unsigned char* bytes;
	stbi_set_flip_vertically_on_load(true);
	bytes = stbi_load(image, width, height, numColch, 0);
	return bytes;
}
