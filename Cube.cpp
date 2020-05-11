#pragma once
#include "Cube.h"
#include "ShaderProgram_Textured3D.h"
#include "Assets.h"

#define GLEW_STATIC
#include <math.h>

Cube::Cube(const char* _id) : GameObject(_id)
{
}

Cube::~Cube()
{
}

void Cube::SimulateAI(const double, const Assets*, const Scene*, const Configuration*, const Input*)
{
}

void Cube::Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config)
{
	static double _totalTime = 0;
	_totalTime += _deltaTime;

	const ShaderProgram_Textured3D* _program = (ShaderProgram_Textured3D*)_assets->GetAsset("ShaderProgram.3D.Textured");
	const Texture* _texture = (Texture*)_assets->GetAsset("Texture.SecureServ2");

	const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.Cube");
	glm::mat4 _trans = Transformation(_scene, _config);

	_program->Render(_config, _mesh, _texture, &_trans);

}
