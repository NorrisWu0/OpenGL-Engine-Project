#pragma once
#include <glm/mat4x4.hpp>
#include <vector>

#include "Expectations.h"
#include "ShaderProgram.h"
#include "Configuration.h"
#include "Mesh.h"

class Mesh;
struct Configuration;


class ShaderProgram_Colored3D : public ShaderProgram
{
public:
	ShaderProgram_Colored3D(const Shader* _vertex, const Shader* _fragment);
	~ShaderProgram_Colored3D();

	void Render(const Configuration* _config, const Mesh* _mesh, const std::vector<GLfloat>* _colors, const glm::mat4* _transformation) const;
};

