#pragma once
#include <glm/gtx/transform.hpp>
#include <vector>

#include "Expectations.h"
#include "ShaderProgram.h"
#include "Configuration.h"
#include "Mesh.h"

class Mesh;
struct Configuration;


class ShaderProgram_Colored2D : public ShaderProgram
{
public:
	ShaderProgram_Colored2D(const Shader* _vertex, const Shader* _fragment);
	~ShaderProgram_Colored2D();

	void Render(const Configuration* _config, const Mesh* _mesh, const std::vector<GLfloat>* _colors, const glm::mat4* _transformation) const;
};