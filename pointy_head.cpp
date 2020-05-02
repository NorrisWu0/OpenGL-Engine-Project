#include "pointy_head.h"
#include "ShaderProgram_Colored2D.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>
#include <vector>
#include <math.h>

Pointy_Head::Pointy_Head(const char* id)
	: GameObject(id)
{
	m_Position = glm::vec3(3, 1, 0);
	m_Scale = glm::vec3(0.5, 0.5, 0.5);
	totalTime = 0;
}

Pointy_Head::~Pointy_Head()
{

}

void Pointy_Head::SimulateAI(const double, const Assets*, const Scene*, const Configuration*)
{

}

void Pointy_Head::Render(const double _deltaTime, const Assets* assets, const Scene* scene, const Configuration* config)
{
	totalTime += _deltaTime / 2;
	m_Rotation = glm::vec3(0, 0, totalTime);

	std::vector<GLfloat> _colors =
	{
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
		RTF(192), RTF(230), RTF(237), 1.0f,
	};
	
	const ShaderProgram_Colored2D* _program = (ShaderProgram_Colored2D*)assets->GetAsset("ShaderProgram.2D.Colored");
	const Mesh* _mesh = (Mesh*)assets->GetAsset("Mesh.Octagon");
	glm::mat4 _trans = Transformation(scene, config);

	_program->Render(config, _mesh, &_colors, &_trans);
}