#pragma once
#include "pch.h"
#include "GameObject.h" 
#include "Entity.h"

class Component : public Entity
{
public:
	Component();
	~Component();

	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	void SetOwner(GameObject* owner) { _owner = owner; }
	GameObject* GetOwner() { return _owner; }

private:
	GameObject* _owner;
};

