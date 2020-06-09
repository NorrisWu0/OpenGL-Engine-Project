#pragma once
#include <math.h>

#include "GameObject.h"
#include "ShaderProgram_Textured3D.h"
#include "Assets.h"
#include "Input.h"

class Robot :
	public GameObject
{
	public:
	Robot(const char* _id);
	~Robot();

	virtual void SimulateAI(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input) override;
	virtual void Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config) override;

};
