#pragma once

#include "GameObject.h"

class Pointy_Head : public GameObject
{
public:
	Pointy_Head(const char* _id);
	~Pointy_Head();

	virtual void SimulateAI(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input) override;
	virtual void Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config) override;
};