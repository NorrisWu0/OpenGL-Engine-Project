#pragma once
#include "Pyramid.h"
#include "ShaderProgram_Colored3D.h"
#include "ShaderProgram_Textured3D.h"
#include "Assets.h"

Pyramid::Pyramid(const char* _id) : GameObject(_id)
{
}

Pyramid::~Pyramid()
{
}

void Pyramid::SimulateAI(const double, const Assets*, const Scene*, const Configuration*, const Input*)
{
}

void Pyramid::Render(const double, const Assets* _assets, const Scene* _scene, const Configuration* _config)
{
	const ShaderProgram_Textured3D* _program = (ShaderProgram_Textured3D*)_assets->GetAsset("ShaderProgram.3D.Textured");
	const Texture* _texture = (Texture*)_assets->GetAsset("Texture.AllSeeingEye");

	const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.Tetrehedron");
	glm::mat4 _trans = Transformation(_scene, _config);

	_program->Render(_config, _mesh, _texture, &_trans);

}
