#pragma once
#include <glm/vec3.hpp>
#include <map>
#include <string>
#include <vector>

#include "GameObject.h"

class GameObject;
class Input;
class Configuration;

class Scene
{
public:
	Scene(const char* _id);
	~Scene();

	virtual void Update(const double _deltaTime, const Input* _input, Configuration* _config) = 0;

	GameObject* GetGameObject(const char* _id) const;
	std::vector<GameObject*> GetGameObjects() const;

	const char* GetID() const;

	glm::vec3 CameraPosition() const;
	glm::vec3 CameraForward() const;
	glm::vec3 CameraUp() const;

protected:
	std::map<std::string, GameObject*> m_GameObjects;
	const char* m_ID;
	
	bool m_CameraRotationLock = false;

	float m_RotationSensitivity = 0.25f;
	float m_CameraYaw = -90.0f;
	float m_CameraPitch = 0.0f;

	glm::vec3 m_CameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 m_CameraForward = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 m_CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
};