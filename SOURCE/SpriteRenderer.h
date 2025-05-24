#pragma once
#include "Entity.h"
#include "Component.h"

class SpriteRenderer : public Component
{
public:
	SpriteRenderer();
	~SpriteRenderer();

	void Init() override;
	void Update()  override;
	void LateUpdate()  override;
	void Render(HDC hdc)  override;

	void ImageLoad(const std::wstring& path);

private:
	Gdiplus::Image* _image;
	UINT _width;
	UINT _height;
};

