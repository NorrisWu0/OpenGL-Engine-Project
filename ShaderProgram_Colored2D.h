#pragma once

#include "ShaderProgram.h"

#include <vector>
#include <glm/gtx/transform.hpp>

class Mesh;
struct Configuration;

class ShaderProgram_Colored2D : public ShaderProgram
{
public:
	ShaderProgram_Colored2D(const Shader* vertex_shader, const Shader* fragment_shader);
	~ShaderProgram_Colored2D();

	void Render(const Configuration* config, const Mesh* mesh, const std::vector<GLfloat>* colors, const glm::mat4* Transformation) const;
};