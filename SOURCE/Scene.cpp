#include "Scene.h"
#include <algorithm> 

Scene::Scene() : _layers{}
{
	_layers.resize((UINT)eLayerType::Max);
	for (size_t i =0; i<(UINT)eLayerType::Max; i++)
	{
		_layers[i] = new Layer();
	}
}

Scene::~Scene()
{
}

void Scene::Init()
{
	for (Layer* layer : _layers)
	{
		if (layer == nullptr)
			continue;

		layer->Init();
	}
}

void Scene::Update()
{
	for (Layer* layer : _layers)
	{
		if (layer == nullptr)
			continue;

		layer->Update();
	}
}

void Scene::LateUpdate()
{
	for (Layer* layer : _layers)
	{
		if (layer == nullptr)
			continue;

		layer->LateUpdate();
	}
}

void Scene::Render(HDC hdc)
{
	for (Layer* layer : _layers)
	{
		if (layer == nullptr)
			continue;

		layer->Render(hdc);
	}
}

void Scene::AddGameObject( GameObject* gameobj,  eLayerType type)
{

	_layers[(UINT)type]->AddGameObject(gameobj);
}

void Scene::OnEnter()
{

}

void Scene::OnExit()
{

}
