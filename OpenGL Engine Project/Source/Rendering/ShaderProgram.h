#pragma once
#include <glew.h>
#include <stdexcept>
#include <string>

#include "Utilities/Asset.h"
#include "Rendering/Shader.h"

class Shader;


class ShaderProgram : public Asset
{
public:
	ShaderProgram(const char* _id, const Shader* _vertex, const Shader* _fragment);
	~ShaderProgram();

	const GLuint GetProgram() const;
	const GLuint GetVAO()     const;

private:
	GLuint m_Program;
	GLuint m_VAO;
};