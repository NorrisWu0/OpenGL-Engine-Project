#pragma once
#include <glm/mat4x4.hpp>
#include <vector>

#include "Utilities/Expectations.h"
#include "Rendering/ShaderProgram.h"
#include "Utilities/Configuration.h"
#include "Mesh/Mesh.h"
#include "Mesh/Texture.h"

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

	void SetAmbientColor(glm::vec3 _color);
	void SetLightColor(glm::vec3 _color);

	private:
	glm::vec3 m_AmbientColor{ .2, 0.2, 0.2 };
	glm::vec3 m_LightColor{ 0.8, 0.8, 0.8 };
};

