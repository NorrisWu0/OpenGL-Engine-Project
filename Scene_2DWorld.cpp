#include "Scene_2DWorld.h"
#include "pointy_head.h"
#include "Floor.h"
#include "Bunker.h"

Scene_2DWorld::Scene_2DWorld()
	: Scene("Game")
{
	Pointy_Head* pointy_head = new Pointy_Head("GameObject.Pointy_Head");
	m_GameObjects[pointy_head->ID()] = pointy_head;

	Floor* _floor = new Floor("GameObject.Floor");
	m_GameObjects[_floor->ID()] = _floor;

	Bunker* _bunker = new Bunker("GameObject.Bunker");
	m_GameObjects[_bunker->ID()] = _bunker;
}

Scene_2DWorld::~Scene_2DWorld()
{

}

void Scene_2DWorld::Update(const double, const Input*)
{
}