#pragma once
#include "Resource.h"
#include "Texture.h"
#include "CustomTime.h"

class Animation : public Resource
{
public:
	struct Sprite
	{
		Vector2 leftTop;
		Vector2 size;
		Vector2 offset;
		float duration;

		Sprite() :leftTop(Vector2::Zero), size(Vector2::Zero), offset(Vector2::Zero), duration(0.0f) {}
	};

	Animation();
	~Animation();

	HRESULT Load(const std::wstring& path) override;
	void Update();
	void Render(HDC hdc);


	void CreateAnimation(const std::wstring& name,
		OG_Utils::graphcis::Texture* spriteSheet,
		Vector2 leftTop,
		Vector2 size,
		Vector2 offset,
		UINT spriteLength,
		float duration);

	void Reset();

	bool IsComplete() { return _bComplete; }
	void SetAnimator(class Animator* animator) { _animator = animator; }


private:
	class Animator* _animator;
	graphcis::Texture* _texture;

	std::vector<Sprite> _AnimationSheet;
	int _animIndex;
	float _time;
	bool _bComplete;
};

