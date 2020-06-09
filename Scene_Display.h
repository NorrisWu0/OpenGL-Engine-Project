#pragma once
#include <iostream>

#include "Scene.h"
#include "Input.h"

#include "SecureServ.h"
#include "AllSeeingEye.h"
#include "pointy_head.h"
#include "Cube.h"
#include "Grass.h"
#include "Pyramid.h"
#include "Robot.h"


class Scene_Display :	public Scene
{
public: 
	Scene_Display();
	~Scene_Display();

	virtual void Update(const double _deltaTime, const Input* _input) override;
};
