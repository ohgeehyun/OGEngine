#pragma once
#include "../Source/GameObject.h"

class Enemy : public GameObject
{
public:
	void Init() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

private:

};
