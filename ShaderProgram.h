#pragma once

#include <string>

#define GLEW_STATIC
#include <glew.h>

#include "asset.h"

class Shader;

class ShaderProgram : public Asset
{
public:
	ShaderProgram(const char* id, const Shader* vertex_shader, const Shader* fragment_shader);
	~ShaderProgram();

	const GLuint program() const;
	const GLuint vao()     const;

private:
	GLuint _program;
	GLuint _vao;
};