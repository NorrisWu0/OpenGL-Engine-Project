#include "Scene_Display.h"


SecureServ* _secureServ = new SecureServ("GameObject.SecureServ");
AllSeeingEye* _ase = new AllSeeingEye("GameObject.AllSeeingEye");
Pointy_Head* _ph = new Pointy_Head("GameObject.thisnewthing");
Cube* _cube = new Cube("GameObject.Cube");
Grass* _grass = new Grass("GameObject.Grass");
Pyramid* _pyramid = new Pyramid("GameObject.Pyramid");
Robot* _robot = new Robot("GameObject.Robot");

Scene_Display::Scene_Display() : Scene("Game")
{
	m_CameraPosition = { 0, 0, 0 };

	m_GameObjects[_secureServ->ID()] = _secureServ;
	m_GameObjects[_ase->ID()] = _ase;
	m_GameObjects[_ph->ID()] = _ph;
	m_GameObjects[_cube->ID()] = _cube;
	m_GameObjects[_grass->ID()] = _grass;
	m_GameObjects[_pyramid->ID()] = _pyramid;
	m_GameObjects[_robot->ID()] = _robot;

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

	_robot->SetPosition({48.0f, 0.0f, -3.0f});
	_robot->SetScale({1, 1, 1});
}

Scene_Display::~Scene_Display()
{
}

void Scene_Display::Update(const double _deltaTime, const Input* _input)
{
	float _moveSpeed = 4.0f;

	#pragma region Camera Movement
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
	
	#pragma region Camera Rotation
	const double _mouseMovementX = _input->CurrentCursorPosition().first - _input->PreviousCursorPosition().first;
	const double _mouseMovementY = _input->CurrentCursorPosition().second - _input->PreviousCursorPosition().second;

	m_CameraYaw += (float)_mouseMovementX * m_RotationSensitivity;
	m_CameraPitch -= (float)_mouseMovementY * m_RotationSensitivity;

	if (m_CameraPitch > 89.0f) m_CameraPitch = 89.0f;
	if (m_CameraPitch < -89.0f) m_CameraPitch = -89.0f;

	glm::vec3 _camDirection;

	_camDirection.x = cos(glm::radians(m_CameraYaw)) * cos(glm::radians(m_CameraPitch));
	_camDirection.y = sin(glm::radians(m_CameraPitch));
	_camDirection.z = sin(glm::radians(m_CameraYaw)) * cos(glm::radians(m_CameraPitch));
	m_CameraForward = glm::normalize(_camDirection);
	#pragma endregion

	#pragma region Camera Slot
	glm::vec3 _offset = { 0.0f, 0.0f, 3.0f };

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

	if (_input->IsButtonState(Input::Button::K7, Input::Button_State::DOWN))
		m_CameraPosition = _robot->GetPosition() + _offset;

	#pragma endregion

	

	std::cout << "Camera Position - X:" << m_CameraPosition.x << "  Y:" << m_CameraPosition.y << "  Z:" << m_CameraPosition.z << std::endl;
}
