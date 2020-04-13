#include "pointy_head.h"
#include "colored_2D_shader_program.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>
#include <vector>
#include <math.h>

Pointy_Head::Pointy_Head(const char* id)
	: Game_Object(id)
{
	position = glm::vec3(0.5, 0.5, 0);
}

Pointy_Head::~Pointy_Head()
{
}

void Pointy_Head::SimulateAI(const double, const Assets*, const Scene*, const Configuration*)
{

}

void Pointy_Head::Render(const double, const Assets* assets, const Scene* scene, const Configuration* config)
{
	std::vector<GLfloat> _colors =
	{
		RTF(255), RTF(194), RTF(89), 1.0f,
		RTF(255), RTF(194), RTF(89), 1.0f,
		RTF(255), RTF(194), RTF(89), 1.0f,
	};
	
	const Colored_2D_Shader_Program* _program = (Colored_2D_Shader_Program*)assets->get_asset("Shader_Program.2D.Colored");
	const Mesh* _mesh = (Mesh*)assets->get_asset("Mesh.Triangle");
	glm::mat4 _trans = Transformation(scene, config);

	_program->Render(config, _mesh, &_colors, &_trans);
}