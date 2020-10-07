#pragma once
#include "GameObject/GameObject.h"
#include "Rendering/ShaderPrograms/ShaderProgram_Textured3D.h"
#include "Utilities/Assets.h"

class TestChamber : public GameObject
{
	public:
	TestChamber(const char* _id);
	~TestChamber();

	virtual void SimulateAI(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input) override;
	virtual void Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config) override;

};

