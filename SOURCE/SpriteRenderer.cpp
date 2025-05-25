#include "pch.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"

SpriteRenderer::SpriteRenderer() :Component(), _textrue(nullptr), _size(OG_Utils::Vector2::One)
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
	ASSERT_CRASH(_textrue != nullptr);

	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();

	if (_textrue->GetTextureType() == OG_Utils::graphcis::Texture::eTextureType::Bmp)
	{
		TransparentBlt(hdc, pos.x, pos.y,_textrue->GetWidth() * _size.x , _textrue->GetHeight() * _size.y,_textrue->GetHdc(),0,0, _textrue->GetWidth(), _textrue->GetHeight(),RGB(255,0,255));
	}
	else if (_textrue->GetTextureType() == OG_Utils::graphcis::Texture::eTextureType::Png)
	{
		Gdiplus::Graphics graphcis(hdc);
		graphcis.DrawImage(_textrue->GetImage(), Gdiplus::Rect(pos.x, pos.y, _textrue->GetWidth() * _size.x , _textrue->GetHeight() * _size.y));
	}
}

