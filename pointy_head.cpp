#include "pointy_head.h"
#include "ShaderProgram_Colored2D.h"
#include "ShaderProgram_Textured2D.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>
#include <vector>
#include <math.h>

Pointy_Head::Pointy_Head(const char* id)
	: GameObject(id)
{
}

Pointy_Head::~Pointy_Head()
{

}

void Pointy_Head::SimulateAI(const double, const Assets*, const Scene*, const Configuration*, const Input*)
{

}

void Pointy_Head::Render(const double, const Assets* assets, const Scene* scene, const Configuration* config)
{
	/*std::vector<GLfloat> _colors =
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
	
	const ShaderProgram_Colored2D* _program = (ShaderProgram_Colored2D*)assets->GetAsset("ShaderProgram.2D.Colored");*/

	const ShaderProgram_Textured2D* _program = (ShaderProgram_Textured2D*)assets->GetAsset("ShaderProgram.2D.Textured");
	const Texture* _texture = (Texture*)assets->GetAsset("Texture.Pentagon");

	const Mesh* _mesh = (Mesh*)assets->GetAsset("Mesh.Octagon");
	glm::mat4 _trans = Transformation(scene, config);

	_program->Render(config, _mesh, _texture, &_trans);
}