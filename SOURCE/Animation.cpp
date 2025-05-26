#include "Animation.h"
#include "Animator.h"
#include "Transform.h"
#include "Renderer.h"
#include "Camera.h"

Animation::Animation() :
	Resource(OG_Utils::eResourceType::Animation),
	_animator(nullptr),
	_AnimationSheet{},
	_animIndex(-1),
	_time(0.0f),
	_bComplete(false),
	_texture(nullptr)
{

}

Animation::~Animation()
{
}

HRESULT Animation::Load(const std::wstring& path)
{
	return E_NOTIMPL;
}

void Animation::Update()
{
	//루프 완료면 return
	if (_bComplete)
		return;

	_time += CustomTime::DeltaTime();

	if (_AnimationSheet[_animIndex].duration < _time)
	{
		_time = 0.0f;
		if (_animIndex < _AnimationSheet.size() -1)
		{
			_animIndex++;
		}
		else
		{
			_bComplete = true;
		}
	}
}

void Animation::Render(HDC hdc)
{
	//알파블렌드를 쓸 수 있는 조건 : 해당 이미지에 알파 채널이 있어야한다.
	//AlphaBlend(125,);
	if (_texture == nullptr)
		return;

	GameObject* gameObj =  _animator->GetOwner();
	Transform* tr = gameObj->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();
	float rot = tr->GetRotation();
	Vector2 scale = tr->GetScale();
	
	if (renderer::mainCamera)
		pos = renderer::mainCamera->CacluatePosition(pos);

	Sprite sprite = _AnimationSheet[_animIndex];
	graphcis::Texture::eTextureType type = _texture->GetTextureType();

	if (type == graphcis::Texture::eTextureType::Bmp)
	{
		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255; // alpha값 0(transparent) ~ 255(Opaque)

		HDC imgHdc = _texture->GetHdc();

		AlphaBlend(hdc, 
			pos.x - (sprite.size.x/2.0f),
			pos.y - (sprite.size.y/2.0f),
			sprite.size.x * scale.x,
			sprite.size.y * scale.y,
			imgHdc,
			sprite.leftTop.x,
			sprite.leftTop.y,
			sprite.size.x,
			sprite.size.y,
			func);
	}
	else if (type == graphcis::Texture::eTextureType::Png)
	{
		//원하는 픽셀을 투명화 범위 지정 가능
		Gdiplus::ImageAttributes imegeAtt = {};
		
		//투명화 시킬 픽셀의 색 범위
		imegeAtt.SetColorKey(Gdiplus::Color(230,230,230),Gdiplus::Color(255,255,255));

		Gdiplus::Graphics graphics(hdc);

		graphics.TranslateTransform(pos.x,pos.y);
		graphics.RotateTransform(rot);
		graphics.TranslateTransform(-pos.x,-pos.y);

		graphics.DrawImage(
			_texture->GetImage()
			,Gdiplus::Rect
			(
			 pos.x - (sprite.size.x / 2.0f),
			 pos.y - (sprite.size.y / 2.0f),
			 sprite.size.x * scale.x,
			 sprite.size.y * scale.y
			)
			,sprite.leftTop.x
			,sprite.leftTop.y
			,sprite.size.x
			,sprite.size.y
			,Gdiplus::UnitPixel
			,&imegeAtt
		);

	}
}

void Animation::CreateAnimation(const std::wstring& name, OG_Utils::graphcis::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
{
	_texture = spriteSheet;
	for (size_t i = 0; i < spriteLength; i++)
	{
		Sprite sprite = {};
		sprite.leftTop.x = leftTop.x + (size.x * i);
		sprite.leftTop.y = leftTop.y;
		sprite.size = size;
		sprite.offset = offset;
		sprite.duration = duration;

		_AnimationSheet.push_back(sprite);
	}
}

void Animation::Reset()
{
	_time = 0.0f;
	_animIndex = 0;
	_bComplete = false;
}
