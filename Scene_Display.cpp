#include "Scene_Display.h"


Cube* _cube = new Cube("GameObject.Cube");

Scene_Display::Scene_Display() : Scene("Game")
{
	m_CameraPosition = { 0, 0, 0 };

	m_GameObjects[_cube->GetID()] = _cube;

	_cube->SetPosition({0.0f, 0.0f, -3.0f});
	_cube->SetScale({1.5f, 1.5f, 1.5f});
}

Scene_Display::~Scene_Display() {}

void Scene_Display::Update(const double _deltaTime, const Input* _input, const Configuration*)
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

	#pragma region Camera Anchors
	glm::vec3 _offset = { 0.0f, 0.0f, 3.0f };

	if (_input->IsButtonState(Input::Button::K1, Input::Button_State::DOWN))
		m_CameraPosition = _cube->GetPosition() + _offset;

	#pragma endregion

	std::cout << "Camera Position - X:" << m_CameraPosition.x << "  Y:" << m_CameraPosition.y << "  Z:" << m_CameraPosition.z << std::endl;
}

void CameraControl()
{

}