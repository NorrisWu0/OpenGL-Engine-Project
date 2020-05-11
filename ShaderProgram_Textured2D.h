#pragma once

#include "ShaderProgram.h"
#include "Texture.h"

#include <glm/mat4x4.hpp>

#include <vector>

class Mesh;
struct Configuration;

class ShaderProgram_Textured2D : public ShaderProgram
{
public:
	ShaderProgram_Textured2D(const Shader* _vertexShader, const Shader* _fragmentShader);
	~ShaderProgram_Textured2D();

	void Render(const Configuration* _config, const Mesh* _mesh, const Texture* _texture, const glm::mat4* _transformation) const;
};