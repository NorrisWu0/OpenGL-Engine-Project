#pragma once
#include "Cube.h"
#include "ShaderProgram_Colored3D.h"
#include "assets.h"

#define GLEW_STATIC
#include <math.h>

Cube::Cube(const char* _id) : GameObject(_id)
{
}

Cube::~Cube()
{
}

void Cube::SimulateAI(const double, const Assets*, const Scene*, const Configuration*)
{
}

void Cube::Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config)
{
	static double _totalTime = 0;
	_totalTime += _deltaTime;

	m_Rotation.x = -(float)_totalTime;
	m_Rotation.y = -(float)_totalTime / 4;

	std::vector<GLfloat> _colors;
	
	auto _red = {1.f, 0.f, 0.f, 1.f};
	auto _green = {0.f, 1.f, 0.f, 1.f};
	auto _blue = {0.f, 0.f, 1.f, 1.f};
	auto _white = {1.f, 1.f, 1.f, 1.f};

	_colors.insert(_colors.end(), _blue);
	_colors.insert(_colors.end(), _blue);
	_colors.insert(_colors.end(), _blue);
	_colors.insert(_colors.end(), _blue);
	_colors.insert(_colors.end(), _blue);
	_colors.insert(_colors.end(), _blue);

	_colors.insert(_colors.end(), _red);
	_colors.insert(_colors.end(), _red);
	_colors.insert(_colors.end(), _red);
	_colors.insert(_colors.end(), _red);
	_colors.insert(_colors.end(), _red);
	_colors.insert(_colors.end(), _red);

	_colors.insert(_colors.end(), _blue);
	_colors.insert(_colors.end(), _blue);
	_colors.insert(_colors.end(), _blue);
	_colors.insert(_colors.end(), _blue);
	_colors.insert(_colors.end(), _blue);
	_colors.insert(_colors.end(), _blue);

	_colors.insert(_colors.end(), _red);
	_colors.insert(_colors.end(), _red);
	_colors.insert(_colors.end(), _red);
	_colors.insert(_colors.end(), _red);
	_colors.insert(_colors.end(), _red);
	_colors.insert(_colors.end(), _red);

	_colors.insert(_colors.end(), _green);
	_colors.insert(_colors.end(), _green);
	_colors.insert(_colors.end(), _green);
	_colors.insert(_colors.end(), _green);
	_colors.insert(_colors.end(), _green);
	_colors.insert(_colors.end(), _green);

	_colors.insert(_colors.end(), _green);
	_colors.insert(_colors.end(), _green);
	_colors.insert(_colors.end(), _green);
	_colors.insert(_colors.end(), _green);
	_colors.insert(_colors.end(), _green);
	_colors.insert(_colors.end(), _green);


	const ShaderProgram_Colored3D* _program = (ShaderProgram_Colored3D*)_assets->GetAsset("ShaderProgram.3D.Colored");
	const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.Cube");
	glm::mat4 _trans = Transformation(_scene, _config);

	_program->Render(_config, _mesh, &_colors, &_trans);

}
