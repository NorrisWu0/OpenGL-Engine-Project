#pragma once

#include "GameObject.h"

class Bunker :	public GameObject
{
public:
	Bunker(const char* _id);
	~Bunker();

	virtual void SimulateAI(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input) override;
	virtual void Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config) override;

};

