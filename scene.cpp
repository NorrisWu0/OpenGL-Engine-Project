#pragma once

#include "Scene.h"
#include "GameObject.h"

Scene::Scene(const char* ID)
	: m_ID(ID)
{
}

Scene::~Scene()
{
}

std::vector<GameObject*> Scene::GetGameObjects() const
{
	std::vector<GameObject*> game_objects;

	for(auto key_value : m_GameObjects)
	{
		game_objects.push_back(key_value.second);
	}

	return game_objects;
}

GameObject* Scene::GetGameObject(const char* ID) const
{
	if(m_GameObjects.find(ID) == m_GameObjects.end())
	{
		std::cout << "Attempted to find a game object that does not exist. ID: " << ID << std::endl;
		exit(1);
	}

	return m_GameObjects.find(ID)->second;
}

const char* Scene::ID() const
{
	return m_ID;
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
