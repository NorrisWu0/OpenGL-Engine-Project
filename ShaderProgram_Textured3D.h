#pragma once

#include "ShaderProgram.h"
#include "Texture.h"

#include <glm/mat4x4.hpp>

#include <vector>

class Mesh;
struct Configuration;

class ShaderProgram_Textured3D : public ShaderProgram
{
public:
	ShaderProgram_Textured3D(const Shader* _vertexShader, const Shader* _fragmentShader);
	~ShaderProgram_Textured3D();

	void Render(const Configuration*, const Mesh*, const Texture*, const glm::mat4*) const;
};

