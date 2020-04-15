#pragma once

#include "GameObject.h"

class Pointy_Head : public GameObject
{
public:
	Pointy_Head(const char* id);
	~Pointy_Head();

	virtual void SimulateAI(const double _deltaTime, const Assets* assets, const Scene* scene, const Configuration* config) override;
	virtual void Render(const double _deltaTime, const Assets* assets, const Scene* scene, const Configuration* config) override;
};