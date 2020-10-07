#pragma once

#include "GameObject/GameObject.h"
#include "Rendering/ShaderPrograms/ShaderProgram_Textured2D.h"
#include "Utilities/Assets.h"

class DropTrap :
    public GameObject
{
	public:
	DropTrap(const char* _id);
	~DropTrap();

	void ActivateTrap();

	virtual void SimulateAI(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input) override;
	virtual void Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config) override;

	private:
	bool m_IsTriggered = false;	

};

