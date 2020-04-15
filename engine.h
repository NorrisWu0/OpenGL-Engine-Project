#pragma once

class Scene;
class Input;
struct Configuration;
struct GLFWwindow;

#include "assets.h"

class Engine
{
public:
	Engine(const char* game_name, Configuration* config);
	~Engine();

	void simulate(const double _deltaTime, const class Assets* assets, const Scene* scene, const Configuration* config);

	GLFWwindow* window() const;

private:
	void SimulateAI(const double _deltaTime, const Assets* assets, const Scene* scene, const Configuration* config);
	void SimulatePhysics(const double _deltaTime, const Assets* assets, const Scene* scene, const Configuration* config);
	void Render(const double _deltaTime, const Assets* assets, const Scene* scene, const Configuration* config);

	GLFWwindow* _window = nullptr;
};