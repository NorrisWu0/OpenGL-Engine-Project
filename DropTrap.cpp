#include "DropTrap.h"


DropTrap::DropTrap(const char* _id) : GameObject(_id) {}
DropTrap::~DropTrap() {}

void DropTrap::ActivateTrap()
{
	std::cout << "Drop Trap Activated!!! Prepare to pie!!!!" << std::endl;
	if (!m_IsTriggered)
		m_IsTriggered = true;
}

void DropTrap::SimulateAI(const double _deltaTime, const Assets*, const Scene*, const Configuration*, const Input*)
{
	if (m_IsTriggered && m_Position.y > -10)
		m_Position.y -= (float)_deltaTime;
}

void DropTrap::Render(const double, const Assets* _assets, const Scene* _scene, const Configuration* _config)
{

	const ShaderProgram_Textured2D* _program = (ShaderProgram_Textured2D*)_assets->GetAsset("ShaderProgram.2D.Textured");
	const Texture* _texture = (Texture*)_assets->GetAsset("Texture.DropTrap");

	const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.Square");

	_program->Render(_config, _mesh, _texture, Translation(), Rotation(), Scale(), Camera(_scene, _config), Projection(_scene, _config));

}