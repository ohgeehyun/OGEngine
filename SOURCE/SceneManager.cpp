#include "SceneManager.h"

std::map<const std::wstring, Scene*> SceneManager::_scenes;
Scene* SceneManager::_ActiveScene = nullptr;

Scene* SceneManager::LoadScene(const std::wstring& name)
{
	if (_ActiveScene)
		_ActiveScene->OnExit();
	
	auto It = _scenes.find(name);
	
	if (It == _scenes.end())
		return nullptr;
	
	_ActiveScene = It->second;
	_ActiveScene->OnEnter();
	
	return It->second;
}

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
