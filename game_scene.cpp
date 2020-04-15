#include "game_scene.h"
#include "pointy_head.h"
#include "Floor.h"
#include "Bunker.h"

Game_Scene::Game_Scene()
	: Scene("Game")
{
	Pointy_Head* pointy_head = new Pointy_Head("GameObject.Pointy_Head");
	_game_objects[pointy_head->id()] = pointy_head;

	Floor* _floor = new Floor("GameObject.Floor");
	_game_objects[_floor->id()] = _floor;

	Bunker* _bunker = new Bunker("GameObject.Bunker");
	_game_objects[_bunker->id()] = _bunker;
}

Game_Scene::~Game_Scene()
{

}

void Game_Scene::update(const double)
{
}