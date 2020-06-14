#pragma once
#include "Cube.h"


Cube::Cube(const char* _id) : GameObject(_id) {}
Cube::~Cube() {}

void Cube::SimulateAI(const double, const Assets*, const Scene*, const Configuration*, const Input*) {}

void Cube::Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config)
{
	m_TotalTime += _deltaTime / 3;
	m_Rotation.x = (float)m_TotalTime;

	m_Position.x = sinf((float)m_TotalTime * 2) * 4;

	const ShaderProgram_Textured3D* _program = (ShaderProgram_Textured3D*)_assets->GetAsset("ShaderProgram.3D.Textured");
	const Texture* _texture = (Texture*)_assets->GetAsset("Texture.SecureServ2");

	const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.Cube");

	_program->Render(_config, _mesh, _texture, Translation(), Rotation(), Scale(), Camera(_scene, _config), Projection(_scene, _config));

}
