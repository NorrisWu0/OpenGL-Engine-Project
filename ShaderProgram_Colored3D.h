#pragma once
#include "ShaderProgram.h"

#include <glm/mat4x4.hpp>

#include <vector>

class Mesh;
struct Configuration;

class ShaderProgram_Colored3D : public ShaderProgram
{
public:
	ShaderProgram_Colored3D(const Shader* vertex_shader, const Shader* fragment_shader);
	~ShaderProgram_Colored3D();

	void Render(const Configuration* config, const Mesh* mesh, const std::vector<GLfloat>* colors, const glm::mat4* Transformation) const;
};

