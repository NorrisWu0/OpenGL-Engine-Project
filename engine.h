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

	void simulate(const double seconds_to_simulate, const class Assets* assets, const Scene* scene, const Configuration* config);

	GLFWwindow* window() const;

private:
	void SimulateAI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config);
	void SimulatePhysics(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config);
	void Render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config);

	GLFWwindow* _window = nullptr;
};