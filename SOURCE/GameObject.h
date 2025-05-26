#pragma once
#include "pch.h"

class Component;

class GameObject
{
public:
	GameObject();
	~GameObject();

	void InitTransform();

	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	template<typename T>
	T* AddComponent()
	{
		T* comp = new T();
		comp->SetOwner(this);
		comp->Init();
		_components[(UINT)comp->GetType()] = comp;

		return comp;
	}

	template<typename T>
	T* GetComponent()
	{
		T* component = nullptr;
		for (Component* comp : _components)
		{
			component = dynamic_cast<T*>(comp);
			if (component)
				break;
		}

		return component;
	}

private:
	std::vector<Component*> _components;
};

