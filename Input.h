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
		LSHIFT,

		W, S, A, D,
		E, Q, T,

		NumPad8,
		NumPad2,
		NumPad4,
		NumPad6,

		K1, K2, K3, K4, K5, 
		K6, K7, K8, K9, K0,

		UP, DOWN,
		LEFT, RIGHT,

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

	void SetCursorPosition(double _x, double _y);
	std::pair<double, double> CurrentCursorPosition() const;
	std::pair<double, double> PreviousCursorPosition() const;
	
private:
	std::map<Button, Button_State> m_ButtonState;

	double m_CurrentCursorX;
	double m_CurrentCursorY;

	double m_PreviousCursorX;
	double m_PreviousCursorY;

};