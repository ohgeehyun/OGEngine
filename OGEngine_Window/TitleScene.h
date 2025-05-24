#pragma once
#include "../Source/Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();
public:
	void Init() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

	void OnEnter() override;
	void OnExit() override;
};

