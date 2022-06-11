#ifndef RESOURCE_LOADER_H
#define RESOURCE_LOADER_H

#include <string>

std::string LoadShader(std::string path);

unsigned char* LoadTexture(std::string path, 
	int* width, int* height, int* numColch);

#endif