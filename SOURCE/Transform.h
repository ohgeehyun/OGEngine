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

	void SetPosition(OG_Utils::Vector2 pos) { _position.x = pos.x; _position.y = pos.y; }
	OG_Utils::Vector2 GetPosition() { return _position; }

private:
	OG_Utils::Vector2 _position;
	

};

