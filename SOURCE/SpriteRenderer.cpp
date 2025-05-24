#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"

SpriteRenderer::SpriteRenderer()
	: _image(nullptr)
	, _width(0)
	, _height(0)
{
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Init()
{
}

void SpriteRenderer::Update()
{
}

void SpriteRenderer::LateUpdate()
{
}

void SpriteRenderer::Render(HDC hdc)
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();

	Gdiplus::Graphics graphcis(hdc);
	graphcis.DrawImage(_image, Gdiplus::Rect(pos.x, pos.y, _width, _height));
}

void SpriteRenderer::ImageLoad(const std::wstring& path)
{
	_image = Gdiplus::Image::FromFile(path.c_str());
	_width = _image->GetWidth();
	_height = _image->GetHeight();
}
