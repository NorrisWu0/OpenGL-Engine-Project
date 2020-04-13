#pragma once

#include "game_object.h"

class Pointy_Head : public Game_Object
{
public:
	Pointy_Head(const char* id);
	~Pointy_Head();

	virtual void SimulateAI(const double _deltaTime, const Assets* assets, const Scene* scene, const Configuration* config) override;
	virtual void Render(const double _deltaTime, const Assets* assets, const Scene* scene, const Configuration* config) override;
};