#pragma once
#include "Grass.h"


Grass::Grass(const char* _id) : GameObject(_id) {}

Grass::~Grass() {}

void Grass::SimulateAI(const double, const Assets*, const Scene*, const Configuration*, const Input*) {}

void Grass::Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config)
{
	m_TotalTime += _deltaTime;
	m_Rotation.z = (float)m_TotalTime;

	const ShaderProgram_Textured3D* _program = (ShaderProgram_Textured3D*)_assets->GetAsset("ShaderProgram.3D.Textured");
	const Texture* _texture = (Texture*)_assets->GetAsset("Texture.MCGrass");

	const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.Cube");

	_program->Render(_config, _mesh, _texture, Translation(), Rotation(), Scale(), Camera(_scene, _config), Projection(_scene, _config));

}
