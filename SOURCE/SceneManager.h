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

		_ActiveScene = scene;
		
		_scenes.insert(std::make_pair(name,scene));
		scene->Init();

		return scene;
	}

	static Scene* LoadScene(const std::wstring& name);

	static void Init();
	static void Update();
	static void LateUpdate();
	static void Render(HDC hdc);

	static Scene* GetActiveScene() { return _ActiveScene; }

private:
	static std::map<const std::wstring, Scene*>  _scenes;
	static Scene* _ActiveScene;

};

