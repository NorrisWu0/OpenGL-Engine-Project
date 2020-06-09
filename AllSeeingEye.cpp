#include "AllSeeingEye.h"

AllSeeingEye::AllSeeingEye(const char* _id) : GameObject(_id) {}
AllSeeingEye::~AllSeeingEye() {}

void AllSeeingEye::SimulateAI(const double, const Assets*, const Scene*, const Configuration*, const Input*) {}

void AllSeeingEye::Render(const double, const Assets* _assets, const Scene* _scene, const Configuration* _config)
{
	const ShaderProgram_Textured2D* _program = (ShaderProgram_Textured2D*)_assets->GetAsset("ShaderProgram.2D.Textured");
	const Texture* _texture = (Texture*)_assets->GetAsset("Texture.AllSeeingEye");

	const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.RightTriangle");
	glm::mat4 _trans = Transformation(_scene, _config);

	_program->Render(_config, _mesh, _texture, &_trans);

}