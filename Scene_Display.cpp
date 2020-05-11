#include "Scene_Display.h"
#include "Input.h"

#include "SecureServ.h"
#include "AllSeeingEye.h"
#include "pointy_head.h"

#include "Cube.h"
#include "Grass.h"
#include "Pyramid.h"

#include <iostream>

SecureServ* _secureServ = new SecureServ("GameObject.SecureServ");
AllSeeingEye* _ase = new AllSeeingEye("GameObject.AllSeeingEye");
Pointy_Head* _ph = new Pointy_Head("GameObject.thisnewthing");

Cube* _cube = new Cube("GameObject.Cube");
Grass* _grass = new Grass("GameObject.Grass");
Pyramid* _pyramid = new Pyramid("GameObject.Pyramid");

Scene_Display::Scene_Display() : Scene("Game")
{
	m_CameraPosition = { 0, 0, 0 };

	_game_objects[_secureServ->id()] = _secureServ;
	_game_objects[_ase->id()] = _ase;
	_game_objects[_ph->id()] = _ph;
	_game_objects[_cube->id()] = _cube;
	_game_objects[_grass->id()] = _grass;
	_game_objects[_pyramid->id()] = _pyramid;

	_secureServ->SetPosition({0.0f, 0.0f, -3.0f});
	_ase->SetPosition({8.0f, 0.0f, -3.0f});
	_ase->SetScale({2.0f, 2.0f, 1.0f});
	_ph->SetPosition({16.0f, 0.0f, -3.0f });

	_cube->SetPosition({24.0f, 0.0f, -3.0f});
	_cube->SetScale({1.5f, 1.5f, 1.5f});

	_grass->SetPosition({32.0f, 0.0f, -3.0f});
	_grass->SetScale({1.5f, 1.5f, 1.5f});

	_pyramid->SetPosition({42.0f, 0.0f, -3.0f});
	_pyramid->SetScale({3.0f, 3.0f, 3.0f});
}

Scene_Display::~Scene_Display()
{
}

void Scene_Display::Update(const double _deltaTime, const Input* _input)
{
	float _moveSpeed = 4.0f;
	
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

	if (_input->IsButtonState(Input::Button::LSHIFT, Input::Button_State::DOWN))
		_moveSpeed = 8.0f;
	else
		_moveSpeed = 4.0f;
	#pragma endregion
	
	glm::vec3 _offset = { 0.0f, 0.0f, 3.0f };

	#pragma region Camera Location
	if (_input->IsButtonState(Input::Button::K1, Input::Button_State::DOWN))
		m_CameraPosition = _secureServ->GetPosition() + _offset;

	if (_input->IsButtonState(Input::Button::K2, Input::Button_State::DOWN))
		m_CameraPosition = _ase->GetPosition() + _offset;

	if (_input->IsButtonState(Input::Button::K3, Input::Button_State::DOWN))
		m_CameraPosition = _ph->GetPosition() + _offset;

	if (_input->IsButtonState(Input::Button::K4, Input::Button_State::DOWN))
		m_CameraPosition = _cube->GetPosition() + _offset;

	if (_input->IsButtonState(Input::Button::K5, Input::Button_State::DOWN))
		m_CameraPosition = _grass->GetPosition() + _offset;

	if (_input->IsButtonState(Input::Button::K6, Input::Button_State::DOWN))
		m_CameraPosition = _pyramid->GetPosition() + _offset;

	#pragma endregion

	
	//std::cout << "Camera Position - X:" << m_CameraPosition.x << "  Y:" << m_CameraPosition.y << "  Z:" << m_CameraPosition.z << std::endl;
}
