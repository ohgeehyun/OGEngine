#pragma once
#include "pch.h"
#include "Layer.h"
#include "GameObject.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Component.h"
#include "Transform.h"

namespace OG_Utils::object
{
	template <typename T>
	static T* Instantiate(OG_Utils::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(OG_Utils::eLayerType type, OG_Utils::Vector2 pos)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(pos);

		return gameObject;
	}

}