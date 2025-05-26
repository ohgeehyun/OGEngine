#include "PlayerScript.h"
#include "CustomInput.h"
#include "Transform.h"
#include "CustomTime.h"
#include "GameObject.h"
#include "Component.h"
#include "Animator.h"

PlayerScript::PlayerScript() : _state(PlayerScript::eState::SitDown)
{
}

PlayerScript::~PlayerScript()
{
}

void PlayerScript::Init()
{

}

void PlayerScript::Update()
{
	if (_animator == nullptr)
	{
		_animator = GetOwner()->GetComponent<Animator>();
	}

	switch (_state)
	{
	case PlayerScript::eState::SitDown:
		sitDown();
		break;
	case PlayerScript::eState::Walk:
		move();
		break;
	case PlayerScript::eState::Sleep:
		break;
	case PlayerScript::eState::Attack:
		break;
	default:
		break;
	}
}

void PlayerScript::LateUpdate()
{
}

void PlayerScript::Render(HDC hdc)
{
}

void PlayerScript::sitDown()
{
	if (CustomInput::GetKey(CustomInput::eKeyCode::Right))
	{
		_state = PlayerScript::eState::Walk;
		_animator->PlayAnimation(L"RightWalk");
	}
	if (CustomInput::GetKey(CustomInput::eKeyCode::Left))
	{
		_state = PlayerScript::eState::Walk;
		_animator->PlayAnimation(L"LeftWalk");
	}
	if (CustomInput::GetKey(CustomInput::eKeyCode::Up))
	{
		_state = PlayerScript::eState::Walk;
		_animator->PlayAnimation(L"UpWalk");
	}
	if (CustomInput::GetKey(CustomInput::eKeyCode::Down))
	{
		_state = PlayerScript::eState::Walk;
		_animator->PlayAnimation(L"DownWalk");
	}
}

void PlayerScript::move()
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();

	if (CustomInput::GetKey(CustomInput::eKeyCode::Right))
	{
		pos.x += 100.0f * CustomTime::DeltaTime();
	}
	if (CustomInput::GetKey(CustomInput::eKeyCode::Left))	
	{
		pos.x -= 100.0f * CustomTime::DeltaTime();
	}
	if (CustomInput::GetKey(CustomInput::eKeyCode::Up))
	{
		pos.y -= 100.0f * CustomTime::DeltaTime();
	}
	if (CustomInput::GetKey(CustomInput::eKeyCode::Down))
	{
		pos.y += 100.0f * CustomTime::DeltaTime();
	}

	tr->SetPosition(pos);

	if (CustomInput::GetKeyUp(CustomInput::eKeyCode::Up)|| CustomInput::GetKeyUp(CustomInput::eKeyCode::Down)
		|| CustomInput::GetKeyUp(CustomInput::eKeyCode::Left)|| CustomInput::GetKeyUp(CustomInput::eKeyCode::Right))
	{
		_state = PlayerScript::eState::SitDown;
		_animator->PlayAnimation(L"SitDown",false);
	}

}
