#pragma once

#include "SecureServ.h"
#include "ShaderProgram_Colored2D.h"
#include "ShaderProgram_Textured2D.h"
#include "Assets.h"

SecureServ::SecureServ(const char* _id) : GameObject(_id)
{
}

SecureServ::~SecureServ()
{
}

void SecureServ::SimulateAI(const double, const Assets*, const Scene*, const Configuration*, const Input*)
{
}

void SecureServ::Render(const double, const Assets* _assets, const Scene* _scene, const Configuration* _config)
{
	const ShaderProgram_Textured2D* _program = (ShaderProgram_Textured2D*)_assets->GetAsset("ShaderProgram.2D.Textured");
	const Texture* _texture = (Texture*)_assets->GetAsset("Texture.SecureServ"); 
	
	const Mesh* _mesh = (Mesh*)_assets->GetAsset("Mesh.Square");
	glm::mat4 _trans = Transformation(_scene, _config);

	_program->Render(_config, _mesh, _texture, &_trans);
}
