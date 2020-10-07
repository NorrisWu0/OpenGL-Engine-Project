#pragma once
#include "GameObject/GameObject.h"
#include "Rendering/ShaderPrograms/ShaderProgram_Textured3D.h"
#include "Utilities/Assets.h"

class Lava :
	public GameObject
{
	public:
	Lava(const char* _id);
	~Lava();

	void ActivateLava();

	virtual void SimulateAI(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input) override;
	virtual void Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config) override;

	private:
	bool m_IsTriggered = false;

};

