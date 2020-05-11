#pragma once
#include "GameObject.h"
class SecureServ :
	public GameObject
{
public:
	SecureServ(const char* id);
	~SecureServ();

	virtual void SimulateAI(const double _deltaTime, const Assets* _assets, const Scene* _scene, const Configuration* _config, const Input* _input) override;
	virtual void Render(const double _deltaTime, const Assets* m_Assets, const Scene* _scene, const Configuration* _config) override;
};