#include "Player.h"
#include "CustomInput.h"
#include "Transform.h"
#include "CustomTime.h"

void Player::Init()
{
	GameObject::Init();
}

void Player::Update()
{
	GameObject::Update();
}

void Player::LateUpdate()
{
	GameObject::LateUpdate();
	if (CustomInput::GetKey(CustomInput::eKeyCode::Right))
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.x += 100.0f * CustomTime::DeltaTime();
		tr->SetPosition(pos);
	}
}

void Player::Render(HDC hdc)
{
	GameObject::Render(hdc);
}