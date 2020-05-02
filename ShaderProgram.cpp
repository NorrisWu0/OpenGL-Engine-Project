#include "ShaderProgram.h"
#include "shader.h"

#include <stdexcept>

ShaderProgram::ShaderProgram(const char* id, const Shader* vertex_shader, const Shader* fragment_shader)
	: Asset(id)
{
	_program = glCreateProgram();
	glAttachShader(_program, vertex_shader->data());
	glAttachShader(_program, fragment_shader->data());
	glLinkProgram(_program);

	GLint shader_program_linking_result;
	glGetProgramiv(_program, GL_LINK_STATUS, &shader_program_linking_result);
	if(shader_program_linking_result == GL_FALSE)
	{
		GLchar info[1024];
		glGetProgramInfoLog(_program, sizeof(info), NULL, info);
		throw std::runtime_error(info);
	}

	glGenVertexArrays(1, &_vao);
}

ShaderProgram::~ShaderProgram()
{
}

const GLuint ShaderProgram::program() const
{
	return _program;
}

const GLuint ShaderProgram::vao() const
{
	return _vao;
}