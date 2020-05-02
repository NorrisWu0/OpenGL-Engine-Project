#pragma once

#include "GameObject.h"

class Bunker :	public GameObject
{
public:
	Bunker(const char*);
	~Bunker();

	virtual void SimulateAI(const double, const Assets*, const Scene*, const Configuration*) override;
	virtual void Render(const double, const Assets*, const Scene*, const Configuration*) override;

};

