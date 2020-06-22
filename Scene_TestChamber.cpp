#include "Scene_TestChamber.h"

#include <string>

#include "TestChamber.h"
#include "Cube.h"
#include "SignPost.h"
#include "DropTrap.h"
#include "Lava.h"

int counter = 1;

TestChamber* chamber = new TestChamber("GameObject.Plain");
Cube* cube = new Cube("GameObject.Cube0");
SignPost* sign1 = new SignPost("GameObject.Sign1");
SignPost* infoSign = new SignPost("GameObject.InfoSign");
SignPost* warningSign1 = new SignPost("GameObject.WarningSign1");
SignPost* warningSign2 = new SignPost("GameObject.WarningSign2");
DropTrap* droptrap = new DropTrap("GameObject.DropTrap");
Lava* lava = new Lava("GameObject.Lava");
SignPost* endSign = new SignPost("GameObject.EndSign");

Scene_TestChamber::Scene_TestChamber() : Scene("Game")
{
	m_Time = 0;
	m_CameraPosition = { 0, 0, 24 };

	m_GameObjects[chamber->GetID()] = chamber;
	chamber->SetPosition({ 0.0f, -2.0f, 0.0f });
	chamber->SetScale({ 50.0f, 50.0f, 50.0f });

	m_GameObjects[cube->GetID()] = cube;

	m_GameObjects[sign1->GetID()] = sign1;
	sign1->SetPosition({ 0.0f, 2.0f, -19.0f });
	sign1->SetScale({ 50.0f, 50.0f, 1.0f });
	sign1->SetRotation({ 0.3f, 0.0f, 0.0f });
	sign1->SetTexture("Texture.AllSeeingEye");
	sign1->SetActive(false);

	m_GameObjects[infoSign->GetID()] = infoSign;
	infoSign->SetPosition({ 0.0f, 0.0f, 15.0f });
	infoSign->SetScale({ 5.0f, 2.5f, 1.0f });
	infoSign->SetRotation({ 0.0f, 0.0f, 0.0f });
	infoSign->SetTexture("Texture.InfoSign");

	m_GameObjects[warningSign1->GetID()] = warningSign1;
	warningSign1->SetPosition({ -5.0f, 0.0f, 15.8f });
	warningSign1->SetScale({ 5.0f, 2.5f, 1.0f });
	warningSign1->SetRotation({ 0.0f, 0.3f, 0.0f });
	warningSign1->SetTexture("Texture.WarningSign");

	m_GameObjects[warningSign2->GetID()] = warningSign2;
	warningSign2->SetPosition({ 5.0f, 0.0f, 15.8f });
	warningSign2->SetScale({ 5.0f, 2.5f, 1.0f });
	warningSign2->SetRotation({ 0.0f, -0.3f, 0.0f });
	warningSign2->SetTexture("Texture.WarningSign");

	m_GameObjects[droptrap->GetID()] = droptrap;
	droptrap->SetPosition({ 0.0, 26.0, 0.0 });
	droptrap->SetScale({ 50.0, 50.0, 1.0 });
	droptrap->SetRotation({ 1.58, 0.0, 0.0 });

	m_GameObjects[lava->GetID()] = lava;
	lava->SetPosition({ 0.0, -28.0, 0.0 });
	lava->SetScale({ 50.0, 50.0, 1.0 });
	lava->SetRotation({ -1.58, 0.0, 0.0 });

	m_GameObjects[endSign->GetID()] = endSign;
	endSign->SetPosition({ 0.0f, 50.0f, 0.0f });
	endSign->SetScale({ 5.0f, 2.5f, 1.0f });
	endSign->SetTexture("Texture.Afterlife");

}

Scene_TestChamber::~Scene_TestChamber() {}

void Scene_TestChamber::Update(const double _deltaTime, const Input* _input, Configuration* _config)
{
	ControlCamera(_deltaTime, _input, _config);
	ControlGameObjects(_deltaTime, _input, _config);

	if (counter > 3)
	{
		droptrap->ActivateTrap();
		lava->ActivateLava();
		sign1->SetActive(true);
		infoSign->SetActive(false);
		warningSign1->SetActive(false);
		warningSign2->SetActive(false);
		
		if (m_CameraPosition.y <= (lava->GetPosition().y + 1))
		{
			m_IsDead = true;
			m_CameraPosition = endSign->GetPosition() + glm::vec3(0.0f, 0.0f, 3.0f);
			m_CameraForward = glm::vec3(0.0f, 0.0f, -1.0f);
			m_CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
		}
	}
}

float camSpeed = 4.0f;
glm::vec3 camDirection{ 0, 0, 0 };

void Scene_TestChamber::ControlCamera(const double _deltaTime, const Input* _input, Configuration* _config)
{

	if (!m_IsDead)
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

		#pragma endregion

		m_CameraPosition = glm::clamp(m_CameraPosition, -24.5f, 24.5f);
		m_CameraPosition.y = glm::clamp(m_CameraPosition.y, -22.0f, droptrap->GetPosition().y - 2);
	}
}


void Scene_TestChamber::ControlGameObjects(const double, const Input* _input, Configuration*)
{
	if (_input->IsButtonState(Input::Button::T, Input::Button_State::PRESSED))
	{
		std::string _str = "GameObject.Cube";
		_str += std::to_string(counter);
		Cube* _newCube = new Cube(_str.c_str());
		m_GameObjects[_newCube->GetID()] = _newCube;
		counter++;
	}
}