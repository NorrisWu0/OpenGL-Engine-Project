#pragma once

#include "Bunker.h"
#include "colored_2D_shader_program.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>
#include <vector>
#include <math.h>

Bunker::Bunker(const char* _id)	: GameObject(_id)
{
	position = glm::vec3(0, -1.25, 0);
	scale = glm::vec3(1.5, 1.5, 1);
}

Bunker::~Bunker()
{
}

void Bunker::SimulateAI(const double, const Assets*, const Scene*, const Configuration*)
{
}

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

	const Colored_2D_Shader_Program* _program = (Colored_2D_Shader_Program*)_assets->get_asset("Shader_Program.2D.Colored");
	const Mesh* _mesh = (Mesh*)_assets->get_asset("Mesh.Bunker");
	glm::mat4 _trans = Transformation(_scene, _config);

	_program->Render(_config, _mesh, &_colors, &_trans);

}
