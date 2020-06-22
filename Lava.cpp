#include "Lava.h"

#include "ShaderProgram_Textured3D.h"

Lava::Lava(const char* _id) : GameObject(_id) {}
Lava::~Lava() {}

void Lava::ActivateLava()
{
	std::cout << "Or drown in HOT HOT LAVA!!!!" << std::endl;
	if (!m_IsTriggered)
		m_IsTriggered = true;
}

// Yea, this is not good.
bool temp = false;

void Lava::SimulateAI(const double _deltaTime, const Assets* _assets, const Scene*, const Configuration*, const Input*)
{
	if (m_IsTriggered)
	{
		if (!temp)
		{
			ShaderProgram_Textured3D* _program = (ShaderProgram_Textured3D*)_assets->GetAsset("ShaderProgram.3D.Textured");
			_program->SetAmbientColor({ 0.0, 0.0, 0.0 });
			_program->SetLightColor({ 1.0, 0.0, 0.0 });
			temp = true;
		}

		if (m_Position.y < -10)
			m_Position.y += (float)_deltaTime / 2;
	}
}

void Lava::Render(const double, const Assets* _assets, const Scene* _scene, const Configuration* _config)
{

	const ShaderProgram_Textured2D* _program = (ShaderProgram_Textured2D*)_assets->GetAsset("ShaderProgram.2D.Textured");
	const Texture* _texture = (Texture*)_assets->GetAsset("Texture.Lava");

	const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.Square");

	_program->Render(_config, _mesh, _texture, Translation(), Rotation(), Scale(), Camera(_scene, _config), Projection(_scene, _config));

}