#include "Input.h"

#include <iostream>

#include <glfw3.h>

Input* input;

Input::Input(GLFWwindow* window)
{
	const auto on_key_pressed_callback = [](GLFWwindow*, int key, int, int action, int)
	{
		switch (action)
		{
		case GLFW_PRESS:
			switch (key)
			{
			case GLFW_KEY_ESCAPE:
				input->SetButtonState(Button::QUIT, Button_State::PRESSED);
				break;
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

			case GLFW_KEY_LEFT_SHIFT:
				input->SetButtonState(Button::LSHIFT, Button_State::PRESSED);
				break;
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
			case GLFW_KEY_E:
				input->SetButtonState(Button::E, Button_State::PRESSED);
				break;
			case GLFW_KEY_Q:
				input->SetButtonState(Button::Q, Button_State::PRESSED);
				break;
			case GLFW_KEY_T:
				input->SetButtonState(Button::T, Button_State::PRESSED);
				break;

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
			}
			break;

		case GLFW_RELEASE:
			switch (key)
			{
			case GLFW_KEY_ESCAPE:
				input->SetButtonState(Button::QUIT, Button_State::RELEASED);
				break;
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

			case GLFW_KEY_LEFT_SHIFT:
				input->SetButtonState(Button::LSHIFT, Button_State::RELEASED);
				break;
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
			case GLFW_KEY_E:
				input->SetButtonState(Button::E, Button_State::RELEASED);
				break;
			case GLFW_KEY_Q:
				input->SetButtonState(Button::Q, Button_State::RELEASED);
				break;
			case GLFW_KEY_T:
				input->SetButtonState(Button::T, Button_State::RELEASED);
				break;

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


			}
			break;

		}
	};

	input = this;

	glfwSetKeyCallback(window, on_key_pressed_callback);
}
Input::~Input()
{
}

void Input::Update(GLFWwindow* window)
{
	for (auto button : m_ButtonState)
		if (button.second == Button_State::PRESSED)
			m_ButtonState[button.first] = Button_State::DOWN;
		else if (button.second == Button_State::RELEASED)
			m_ButtonState[button.first] = Button_State::W;

	glfwPollEvents();

	if (glfwWindowShouldClose(window))
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

void Input::SetButtonState(Button type, Button_State state)
{
	m_ButtonState[type] = state;
};