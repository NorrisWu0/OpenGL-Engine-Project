#pragma once
#include "Bunker.h"


Bunker::Bunker(const char* _id)	: GameObject(_id)
{
	m_Position = glm::vec3(0, -1.25, 0);
	m_Scale = glm::vec3(1.5, 1.5, 1);
}

Bunker::~Bunker() {}

void Bunker::SimulateAI(const double, const Assets*, const Scene*, const Configuration*, const Input*) {}

void Bunker::Render(const double, const Assets* _assets, const Scene* _scene, const Configuration* _config)
{
	std::vector<GLfloat> _colors = {
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
		RTF(66), RTF(66), RTF(66), 1.0f,
	};

	const ShaderProgram_Colored2D* _program = (ShaderProgram_Colored2D*)_assets->GetAsset("ShaderProgram.2D.Colored");
	const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.Bunker");
	glm::mat4 _trans = Transformation(_scene, _config);

	_program->Render(_config, _mesh, &_colors, &_trans);
}
