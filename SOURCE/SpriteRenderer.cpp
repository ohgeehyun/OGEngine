#include "pch.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "Renderer.h"
#include "Camera.h"

SpriteRenderer::SpriteRenderer() :Component(OG_Utils::eComponentType::SpriteRenderer), _textrue(nullptr), _size(OG_Utils::Vector2::One)
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
	float rot = tr->GetRotation();
	Vector2 scale = tr->GetScale();

	Vector2 cameraPos = renderer::mainCamera->CacluatePosition(pos);
	pos = renderer::mainCamera->CacluatePosition(pos);

	if (_textrue->GetTextureType() == OG_Utils::graphcis::Texture::eTextureType::Bmp)
	{
		TransparentBlt(hdc
			, pos.x
			, pos.y
			,_textrue->GetWidth() * _size.x * scale.x
			,_textrue->GetHeight() * _size.y * scale.y
			,_textrue->GetHdc(),0,0
			,_textrue->GetWidth()
			,_textrue->GetHeight()
			,RGB(255,0,255));
	}
	else if (_textrue->GetTextureType() == OG_Utils::graphcis::Texture::eTextureType::Png)
	{

		//원하는 픽셀을 투명화 범위 지정 가능
		Gdiplus::ImageAttributes imegeAtt = {};

		//투명화 시킬 픽셀의 색 범위
		imegeAtt.SetColorKey(Gdiplus::Color(200, 200, 200), Gdiplus::Color(255, 255, 255));

		Gdiplus::Graphics graphcis(hdc);

		graphcis.TranslateTransform(pos.x, pos.y);
		graphcis.RotateTransform(rot);
		graphcis.TranslateTransform(-pos.x, -pos.y);

		graphcis.DrawImage(_textrue->GetImage()
			,Gdiplus::Rect
			(
				pos.x, 
				pos.y,
				_textrue->GetWidth() * _size.x * scale.x,
				_textrue->GetHeight() * _size.y * scale.y
			)
			,0
			,0
			,_textrue->GetWidth(),_textrue->GetHeight()
			,Gdiplus::UnitPixel
			,nullptr/*&imegeAtt*/);
	}
}

