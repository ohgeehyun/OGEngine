#include "PlayScene.h"
#include "GameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "CustomInput.h"
#include "SceneManager.h"

PlayScene::PlayScene() : background(nullptr)
{

}

PlayScene::~PlayScene()
{

}

void PlayScene::Init()
{
	background = new Player();

	Transform* tr = background->AddComponent<Transform>();
	tr->SetPos(Vector2(0, 0));
	tr->SetName(L"TR");

	SpriteRenderer* sr = background->AddComponent<SpriteRenderer>();
	sr->SetName(L"SR");
	sr->ImageLoad(L"G:\\unity\\OGEngine\\Resourses\\CloudOcean.png");


	AddGameObject(background,eLayerType::BackGround);
}

void PlayScene::Update()
{
	Scene::Update();
}

void PlayScene::LateUpdate()
{
	Scene::LateUpdate();

	if (CustomInput::GetKeyDown(CustomInput::eKeyCode::N))
		SceneManager::LoadScene(L"TitleScene");
}

void PlayScene::Render(HDC hdc)
{
	Scene::Render(hdc);
	wchar_t str[50] = L"Play Scene";
	TextOut(hdc, 0, 0, str, 10);
}

void PlayScene::OnEnter()
{
}

void PlayScene::OnExit()
{
	Transform* tr = background->GetComponent<Transform>();
	tr->SetPos(Vector2(0, 0));
}
