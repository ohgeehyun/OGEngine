#pragma once
#include "Entity.h"
#include "GameObject.h"
#include "Layer.h"

class Scene : public Entity
{
public:
	Scene();
	~Scene();

	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	virtual void OnEnter();
	virtual void OnExit();

	void AddGameObject( GameObject* gameobj, eLayerType type);

private:
	std::vector<Layer*> _layers;
};

