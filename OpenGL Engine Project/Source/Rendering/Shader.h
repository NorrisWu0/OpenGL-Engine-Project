#pragma once
#include <glew.h>
#include <string>
#include <fstream>

#include "Utilities/Expectations.h"
#include "Utilities/Asset.h"


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