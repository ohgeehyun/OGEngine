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
#include "PlayerScript.h"
#include "Camera.h"
#include "Renderer.h"
#include "Animator.h"
#include "Enemy.h"

PlayScene::PlayScene() : _player(nullptr)
{

}

PlayScene::~PlayScene()
{

}

void PlayScene::Init()
{
	//main camera
	GameObject* camera =  object::Instantiate<GameObject>(OG_Utils::eLayerType::None,Vector2(344.0f,442.0f));
	Camera* cameraComp = camera->AddComponent<Camera>();
	OG_Utils::renderer::mainCamera = cameraComp;
	

	_player = OG_Utils::object::Instantiate<Player>(OG_Utils::eLayerType::Particle/*,Vector2(100.0f,100.0f)*/);
	_player->AddComponent<PlayerScript>();
	/*SpriteRenderer* sr = _player->AddComponent<SpriteRenderer>();
	sr->SetSize(Vector2(3.0f,3.0f));*/
	/*OG_Utils::graphcis::Texture* packmanTexure = Resources::Find<OG_Utils::graphcis::Texture>(L"MapleEffect");
	Animator* animator = _player->AddComponent<Animator>();
	animator->CreateAnimation(L"CatFrontMove", packmanTexure,Vector2(0.0f,0.0f),Vector2(386.0f,246.0f),Vector2::Zero,8,0.1f);
	animator->PlayAnimation(L"CatFrontMove",true);*/

	OG_Utils::graphcis::Texture* packmanTexure = Resources::Find<OG_Utils::graphcis::Texture>(L"Cat");
	Animator* animator = _player->AddComponent<Animator>();
	animator->CreateAnimation(L"DownWalk", packmanTexure, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"RightWalk", packmanTexure, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"UpWalk", packmanTexure, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"LeftWalk", packmanTexure, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"SitDown", packmanTexure, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"Grooming", packmanTexure, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

	animator->PlayAnimation(L"SitDown", false);

	_player->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
	_player->GetComponent<Transform>()->SetScale(Vector2(2.0f,2.0f));
	_player->GetComponent<Transform>()->SetRotation(30.0f);

	//sr->SetTextrue(packmanTexure);

	GameObject* bg = OG_Utils::object::Instantiate<GameObject>(OG_Utils::eLayerType::Player/*,Vector2(100.0f,100.0f)*/);
	SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
	//bgsr->SetSize(Vector2(3.0f, 3.0f));
	OG_Utils::graphcis::Texture* bgTextrue = Resources::Find<OG_Utils::graphcis::Texture>(L"Bubble");
	bgsr->SetTextrue(bgTextrue);

	//cat

	Enemy* enemy = OG_Utils::object::Instantiate<Enemy>(OG_Utils::eLayerType::Particle/*,Vector2(100.0f,100.0f)*/);
	enemy->AddComponent<PlayerScript>();

	OG_Utils::graphcis::Texture* packmanTexure = Resources::Find<OG_Utils::graphcis::Texture>(L"Cat");
	Animator* animator = _player->AddComponent<Animator>();
	animator->CreateAnimation(L"DownWalk", packmanTexure, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"RightWalk", packmanTexure, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"UpWalk", packmanTexure, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"LeftWalk", packmanTexure, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"SitDown", packmanTexure, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"Grooming", packmanTexure, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

	animator->PlayAnimation(L"SitDown", false);

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
	/*wchar_t str[50] = L"Play Scene";
	TextOut(hdc, 0, 0, str, 10);*/
}

void PlayScene::OnEnter()
{
}

void PlayScene::OnExit()
{
	//Transform* tr = background->GetComponent<Transform>();
	//tr->SetPosition(Vector2(0, 0));
}
