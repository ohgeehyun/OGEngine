#pragma once
#include "Component.h"
#include "Animation.h"
#include "Texture.h"

class Animator : public Component
{
public:
	Animator();
	~Animator();

	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	void CreateAnimation(const std::wstring& name,
		OG_Utils::graphcis::Texture* spriteSheet,
		Vector2 leftTop, 
		Vector2 size,
		Vector2 offset,
		UINT spriteLength,
		float duration);

	Animation* FindAnimation(const std::wstring& name);
	void PlayAnimation(const std::wstring& name, bool loop = true);

private:
	std::map<std::wstring, Animation*> _Animations;
	Animation* _ActiveAnimation;
	bool _bloop;
};

