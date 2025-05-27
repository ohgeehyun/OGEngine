#include "Enemy.h"
#include "CustomInput.h"
#include "Transform.h"
#include "CustomTime.h"

void Enemy::Init()
{
	GameObject::Init();
}

void Enemy::Update()
{
	GameObject::Update();
}

void Enemy::LateUpdate()
{
	GameObject::LateUpdate();
	/*if (CustomInput::GetKey(CustomInput::eKeyCode::Right))
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.x += 100.0f * CustomTime::DeltaTime();
		tr->SetPosition(pos);
	}*/
}

void Enemy::Render(HDC hdc)
{
	GameObject::Render(hdc);
}