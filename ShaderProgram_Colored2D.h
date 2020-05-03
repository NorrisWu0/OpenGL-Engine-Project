#pragma once
#include "ShaderProgram.h"

#include <glm/gtx/transform.hpp>

#include <vector>

class Mesh;
struct Configuration;

class ShaderProgram_Colored2D : public ShaderProgram
{
public:
	ShaderProgram_Colored2D(const Shader* _vertexShader, const Shader* _fragmentShader);
	~ShaderProgram_Colored2D();

	void Render(const Configuration* , const Mesh* , const std::vector<GLfloat>* _colors, const glm::mat4* _transformation) const;
};