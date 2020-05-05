#pragma once

#include "Scene.h"

class Scene_2DWorld : public Scene
{
public:
	Scene_2DWorld();
	~Scene_2DWorld();

	virtual void Update(const double _deltaTime, const Input* _input) override;
};