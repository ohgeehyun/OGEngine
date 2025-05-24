#pragma once
#include "pch.h"

class Component;

class GameObject
{
public:
	GameObject();
	~GameObject();

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
		_components.push_back(comp);

		return comp;
	}

	template<typename T>
	T* GetComponent()
	{
		T* component = nullptr;
		for (Component* comp : _components)
		{
			component = static_cast<T*>(comp);
			if (component)
				break;
		}

		return component;
	}

private:
	//게임 오브젝트의 좌표
	std::vector<Component*> _components;
};

