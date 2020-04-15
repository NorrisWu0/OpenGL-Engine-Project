#pragma once

#include "scene.h"

class Game_Scene : public Scene
{
public:
	Game_Scene();
	~Game_Scene();

	virtual void update(const double _deltaTime) override;
};