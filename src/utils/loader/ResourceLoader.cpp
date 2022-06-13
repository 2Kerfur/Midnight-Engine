#include "ResourceLoader.h"
#include<stb/stb_image.h>
#include "utils/log.h"
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

std::string LoadShader(std::string path)
{
	std::string Shader;



	return Shader;
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
