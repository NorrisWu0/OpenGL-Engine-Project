#pragma once
#include <glm/mat4x4.hpp>
#include <vector>

#include "Expectations.h"
#include "ShaderProgram.h"
#include "Configuration.h"
#include "Mesh.h"
#include "Texture.h"

class Mesh;


class ShaderProgram_Textured3D : public ShaderProgram
{
public:
	ShaderProgram_Textured3D(const Shader* _vertex, const Shader* _fragment);
	~ShaderProgram_Textured3D();

	void Render(const Configuration* _config, const Mesh* _mesh, const Texture* _texture,
				const glm::mat4 _translation, 
				const glm::mat4 _rotation,
				const glm::mat4 _scale,
				const glm::mat4 _camera,
				const glm::mat4 projection) const;
};

