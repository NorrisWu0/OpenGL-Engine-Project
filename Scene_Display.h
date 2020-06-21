#pragma once
#include <iostream>

#include "Scene.h"
#include "Input.h"


class Scene_Display : public Scene
{
	public: 
	Scene_Display();
	~Scene_Display();

	virtual void Update(const double _deltaTime, const Input* _input, Configuration* _config) override;

	private:
	float m_Time;

	void ControlCamera(const double _deltaTime, const Input* _input, Configuration* _config);
	void ControlGameObjects(const double _deltaTime, const Input* _input, Configuration* _config);
};
