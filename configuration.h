#pragma once

struct Configuration
{
	bool renderWireframe = false;

	int screenWidth = 1600;
	int screenHeight = 900;
	int yUnits = 5;
	int zUnits = 10000;
	float fov = 45.f;

	enum class Projection
	{
		Orthographic,
		Perspective
	};

	Projection _projection = Projection::Perspective;

};