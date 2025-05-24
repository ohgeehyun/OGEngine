#include "SceneManager.h"

std::map<const std::wstring, Scene*> SceneManager::_scenes;
Scene* SceneManager::_ActiveScene = nullptr;

void SceneManager::Init()
{
}

void SceneManager::Update()
{
	_ActiveScene->Update();
}

void SceneManager::LateUpdate()
{
	_ActiveScene->LateUpdate();
}

void SceneManager::Render(HDC hdc)
{
	_ActiveScene->Render(hdc);
}
