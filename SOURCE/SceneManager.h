#pragma once
#include "Scene.h"

class SceneManager
{
public:
	template<typename T>
	static Scene* CreateScene(const std::wstring& name)
	{
		T* scene = new T();
		scene->SetName(name);

		_scenes.insert(std::make_pair(name,scene));
		scene->Init();

		return scene;
	}

	static Scene* LoadScene(const std::wstring& name)
	{
		if(_ActiveScene)
			_ActiveScene->OnExit();

		auto It = _scenes.find(name);

		if (It == _scenes.end())
			return nullptr;

		_ActiveScene = It->second;
		_ActiveScene->OnEnter();

		return It->second;
		
	}

	static void Init();
	static void Update();
	static void LateUpdate();
	static void Render(HDC hdc);

private:
	static std::map<const std::wstring, Scene*>  _scenes;
	static Scene* _ActiveScene;

};

