#pragma once

#include "GameObject.h"
#include "scene.h"
#include "configuration.h"

GameObject::GameObject(const char* _id)
	: m_ID(_id)
{
}
GameObject::~GameObject()
{
}

const char* GameObject::ID() const
{
	return m_ID;
}

void GameObject::SimulatePhysics(const double, const Assets*, const Scene*, const Configuration*)
{
}

float GameObject::RTF(float _value)
{
	return _value / 255;
}

std::vector<GLfloat> GameObject::RGBA(float _r, float _g, float _b, float _a)
{
	std::vector<GLfloat> _value = { _r,_g,_b,_a };

	return _value;
}

glm::mat4x4 GameObject::Transformation(const Scene* _scene, const Configuration* _config)
{
	/// Convert vec4 into mat4 (vec4 * vec4 matrix)

	glm::mat4 _position = glm::translate(glm::mat4(1.0f), m_Position);

	glm::mat4 _scale = glm::scale(glm::mat4(1.0f), m_Scale);

	glm::mat4 _rotationX = glm::rotate(m_Rotation.x, glm::vec3(1.f, 0.f, 0.f));
	glm::mat4 _rotationY = glm::rotate(m_Rotation.y, glm::vec3(0.f, 1.f, 0.f));
	glm::mat4 _rotationZ = glm::rotate(m_Rotation.z, glm::vec3(0.f, 0.f, 1.f));
	glm::mat4 _rotation = _rotationX * _rotationY * _rotationZ;

	glm::mat4 _model = _position * _scale * _rotation;
	
	// Camera Transform
	glm::vec3 _cameraPosition = _scene->CameraPosition();
	glm::vec3 _cameraForward = _scene->CameraForward();
	glm::vec3 _cameraUp = _scene->CameraUp();
	__pragma(warning(push));
	__pragma(warning(disable:4127));
	glm::mat4 _camera = glm::lookAt(_cameraPosition, _cameraPosition + _cameraForward, _cameraUp);
	__pragma(warning(pop));

	// Projection - scale objects on x axis
	const float _aspectRatio = float(_config->screenWidth) / _config->screenHeight;
	const float _xUnits = _aspectRatio * _config->yUnits;
	const float _yUnits =  float(_config->yUnits);

	glm::mat4 _projectionScale;
	
	if (_config->_projection == Configuration::Projection::Orthographic)
		_projectionScale = glm::ortho(-_xUnits / 2, _xUnits / 2, -_yUnits / 2, _yUnits / 2, 0.1f, float(_config->zUnits));
	else if (_config->_projection == Configuration::Projection::Perspective)
		_projectionScale = glm::perspectiveFov(glm::radians(_config->fov), float(_config->screenWidth), float(_config->screenHeight), 0.1f, float(_config->zUnits));

	return _projectionScale * _camera * _model;
}

void GameObject::SetPosition(const glm::vec3 _position)
{
	m_Position = _position;
}

glm::vec3 GameObject::GetPosition()
{
	return m_Position;
}

void GameObject::SetRotation(const glm::vec3 _rotation)
{
	m_Rotation = _rotation;
}

glm::vec3 GameObject::GetRotation()
{
	return m_Rotation;
}

void GameObject::SetScale(const glm::vec3 _scale)
{
	m_Scale = _scale;
}

glm::vec3 GameObject::GetScale()
{
	return m_Scale;
}
