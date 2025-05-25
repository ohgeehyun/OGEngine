#include "PlayScene.h"
#include "GameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "CustomInput.h"
#include "SceneManager.h"
#include "object.h"
#include "Texture.h"
#include "Resources.h"

PlayScene::PlayScene() : background(nullptr)
{

}

PlayScene::~PlayScene()
{

}

void PlayScene::Init()
{

	background = OG_Utils::object::Instantiate<Player>(OG_Utils::eLayerType::BackGround/*,Vector2(100.0f,100.0f)*/);
	SpriteRenderer* sr = background->AddComponent<SpriteRenderer>();

	OG_Utils::graphcis::Texture* bg = Resources::Find<OG_Utils::graphcis::Texture>(L"BackGround");
	sr->SetTextrue(bg);

	//오브젝트 생성 후 레이어와 오브젝트들의 초기화 호출
	Scene::Init();
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
	//Transform* tr = background->GetComponent<Transform>();
	//tr->SetPosition(Vector2(0, 0));
}
