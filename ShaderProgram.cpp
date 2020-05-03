#include "ShaderProgram.h"
#include "shader.h"

#include <stdexcept>

ShaderProgram::ShaderProgram(const char* id, const Shader* vertex_shader, const Shader* fragment_shader)
	: Asset(id)
{
	m_Program = glCreateProgram();
	glAttachShader(m_Program, vertex_shader->data());
	glAttachShader(m_Program, fragment_shader->data());
	glLinkProgram(m_Program);

	GLint shader_program_linking_result;
	glGetProgramiv(m_Program, GL_LINK_STATUS, &shader_program_linking_result);
	if(shader_program_linking_result == GL_FALSE)
	{
		GLchar info[1024];
		glGetProgramInfoLog(m_Program, sizeof(info), NULL, info);
		throw std::runtime_error(info);
	}

	glGenVertexArrays(1, &m_VAO);
}

ShaderProgram::~ShaderProgram()
{
}

const GLuint ShaderProgram::GetProgram() const
{
	return m_Program;
}

const GLuint ShaderProgram::GetVAO() const
{
	return m_VAO;
}