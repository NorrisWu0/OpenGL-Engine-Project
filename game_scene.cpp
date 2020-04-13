#include "game_scene.h"
#include "pointy_head.h"
#include "blocky_boy.h"

Game_Scene::Game_Scene()
	: Scene("Game")
{
	Pointy_Head* pointy_head = new Pointy_Head("Game_Object.Pointy_Head");
	_game_objects[pointy_head->id()] = pointy_head;

	Blocky_Boy* blocky_boy = new Blocky_Boy("Game_Object.Blocky_Boy");
	_game_objects[blocky_boy->id()] = blocky_boy;
}

Game_Scene::~Game_Scene()
{

}

void Game_Scene::update(const double)
{
}