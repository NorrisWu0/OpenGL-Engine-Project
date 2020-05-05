#include "Scene_2DWorld.h"
#include "pointy_head.h"
#include "Floor.h"
#include "Bunker.h"

Scene_2DWorld::Scene_2DWorld()
	: Scene("Game")
{
	Pointy_Head* pointy_head = new Pointy_Head("GameObject.Pointy_Head");
	_game_objects[pointy_head->id()] = pointy_head;

	Floor* _floor = new Floor("GameObject.Floor");
	_game_objects[_floor->id()] = _floor;

	Bunker* _bunker = new Bunker("GameObject.Bunker");
	_game_objects[_bunker->id()] = _bunker;
}

Scene_2DWorld::~Scene_2DWorld()
{

}

void Scene_2DWorld::Update(const double, const Input*)
{
}