#include "Scene_TestChamber.h"

#include <string>

#include "Cube.h"
#include "TestChamber.h"

Cube* cube = new Cube("GameObject.Cube0");
TestChamber* chamber = new TestChamber("GameObject.Plain");


Scene_TestChamber::Scene_TestChamber() : Scene("Game")
{
	m_Time = 0;
	m_CameraPosition = { 0, 0, 24 };

	m_GameObjects[cube->GetID()] = cube;
	m_GameObjects[chamber->GetID()] = chamber;
}

Scene_TestChamber::~Scene_TestChamber() {}

void Scene_TestChamber::Update(const double _deltaTime, const Input* _input, Configuration* _config)
{
	ControlCamera(_deltaTime, _input, _config);
	ControlGameObjects(_deltaTime, _input, _config);
}

float camSpeed = 4.0f;
glm::vec3 camDirection{0, 0, 0};

void Scene_TestChamber::ControlCamera(const double _deltaTime, const Input* _input, Configuration* _config)
{

	if (camSpeed == 0)
		camSpeed = 4.0f;
	//if (_input->IsButtonState(Input::Button::, Input::Button_State::))

	#pragma region Camera Speed Control
	if (_input->IsButtonState(Input::Button::PLUS, Input::Button_State::PRESSED))
		camSpeed += 2.0f;
	if (_input->IsButtonState(Input::Button::MINUS, Input::Button_State::PRESSED))
		camSpeed -= 2.0f;

	camSpeed = glm::clamp(camSpeed, 2.0f, 20.0f);
	#pragma endregion

	#pragma region Swich Camera Perspective
	if (_input->IsButtonState(Input::Button::V, Input::Button_State::PRESSED))
		if (_config->Projection == Configuration::ProjectionType::Perspective)
			_config->SetProjection(Configuration::ProjectionType::Orthographic);
		else
			_config->SetProjection(Configuration::ProjectionType::Perspective);
	#pragma endregion

	#pragma region Camera Movement
	if (_input->IsButtonState(Input::Button::W, Input::Button_State::DOWN))
		m_CameraPosition += m_CameraForward * (float)_deltaTime * camSpeed;
	else if (_input->IsButtonState(Input::Button::S, Input::Button_State::DOWN))
		m_CameraPosition -= m_CameraForward * (float)_deltaTime * camSpeed;

	if (_input->IsButtonState(Input::Button::A, Input::Button_State::DOWN))
		m_CameraPosition -= glm::cross(m_CameraForward, m_CameraUp) * (float)_deltaTime * camSpeed;
	else if (_input->IsButtonState(Input::Button::D, Input::Button_State::DOWN))
		m_CameraPosition += glm::cross(m_CameraForward, m_CameraUp) * (float)_deltaTime * camSpeed;

	if (!m_CameraRotationLock)
	{
		if (_input->IsButtonState(Input::Button::Q, Input::Button_State::DOWN))
			m_CameraPosition += m_CameraUp * (float)_deltaTime * camSpeed;
		else if (_input->IsButtonState(Input::Button::E, Input::Button_State::DOWN))
			m_CameraPosition -= m_CameraUp * (float)_deltaTime * camSpeed;

		#pragma endregion

		#pragma region Camera Rotation
		const double _mouseMovementX = _input->CurrentCursorPosition().first - _input->PreviousCursorPosition().first;
		const double _mouseMovementY = _input->CurrentCursorPosition().second - _input->PreviousCursorPosition().second;

		m_CameraYaw += (float)_mouseMovementX * m_RotationSensitivity;
		m_CameraPitch -= (float)_mouseMovementY * m_RotationSensitivity;

		if (m_CameraPitch > 89.0f) m_CameraPitch = 89.0f;
		if (m_CameraPitch < -89.0f) m_CameraPitch = -89.0f;

		camDirection.x = cos(glm::radians(m_CameraYaw)) * cos(glm::radians(m_CameraPitch));
		camDirection.y = sin(glm::radians(m_CameraPitch));
		camDirection.z = sin(glm::radians(m_CameraYaw)) * cos(glm::radians(m_CameraPitch));
		m_CameraForward = glm::normalize(camDirection);
		#pragma endregion

		#pragma region Camera Anchors
		glm::vec3 _offset = { 0.0f, 0.0f, 3.0f };

		if (_input->IsButtonState(Input::Button::K1, Input::Button_State::DOWN))
			m_CameraPosition = cube->GetPosition() + _offset;

	}
	#pragma endregion

	m_CameraPosition = glm::clamp(m_CameraPosition, -24.5f, 24.5f);
	m_CameraPosition.y = glm::clamp(m_CameraPosition.y, -22.0f, 22.0f);

	//std::cout << "Camera Position - X:" << m_CameraPosition.x << "  Y:" << m_CameraPosition.y << "  Z:" << m_CameraPosition.z << std::endl;
	//std::cout << "Camera Rotation - X:" << camDirection.x << "  Y:" << camDirection.y << "  Z:" << camDirection.z << std::endl;

}

int counter = 1;

void Scene_TestChamber::ControlGameObjects(const double , const Input* _input, Configuration*)
{
	if (_input->IsButtonState(Input::Button::T, Input::Button_State::PRESSED))
	{
		std::string _str = "GameObject.Cube";
		_str += std::to_string(counter);
		Cube* _newCube = new Cube(_str.c_str());
		m_GameObjects[_newCube->GetID()] = _newCube;
		counter++;
	}

	chamber->SetPosition({ 0.0f, -2.0f, 0.0f });
	chamber->SetScale({ 50.0f, 50.0f, 50.0f });
}