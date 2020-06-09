#include "Robot.h"

Robot::Robot(const char* _id) : GameObject(_id) {}
Robot::~Robot() {}

void Robot::SimulateAI(const double, const Assets*, const Scene*, const Configuration*, const Input*)
{}

void Robot::Render(const double, const Assets * _assets, const Scene * _scene, const Configuration * _config)
{
	const ShaderProgram_Textured3D* _program = (ShaderProgram_Textured3D*)_assets->GetAsset("ShaderProgram.3D.Textured");
	const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.Handgun");
	const Texture* _texture = (Texture*)_assets->GetAsset("Texture.Handgun");

	glm::mat4 _trans = Transformation(_scene, _config);
	_program->Render(_config, _mesh, _texture, &_trans);

}
