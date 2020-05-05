#include "Scene_Display.h"
#include "Input.h"

#include "Cube.h"

#include <iostream>


Scene_Display::Scene_Display() : Scene("Game")
{
	m_CameraPosition = { 0, 0, 0 };

	Cube* _cube = new Cube("GameObject.Cube");
	_game_objects[_cube->id()] = _cube;

	_cube->SetPosition({0.0f, 0.0f, 3.0f});
}

Scene_Display::~Scene_Display()
{
}

void Scene_Display::Update(const double _deltaTime, const Input* _input)
{
	float _moveSpeed = 2.0f;
	
	#pragma region MyRegion
	if (_input->IsButtonState(Input::Button::W, Input::Button_State::DOWN))
		m_CameraPosition += m_CameraForward * (float)_deltaTime * _moveSpeed;
	else if (_input->IsButtonState(Input::Button::S, Input::Button_State::DOWN))
		m_CameraPosition -= m_CameraForward * (float)_deltaTime * _moveSpeed;

	if (_input->IsButtonState(Input::Button::A, Input::Button_State::DOWN))
		m_CameraPosition -= glm::cross(m_CameraForward, m_CameraUp) * (float)_deltaTime * _moveSpeed;
	else if (_input->IsButtonState(Input::Button::D, Input::Button_State::DOWN))
		m_CameraPosition += glm::cross(m_CameraForward, m_CameraUp) * (float)_deltaTime * _moveSpeed;

	if (_input->IsButtonState(Input::Button::Q, Input::Button_State::DOWN))
		m_CameraPosition += m_CameraUp * (float)_deltaTime * _moveSpeed;
	else if (_input->IsButtonState(Input::Button::E, Input::Button_State::DOWN))
		m_CameraPosition -= m_CameraUp * (float)_deltaTime * _moveSpeed;

	#pragma endregion
	
	std::cout << "Camera Position - X:" << m_CameraPosition.x << "  Y:" << m_CameraPosition.y << "  Z:" << m_CameraPosition.z << std::endl;
}
