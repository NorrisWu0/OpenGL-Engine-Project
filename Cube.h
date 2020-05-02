#pragma once
#include "GameObject.h"

class Cube : public GameObject
{
public:
	Cube(const char*);
	~Cube();
	
	virtual void SimulateAI(const double, const Assets*, const Scene*, const Configuration*) override;
	virtual void Render(const double, const Assets*, const Scene*, const Configuration*) override;

};

