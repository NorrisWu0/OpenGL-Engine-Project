#pragma once
#include <math.h>

#include "GameObject.h"
#include "ShaderProgram_Textured2D.h"
#include "Assets.h"

class SignPost :
	public GameObject
{
	public:
	SignPost(const char* _id);
	~SignPost();

	void SetTexture(const char* _textureID);

	virtual void SimulateAI(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input) override;
	virtual void Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config) override;

	private:
	const char* m_TextureID = NULL;
};
