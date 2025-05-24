#include "TitleScene.h"
#include "CustomInput.h"
#include "SceneManager.h"
TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	Scene::Init();
}

void TitleScene::Update()
{
	Scene::Update();
}

void TitleScene::LateUpdate()
{
	Scene::LateUpdate();

	if (CustomInput::GetKeyDown(CustomInput::eKeyCode::N))
		SceneManager::LoadScene(L"PlayScene");
}

void TitleScene::Render(HDC hdc)
{
	wchar_t str[50] = L"Title Scene";
	TextOut(hdc, 0, 0, str, 11);
}

void TitleScene::OnEnter()
{
}

void TitleScene::OnExit()
{
}
