#pragma once
#include <iostream>

#include "Scene.h"
#include "Utilities/Input.h"


class Scene_TestChamber : public Scene
{
	public: 
	Scene_TestChamber();
	~Scene_TestChamber();

	virtual void Update(const double _deltaTime, const Input* _input, Configuration* _config) override;

	private:
	float m_Time;
	bool m_IsDead = false;

	void ControlCamera(const double _deltaTime, const Input* _input, Configuration* _config);
	void ControlGameObjects(const double _deltaTime, const Input* _input, Configuration* _config);
};
