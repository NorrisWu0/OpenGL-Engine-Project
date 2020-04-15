#pragma once

#include <map>
#include <string>
#include <vector>

class GameObject;
class Input;

class Scene
{
public:
	Scene(const char* id);
	~Scene();

	virtual void update(const double _deltaTime) = 0;

	GameObject* get_game_object(const char* id) const;
	std::vector<GameObject*> get_game_objects() const;

	const char* id() const;

protected:
	std::map<std::string, GameObject*> _game_objects;
	const char*                         _id;
};