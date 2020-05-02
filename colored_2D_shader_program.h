#pragma once

#include "ShaderProgram.h"

#include <vector>
#include <glm/gtx/transform.hpp>

class Mesh;
struct Configuration;

class Colored_2D_Shader_Program : public ShaderProgram
{
public:
	Colored_2D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader);
	~Colored_2D_Shader_Program();

	void Render(const Configuration* config, const Mesh* mesh, const std::vector<GLfloat>* colors, const glm::mat4* Transformation) const;
};