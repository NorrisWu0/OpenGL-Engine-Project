#pragma once

#include <map>

struct GLFWwindow;

class Input
{
public:
	Input(GLFWwindow* window);
	~Input();

	enum class Button
	{
		QUIT,

		W,
		S,
		A,
		D,

		UP,
		DOWN,
		LEFT,
		RIGHT,

		E,
		Q,
		T

	};

	enum class Button_State
	{
		PRESSED,
		DOWN,
		RELEASED,
		W
	};

	void Update(GLFWwindow* window);

	void SetButtonState(Button type, Button_State state);
	bool IsButtonState(Button type, Button_State state) const;

private:
	std::map<Button, Button_State> m_ButtonState;
};