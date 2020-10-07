#pragma once
#include <glm/gtx/transform.hpp>
#include <vector>

#include "Utilities/Expectations.h"
#include "Rendering/ShaderProgram.h"
#include "Utilities/Configuration.h"
#include "Mesh/Mesh.h"

class Mesh;


class ShaderProgram_Colored2D : public ShaderProgram
{
public:
	ShaderProgram_Colored2D(const Shader* _vertex, const Shader* _fragment);
	~ShaderProgram_Colored2D();

	void Render(const Configuration* _config, const Mesh* _mesh, const std::vector<GLfloat>* _colors, const glm::mat4* _transformation) const;
};