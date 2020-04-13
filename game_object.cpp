#pragma once

#include "game_object.h"
#include "scene.h"
#include "configuration.h"

Game_Object::Game_Object(const char* id)
	: _id(id)
{
}
Game_Object::~Game_Object()
{
}

const char* Game_Object::id() const
{
	return _id;
}

void Game_Object::SimulatePhysics(const double, const Assets*, const Scene*, const Configuration*)
{
}

float Game_Object::RTF(float _value)
{
	return _value / 255;
}

glm::mat4x4 Game_Object::Transformation(const Scene*, const Configuration*)
{
	/// Convert vec4 into mat4 (vec4 * vec4 matrix)

	glm::mat4 _position = glm::translate(glm::mat4(1.0f), position);

	glm::mat4 _scale = glm::scale(glm::mat4(1.0f), scale);

	glm::mat4 _rotationX = glm::rotate(rotation.x, glm::vec3(1.f, 0.f, 0.f));
	glm::mat4 _rotationY = glm::rotate(rotation.y, glm::vec3(0.f, 1.f, 0.f));
	glm::mat4 _rotationZ = glm::rotate(rotation.z, glm::vec3(0.f, 0.f, 1.f));
	glm::mat4 _rotation = _rotationX * _rotationY * _rotationZ;

	glm::mat4 _model = _position * _scale * _rotation;
	
	return _model;
}
