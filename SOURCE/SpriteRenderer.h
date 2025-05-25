#pragma once
#include "Entity.h"
#include "Component.h"
#include "Texture.h"

class SpriteRenderer : public Component
{
public:
	SpriteRenderer();
	~SpriteRenderer();

	void Init() override;
	void Update()  override;
	void LateUpdate()  override;
	void Render(HDC hdc)  override;

	void SetTextrue(graphcis::Texture* texture) { _textrue = texture; }
	void SetSize(Vector2 size) { _size = size; };
private:
	OG_Utils::graphcis::Texture* _textrue;
	OG_Utils::Vector2 _size;
};

