#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char* _id, const Shader* _vertex, const Shader* _fragment)
	: Asset(_id)
{
	m_Program = glCreateProgram();
	glAttachShader(m_Program, _vertex->data());
	glAttachShader(m_Program, _fragment->data());
	glLinkProgram(m_Program);

	GLint _programLinkingResult;
	glGetProgramiv(m_Program, GL_LINK_STATUS, &_programLinkingResult);
	if(_programLinkingResult == GL_FALSE)
	{
		GLchar info[1024];
		glGetProgramInfoLog(m_Program, sizeof(info), NULL, info);
		throw std::runtime_error(info);
	}

	glGenVertexArrays(1, &m_VAO);
}

ShaderProgram::~ShaderProgram() {}
const GLuint ShaderProgram::GetProgram() const { return m_Program; }
const GLuint ShaderProgram::GetVAO() const { return m_VAO; }