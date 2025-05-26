#include "Animator.h"

Animator::Animator() : Component(OG_Utils::eComponentType::Animator), _Animations{}, _ActiveAnimation(nullptr), _bloop(false)
{
}

Animator::~Animator()
{
}

void Animator::Init()
{
}

void Animator::Update()
{
	if (_ActiveAnimation)
	{
		_ActiveAnimation->Update();
		if (_ActiveAnimation->IsComplete() == true && _bloop == true)
		{
			_ActiveAnimation->Reset();
		}
	}
}

void Animator::LateUpdate()
{
}

void Animator::Render(HDC hdc)
{
	_ActiveAnimation->Render(hdc);
}

void Animator::CreateAnimation(
	const std::wstring& name, 
	OG_Utils::graphcis::Texture* spriteSheet,
	Vector2 leftTop, 
	Vector2 size, 
	Vector2 offset, 
	UINT spriteLength,
	float duration)
{
	Animation* animation = nullptr;
	animation = FindAnimation(name);

	if (animation != nullptr)
		return;

	animation = new Animation();
	animation->CreateAnimation(name,spriteSheet
		,leftTop, size, offset, spriteLength, duration);

	animation->SetAnimator(this);

	_Animations.insert(std::make_pair(name,animation));
}

Animation* Animator::FindAnimation(const std::wstring& name)
{
	auto it = _Animations.find(name);
	if (it == _Animations.end())
		return nullptr;

	return it->second;
}

void Animator::PlayAnimation(const std::wstring& name, bool loop)
{
	Animation* animation = FindAnimation(name);
	if (animation == nullptr)
		return;

	_ActiveAnimation = animation;
	_ActiveAnimation->Reset();
	_bloop = loop;
}
