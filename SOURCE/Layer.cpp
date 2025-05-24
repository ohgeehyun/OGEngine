#include "Layer.h"

Layer::Layer() : _objects{}
{
}

Layer::~Layer()
{
}

void Layer::Init()
{
	for (GameObject* gameObject : _objects)
	{
		if (gameObject == nullptr)
			continue;

		gameObject->Init();
	}
}

void Layer::Update()
{
	for (GameObject* gameObject : _objects)
	{
		if (gameObject == nullptr)
			continue;

		gameObject->Update();
	}
}

void Layer::LateUpdate()
{
	for (GameObject* gameObject : _objects)
	{
		if (gameObject == nullptr)
			continue;

		gameObject->LateUpdate();
	}
}

void Layer::Render(HDC hdc)
{
	for (GameObject* gameObject : _objects)
	{
		if (gameObject == nullptr)
			continue;

		gameObject->Render(hdc);
	}
}

void Layer::AddGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr)
		return;

	_objects.push_back(gameObject);
}
