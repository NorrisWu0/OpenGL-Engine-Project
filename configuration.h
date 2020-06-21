#pragma once

class Configuration
{
	public:
	bool RenderWireframe = false;

	int ScreenWidth = 1600;
	int ScreenHeight = 900;
	int YUnits = 5;
	int ZUnits = 10000;
	float FOV = 90.f;

	enum class ProjectionType
	{
		Orthographic,
		Perspective
	};

	ProjectionType Projection = ProjectionType::Perspective;
	
	void SetProjection(ProjectionType _type);

};