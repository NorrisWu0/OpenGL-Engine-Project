#include "Scene.h"

Scene::Scene(const char* _id) : m_ID(_id) {}
Scene::~Scene() {}

std::vector<GameObject*> Scene::GetGameObjects() const
{
	std::vector<GameObject*> game_objects;

	for(auto key_value : m_GameObjects)
		game_objects.push_back(key_value.second);

	return game_objects;
}

GameObject* Scene::GetGameObject(const char* GetID) const
{
	if(m_GameObjects.find(GetID) == m_GameObjects.end())
	{
		std::cout << "Attempted to find a game object that does not exist. ID: " << GetID << std::endl;
		exit(1);
	}

	return m_GameObjects.find(GetID)->second;
}

const char* Scene::GetID() const {	return m_ID; }

glm::vec3 Scene::CameraPosition() const { return m_CameraPosition; }
glm::vec3 Scene::CameraForward() const { return m_CameraForward; }
glm::vec3 Scene::CameraUp() const { return m_CameraUp; }
