#pragma once

#include "Scene.h"
#include "GameObject.h"

Scene::Scene(const char* id)
	: _id(id)
{
}

Scene::~Scene()
{
}

std::vector<GameObject*> Scene::GetGameObjects() const
{
	std::vector<GameObject*> game_objects;

	for(auto key_value : _game_objects)
	{
		game_objects.push_back(key_value.second);
	}

	return game_objects;
}

GameObject* Scene::GetGameObject(const char* id) const
{
	if(_game_objects.find(id) == _game_objects.end())
	{
		std::cout << "Attempted to find a game object that does not exist. ID: " << id << std::endl;
		exit(1);
	}

	return _game_objects.find(id)->second;
}

const char* Scene::id() const
{
	return _id;
}

glm::vec3 Scene::CameraPosition() const
{
	return m_CameraPosition;
}

glm::vec3 Scene::CameraForward() const
{
	return m_CameraForward;
}

glm::vec3 Scene::CameraUp() const
{
	return m_CameraUp;
}
