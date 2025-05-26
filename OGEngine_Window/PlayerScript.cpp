#include "PlayerScript.h"
#include "CustomInput.h"
#include "Transform.h"
#include "CustomTime.h"
#include "GameObject.h"
#include "Component.h"

PlayerScript::PlayerScript()
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
	if (CustomInput::GetKey(CustomInput::eKeyCode::Right))
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.x += 100.0f * CustomTime::DeltaTime();
		tr->SetPosition(pos);
	}
	if (CustomInput::GetKey(CustomInput::eKeyCode::Left))
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.x -= 100.0f * CustomTime::DeltaTime();
		tr->SetPosition(pos);
	}
	if (CustomInput::GetKey(CustomInput::eKeyCode::Up))
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.y -= 100.0f * CustomTime::DeltaTime();
		tr->SetPosition(pos);
	}
	if (CustomInput::GetKey(CustomInput::eKeyCode::Down))
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.y += 100.0f * CustomTime::DeltaTime();
		tr->SetPosition(pos);
	}
}

void PlayerScript::LateUpdate()
{
}

void PlayerScript::Render(HDC hdc)
{
}
