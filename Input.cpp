#include "Input.h"


Input* input;

Input::Input(GLFWwindow* _window)
{
	const auto _onKeyPressCallback = [](GLFWwindow*, int _key, int, int _action, int)
	{
		switch (_action)
		{
		case GLFW_PRESS:
			switch (_key)
			{
			case GLFW_KEY_ESCAPE:
				input->SetButtonState(Button::QUIT, Button_State::PRESSED);
				break;
			case GLFW_KEY_LEFT_SHIFT:
				input->SetButtonState(Button::LSHIFT, Button_State::PRESSED);
				break;

			#pragma region A - Z
			case GLFW_KEY_W:
				input->SetButtonState(Button::W, Button_State::PRESSED);
				break;
			case GLFW_KEY_A:
				input->SetButtonState(Button::A, Button_State::PRESSED);
				break;
			case GLFW_KEY_S:
				input->SetButtonState(Button::S, Button_State::PRESSED);
				break;
			case GLFW_KEY_D:
				input->SetButtonState(Button::D, Button_State::PRESSED);
				break;
			case GLFW_KEY_E:
				input->SetButtonState(Button::E, Button_State::PRESSED);
				break;
			case GLFW_KEY_Q:
				input->SetButtonState(Button::Q, Button_State::PRESSED);
				break;
			case GLFW_KEY_T:
				input->SetButtonState(Button::T, Button_State::PRESSED);
				break;
			case GLFW_KEY_V:
				input->SetButtonState(Button::V, Button_State::PRESSED);
				break;

			#pragma endregion
							
			#pragma region Num Pad
			case GLFW_KEY_KP_8:
				input->SetButtonState(Button::NumPad8, Button_State::PRESSED);
				break;
			case GLFW_KEY_KP_2:
				input->SetButtonState(Button::NumPad2, Button_State::PRESSED);
				break;
			case GLFW_KEY_KP_4:
				input->SetButtonState(Button::NumPad4, Button_State::PRESSED);
				break;
			case GLFW_KEY_KP_6:
				input->SetButtonState(Button::NumPad6, Button_State::PRESSED);
				break;

			#pragma endregion

			#pragma region Number key
			case GLFW_KEY_1:
				input->SetButtonState(Button::K1, Button_State::PRESSED);
				break;
			case GLFW_KEY_2:
				input->SetButtonState(Button::K2, Button_State::PRESSED);
				break;
			case GLFW_KEY_3:
				input->SetButtonState(Button::K3, Button_State::PRESSED);
				break;
			case GLFW_KEY_4:
				input->SetButtonState(Button::K4, Button_State::PRESSED);
				break;
			case GLFW_KEY_5:
				input->SetButtonState(Button::K5, Button_State::PRESSED);
				break;
			case GLFW_KEY_6:
				input->SetButtonState(Button::K6, Button_State::PRESSED);
				break;
			case GLFW_KEY_7:
				input->SetButtonState(Button::K7, Button_State::PRESSED);
				break;
			}
			break;

			#pragma endregion

			#pragma region Arrow Keys
			case GLFW_KEY_UP:
				input->SetButtonState(Button::UP, Button_State::PRESSED);
				break;
			case GLFW_KEY_DOWN:
				input->SetButtonState(Button::DOWN, Button_State::PRESSED);
				break;
			case GLFW_KEY_LEFT:
				input->SetButtonState(Button::LEFT, Button_State::PRESSED);
				break;
			case GLFW_KEY_RIGHT:
				input->SetButtonState(Button::RIGHT, Button_State::PRESSED);
				break;

			#pragma endregion

		case GLFW_RELEASE:
			switch (_key)
			{
			case GLFW_KEY_ESCAPE:
				input->SetButtonState(Button::QUIT, Button_State::RELEASED);
				break;
			case GLFW_KEY_LEFT_SHIFT:
				input->SetButtonState(Button::LSHIFT, Button_State::RELEASED);
				break;

			#pragma region A - Z
			case GLFW_KEY_W:
				input->SetButtonState(Button::W, Button_State::RELEASED);
				break;
			case GLFW_KEY_A:
				input->SetButtonState(Button::A, Button_State::RELEASED);
				break;
			case GLFW_KEY_S:
				input->SetButtonState(Button::S, Button_State::RELEASED);
				break;
			case GLFW_KEY_D:
				input->SetButtonState(Button::D, Button_State::RELEASED);
			break; 
			case GLFW_KEY_E:
				input->SetButtonState(Button::E, Button_State::RELEASED);
				break;
			case GLFW_KEY_Q:
				input->SetButtonState(Button::Q, Button_State::RELEASED);
				break;
			case GLFW_KEY_T:
				input->SetButtonState(Button::T, Button_State::RELEASED);
				break;
			case GLFW_KEY_V:
				input->SetButtonState(Button::V, Button_State::RELEASED);
				break;

			#pragma endregion

			#pragma region Numpad
			case GLFW_KEY_KP_8:
				input->SetButtonState(Button::NumPad8, Button_State::RELEASED);
				break;
			case GLFW_KEY_KP_2:
				input->SetButtonState(Button::NumPad2, Button_State::RELEASED);
				break;
			case GLFW_KEY_KP_4:
				input->SetButtonState(Button::NumPad4, Button_State::RELEASED);
				break;
			case GLFW_KEY_KP_6:
				input->SetButtonState(Button::NumPad6, Button_State::RELEASED);
				break;

			#pragma endregion

			#pragma region Number Key
			case GLFW_KEY_1:
				input->SetButtonState(Button::K1, Button_State::RELEASED);
				break;
			case GLFW_KEY_2:
				input->SetButtonState(Button::K2, Button_State::RELEASED);
				break;
			case GLFW_KEY_3:
				input->SetButtonState(Button::K3, Button_State::RELEASED);
				break;
			case GLFW_KEY_4:
				input->SetButtonState(Button::K4, Button_State::RELEASED);
				break;
			case GLFW_KEY_5:
				input->SetButtonState(Button::K5, Button_State::RELEASED);
				break;
			case GLFW_KEY_6:
				input->SetButtonState(Button::K6, Button_State::RELEASED);
				break;
			case GLFW_KEY_7:
				input->SetButtonState(Button::K7, Button_State::RELEASED);
				break;

			#pragma endregion

			#pragma region Arror Key
			case GLFW_KEY_UP:
				input->SetButtonState(Button::UP, Button_State::RELEASED);
				break;
			case GLFW_KEY_DOWN:
				input->SetButtonState(Button::DOWN, Button_State::RELEASED);
				break;
			case GLFW_KEY_LEFT:
				input->SetButtonState(Button::LEFT, Button_State::RELEASED);
				break;
			case GLFW_KEY_RIGHT:
				input->SetButtonState(Button::RIGHT, Button_State::RELEASED);
				break;

			#pragma endregion

			}
			break;

		}
	};
	glfwSetKeyCallback(_window, _onKeyPressCallback);

	const auto _onCursorMovedCallback = [](GLFWwindow*, double _x, double _y) 
	{
		input->SetCursorPosition(_x, _y);
	};
	
	m_CurrentCursorX = 0.0;
	m_CurrentCursorY = 0.0;
	m_PreviousCursorX = 0.0;
	m_PreviousCursorY = 0.0;

	glfwSetCursorPosCallback(_window, _onCursorMovedCallback);
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	input = this;

}
Input::~Input()
{
}

void Input::Update(GLFWwindow* _window)
{
	m_PreviousCursorX = m_CurrentCursorX;
	m_PreviousCursorY = m_CurrentCursorY;

	for (auto _button : m_ButtonState)
		if (_button.second == Button_State::PRESSED)
			m_ButtonState[_button.first] = Button_State::DOWN;
		else if (_button.second == Button_State::RELEASED)
			m_ButtonState[_button.first] = Button_State::W;

	glfwPollEvents();

	if (glfwWindowShouldClose(_window))
		input->SetButtonState(Button::QUIT, Button_State::PRESSED);
}

bool Input::IsButtonState(Button type, Button_State state) const
{
	if (m_ButtonState.find(type) == m_ButtonState.end())
		if (state == Button_State::W)
			return true;
		else
			return false;

	return m_ButtonState.find(type)->second == state;
}

void Input::SetCursorPosition(double _x, double _y)
{
	if (m_PreviousCursorX == 0.0 && m_PreviousCursorY == 0.0) 
	{
		m_PreviousCursorX = _x;
		m_PreviousCursorY = _y;
	}

	m_CurrentCursorX = _x;
	m_CurrentCursorY = _y;
}

std::pair<double, double> Input::CurrentCursorPosition() const { return {m_CurrentCursorX, m_CurrentCursorY}; }
std::pair<double, double> Input::PreviousCursorPosition() const { return {m_PreviousCursorX, m_PreviousCursorY}; }
void Input::SetButtonState(Button type, Button_State state) { m_ButtonState[type] = state; };