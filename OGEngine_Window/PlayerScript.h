#pragma once
#include "Script.h"

class PlayerScript : public Script
{
public:
	enum class eState
	{
		SitDown,
		Walk,
		Sleep,
		Attack
	};

	PlayerScript();
	~PlayerScript();

	void Init() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

private:
	void sitDown();
	void move();

private:
	eState _state;
	class Animator* _animator;
};

