#pragma once
#include "Entity.h"
#include "GameObject.h"

class Layer
{
public:
	Layer();
	~Layer();

	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	void AddGameObject(GameObject* gameObject);

private:
	OG_Utils::eLayerType _Type;
	std::vector<GameObject*> _objects;
};

