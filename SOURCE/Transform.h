#pragma once
#include "Entity.h"
#include "Component.h"
#include "Vector2.h"

struct Pos
{
	int _x;
	int _y;
};

class Transform : public Component
{
public:
	Transform();
	~Transform();

	void Init() override;
	void Update()  override;
	void LateUpdate()  override;
	void Render(HDC hdc)  override;
	
	OG_Utils::Vector2 GetPosition() { return _position; }
	float GetRotation() { return _Rotation; }
	OG_Utils::Vector2 GetScale() { return _Scale; }

	void SetPosition(OG_Utils::Vector2 pos) { _position.x = pos.x; _position.y = pos.y; }
	void SetRotation(float rotate) { _Rotation = rotate; }
	void SetScale(Vector2 scale) { _Scale = scale; }

private:
	OG_Utils::Vector2 _position;
	OG_Utils::Vector2 _Scale;
	float _Rotation;
};

