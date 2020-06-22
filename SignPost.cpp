#include "SignPost.h"


SignPost::SignPost(const char* _id) : GameObject(_id) {}
SignPost::~SignPost() {}

void SignPost::SetTexture(const char* _textureID)
{
	m_TextureID = _textureID;
}

void SignPost::SimulateAI(const double, const Assets*, const Scene*, const Configuration*, const Input*) {}

void SignPost::Render(const double, const Assets* _assets, const Scene* _scene, const Configuration* _config)
{
	if (m_IsActive)
	{
		const ShaderProgram_Textured2D* _program = (ShaderProgram_Textured2D*)_assets->GetAsset("ShaderProgram.2D.Textured");
		const Texture* _texture = (Texture*)_assets->GetAsset(m_TextureID);

		const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.Square");

		_program->Render(_config, _mesh, _texture, Translation(), Rotation(), Scale(), Camera(_scene, _config), Projection(_scene, _config));
	}

}