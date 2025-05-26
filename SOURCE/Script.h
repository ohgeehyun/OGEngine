#pragma once
#include "Component.h"

class Script : public Component
{
public:
	Script();
	~Script();

	void Init() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

private:

};

