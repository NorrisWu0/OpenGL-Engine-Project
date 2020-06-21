#pragma once
#include "Cube.h"


Cube::Cube(const char* _id) : GameObject(_id) 
{
	SetPosition(glm::vec3((float)(rand() % 20 - 10), (float)(rand() % 20 - 10), (float)(rand() % 20 - 10)));
}

Cube::~Cube() {}

void Cube::SimulateAI(const double _deltaTime, const Assets*, const Scene*, const Configuration*, const Input*)
{
	glm::vec3 _cubeRotation{ (float)_deltaTime / 4 , (float)_deltaTime / 4 , (float)_deltaTime / 4 };

	m_Rotation += _cubeRotation;
}

void Cube::Render(const double , const Assets* _assets, const Scene* _scene, const Configuration* _config)
{

	const ShaderProgram_Textured3D* _program = (ShaderProgram_Textured3D*)_assets->GetAsset("ShaderProgram.3D.Textured");
	const Texture* _texture = (Texture*)_assets->GetAsset("Texture.GridBox");

	const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.Cube");

	_program->Render(_config, _mesh, _texture, Translation(), Rotation(), Scale(), Camera(_scene, _config), Projection(_scene, _config));

}
