#include "Scene_Display.h"

#include "Cube.h"

Scene_Display::Scene_Display() : Scene("Game")
{
	Cube* _cube = new Cube("GameObject.Cube");
	_game_objects[_cube->id()] = _cube;
}

Scene_Display::~Scene_Display()
{
}

void Scene_Display::Update(const double)
{
}
