#pragma once

#include "GameObject.h"

class Floor : public GameObject
{
public:
	Floor(const char* id);
	~Floor();

	virtual void SimulateAI(const double _deltaTime, const Assets* m_Assets, const Scene* _scene, const Configuration* _config) override;
	virtual void Render(const double _deltaTime, const Assets* m_Assets, const Scene* _scene, const Configuration* _config) override;
};