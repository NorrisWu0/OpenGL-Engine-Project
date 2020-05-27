#pragma once
#include "Floor.h"


Floor::Floor(const char* _id) : GameObject(_id)
{
	m_Position = glm::vec3(0, -1.8, 0);
	m_Scale = glm::vec3(10, 1.25, 1);
}

Floor::~Floor() {}

void Floor::SimulateAI(const double, const Assets*, const Scene*, const Configuration*, const Input*) {}

void Floor::Render(const double, const Assets* m_Assets, const Scene* _scene, const Configuration* _config)
{
	std::vector<GLfloat> _colors =
	{
		RTF(140), RTF(140), RTF(140), 1.0f,
		RTF(140), RTF(140), RTF(140), 1.0f,
		RTF(140), RTF(140), RTF(140), 1.0f,
		RTF(140), RTF(140), RTF(140), 1.0f,
		RTF(140), RTF(140), RTF(140), 1.0f,
		RTF(140), RTF(140), RTF(140), 1.0f,
	};
	
	const ShaderProgram_Colored2D* _program = (ShaderProgram_Colored2D*)m_Assets->GetAsset("ShaderProgram.2D.Colored");
	const Mesh* _mesh = (Mesh*)m_Assets->GetAsset("Mesh.Square");
	glm::mat4 _trans = Transformation(_scene, _config);

	_program->Render(_config, _mesh, &_colors, &_trans);
}
