#pragma once
#include "../Source/Scene.h"

class Player;

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();
public:
	void Init() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

	void OnEnter() override;
	void OnExit() override;
private:
	Player* _player;
};

