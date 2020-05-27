#pragma once
#include <glew.h>
#include <vector>
#include <math.h>

#include "GameObject.h"
#include "ShaderProgram_Colored2D.h"
#include "Assets.h"


class Bunker :	public GameObject
{
public:
	Bunker(const char* _id);
	~Bunker();

	virtual void SimulateAI(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input) override;
	virtual void Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config) override;
};

