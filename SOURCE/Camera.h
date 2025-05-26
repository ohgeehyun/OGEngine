#pragma once
#include "Component.h"
#include "GameObject.h"

class Camera : public Component
{
public:
	//카메라 기준으로 위치 계산
	Vector2 CacluatePosition(Vector2 objectPos) { return  objectPos - _distance; };

	Camera();
	~Camera();

	void Init() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;
private:
	std::vector<GameObject*> _gameObjects;
	//윈도우 창에서 카메라의 시작 위치
	Vector2 _distance;
	//화면해상도
	Vector2 _resolution;
	//카메라의 중점
	Vector2 _lookPosition;

	GameObject* _target;
};

