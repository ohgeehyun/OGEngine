#pragma once
#include "pch.h"
#include "GameObject.h" 
#include "Entity.h"

class Component : public Entity
{
public:
	Component(OG_Utils::eComponentType type);
	~Component();

	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	void SetOwner(GameObject* owner) { _owner = owner; }
	GameObject* GetOwner() { return _owner; }

	OG_Utils::eComponentType GetType() { return _type; }

private:
	GameObject* _owner;
	OG_Utils::eComponentType _type;
};

