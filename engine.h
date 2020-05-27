#pragma once
#include <glew.h>
#include <glfw3.h>
#include <algorithm>
#include <iostream>

#include "Expectations.h"
#include "Configuration.h"
#include "ShaderProgram.h"
#include "Assets.h"
#include "Mesh.h"
#include "Texture.h"
#include "Scene.h"
#include "GameObject.h"
#include "Input.h"

class Scene;
class Input;
struct Configuration;
struct GLFWwindow;


class Engine
{
public:
	Engine(const char* _gameName, Configuration* _config);
	~Engine();

	void Simulate(const double _deltaTime, const class Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input);

	GLFWwindow* window() const;

private:
	void SimulateAI(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input);
	void SimulatePhysics(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config);
	void Render(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config);

	GLFWwindow* _window = nullptr;
};