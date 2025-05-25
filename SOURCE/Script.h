#pragma once
#include "Component.h"

class Script : Component
{

public:
	void Init() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

private:

};

