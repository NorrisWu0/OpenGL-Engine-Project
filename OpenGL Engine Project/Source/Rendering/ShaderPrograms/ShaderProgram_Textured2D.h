#pragma once
#include <glm/mat4x4.hpp>
#include <vector>

#include "Utilities/Expectations.h"
#include "Rendering/ShaderProgram.h"
#include "Utilities/Configuration.h"
#include "Mesh/Mesh.h"
#include "Mesh/Texture.h"

class Mesh;


class ShaderProgram_Textured2D : public ShaderProgram
{
public:
	ShaderProgram_Textured2D(const Shader* _vertex, const Shader* _fragment);
	~ShaderProgram_Textured2D();

	void Render(const Configuration* _config, const Mesh* _mesh, const Texture* _texture, const glm::mat4 _translation, const glm::mat4 _rotation, const glm::mat4 _scale, const glm::mat4 _camera, const glm::mat4 projection) const;
};