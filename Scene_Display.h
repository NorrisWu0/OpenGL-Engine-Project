#pragma once
#include <iostream>

#include "Scene.h"
#include "Input.h"

#include "Cube.h"


class Scene_Display : public Scene
{
public: 
	Scene_Display();
	~Scene_Display();

	virtual void Update(const double _deltaTime, const Input* _input, const Configuration* _config) override;
};
