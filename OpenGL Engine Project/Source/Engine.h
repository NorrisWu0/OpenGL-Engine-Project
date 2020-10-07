#pragma once
#include <glew.h>
#include <glfw3.h>
#include <algorithm>
#include <iostream>

#include "Utilities/Expectations.h"
#include "Utilities/Configuration.h"
#include "Rendering/ShaderProgram.h"
#include "Utilities/Assets.h"
#include "Mesh/Mesh.h"
#include "Mesh/Texture.h"
#include "Scene/Scene.h"
#include "GameObject/GameObject.h"
#include "Utilities/Input.h"

class Scene;
class Input;
class Configuration;
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