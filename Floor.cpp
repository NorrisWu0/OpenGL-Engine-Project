#pragma once

#include "Floor.h"
#include "colored_2D_shader_program.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>
#include <vector>
#include <math.h>


Floor::Floor(const char* _id) : GameObject(_id)
{
	position = glm::vec3(0, -1.8, 0);
	scale = glm::vec3(10, 1.25, 1);
}

Floor::~Floor()
{
}

void Floor::SimulateAI(const double, const Assets*, const Scene*, const Configuration*)
{
}

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
	
	const Colored_2D_Shader_Program* _program = (Colored_2D_Shader_Program*)m_Assets->GetAsset("ShaderProgram.2D.Colored");
	const Mesh* _mesh = (Mesh*)m_Assets->GetAsset("Mesh.Square");
	glm::mat4 _trans = Transformation(_scene, _config);

	_program->Render(_config, _mesh, &_colors, &_trans);
}
