#include "blocky_boy.h"
#include "colored_2D_shader_program.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>
#include <vector>
#include <math.h>

Blocky_Boy::Blocky_Boy(const char* id)
	: Game_Object(id)
{
	position = glm::vec3(-0.5, -0.5, 0);

	totalTime = 0;
}

Blocky_Boy::~Blocky_Boy()
{
}

void Blocky_Boy::SimulateAI(const double, const Assets*, const Scene*, const Configuration*)
{
}

void Blocky_Boy::Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config)
{
	totalTime += _deltaTime;

	position = glm::vec3(cos(totalTime), sin(totalTime), 0);

	std::vector<GLfloat> _colors =
	{
		RTF(227), RTF(238), RTF(255), 1.0f,
		RTF(227), RTF(238), RTF(255), 1.0f,
		RTF(227), RTF(238), RTF(255), 1.0f,
		RTF(227), RTF(238), RTF(255), 1.0f,
		RTF(227), RTF(238), RTF(255), 1.0f,
		RTF(227), RTF(238), RTF(255), 1.0f,
	};
	
	const Colored_2D_Shader_Program* _program = (Colored_2D_Shader_Program*)_assets->get_asset("Shader_Program.2D.Colored");
	const Mesh* _mesh = (Mesh*)_assets->get_asset("Mesh.Square");
	glm::mat4 _trans = Transformation(_scene, _config);

	_program->Render(_config, _mesh, &_colors, &_trans);
}
