#pragma once
#include "Scene.h"

class Scene_Display :	public Scene
{
public: 
	Scene_Display();
	~Scene_Display();

	virtual void Update(const double _deltaTime, const Input* _input) override;
};
