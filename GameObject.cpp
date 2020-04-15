#pragma once

#include "GameObject.h"
#include "scene.h"
#include "configuration.h"

GameObject::GameObject(const char* id)
	: _id(id)
{
}
GameObject::~GameObject()
{
}

const char* GameObject::id() const
{
	return _id;
}

void GameObject::SimulatePhysics(const double, const Assets*, const Scene*, const Configuration*)
{
}

float GameObject::RTF(float _value)
{
	return _value / 255;
}

glm::mat4x4 GameObject::Transformation(const Scene*, const Configuration* _config)
{
	/// Convert vec4 into mat4 (vec4 * vec4 matrix)

	glm::mat4 _position = glm::translate(glm::mat4(1.0f), position);

	glm::mat4 _scale = glm::scale(glm::mat4(1.0f), scale);

	glm::mat4 _rotationX = glm::rotate(rotation.x, glm::vec3(1.f, 0.f, 0.f));
	glm::mat4 _rotationY = glm::rotate(rotation.y, glm::vec3(0.f, 1.f, 0.f));
	glm::mat4 _rotationZ = glm::rotate(rotation.z, glm::vec3(0.f, 0.f, 1.f));
	glm::mat4 _rotation = _rotationX * _rotationY * _rotationZ;

	glm::mat4 _model = _position * _scale * _rotation;
	
	// Camera Transform

	// Projection - scale objects on x axis
	const float _aspectRatio = float(_config->screenWidth) / float(_config->screenHeight);
	const float _xUnits = _aspectRatio * _config->yUnits;
	glm::mat4 _projectionScale = glm::scale(glm::mat4(1.0f), glm::vec3(2.0f / _xUnits, 2.0f / _config->yUnits, 1));

	return _model * _projectionScale;
}
