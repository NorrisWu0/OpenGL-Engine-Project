#pragma once
#include "GameObject.h"
class Pyramid : public GameObject
{
public:
	Pyramid(const char* _id);
	~Pyramid();

	virtual void SimulateAI(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input) override;
	virtual void Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config) override;

};

