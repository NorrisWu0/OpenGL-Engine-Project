#pragma once

#include <map>
#include <string>
#include <vector>

#include <glm/vec3.hpp>

class GameObject;
class Input;

class Scene
{
public:
	Scene(const char* id);
	~Scene();

	virtual void Update(const double _deltaTime, const Input* _input) = 0;

	GameObject* GetGameObject(const char* id) const;
	std::vector<GameObject*> GetGameObjects() const;

	const char* id() const;

	glm::vec3 CameraPosition() const;
	glm::vec3 CameraForward() const;
	glm::vec3 CameraUp() const;

protected:
	std::map<std::string, GameObject*> _game_objects;
	const char* _id;

	glm::vec3 m_CameraPosition = glm::vec3(0.0f, 0.0f, -3.0f);
	glm::vec3 m_CameraForward = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 m_CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

};