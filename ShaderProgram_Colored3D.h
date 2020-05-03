#pragma once
#include "ShaderProgram.h"

#include <glm/mat4x4.hpp>

#include <vector>

class Mesh;
struct Configuration;

class ShaderProgram_Colored3D : public ShaderProgram
{
public:
	ShaderProgram_Colored3D(const Shader* _vertexShader, const Shader* _fragmentShader);
	~ShaderProgram_Colored3D();

	void Render(const Configuration*, const Mesh*, const std::vector<GLfloat>* _colors, const glm::mat4* _transformation) const;
};

