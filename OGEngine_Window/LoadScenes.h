#pragma once
#include "../Source/SceneManager.h"
#include "PlayScene.h"
#include "TitleScene.h"

void LoadScenes()
{
	SceneManager::CreateScene<TitleScene>(L"TitleScene");
	SceneManager::CreateScene<PlayScene>(L"PlayScene");
	

	SceneManager::LoadScene(L"TitleScene");
}