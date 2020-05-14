#pragma once

#include <string>

#define GLEW_STATIC
#include <glew.h>

#include "Asset.h"

class Shader : public Asset
{
public:
	enum class Type
	{
		Vertex,
		Fragment
	};

	Shader(const char* _id, const char* _filePath, const Type type);
	~Shader();

	const GLuint data() const;

private:
	GLuint _data;
};