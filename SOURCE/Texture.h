#pragma once
#include "Resource.h"


namespace OG_Utils::graphcis
{
	class Texture : public Resource
	{
	public:
		enum class  eTextureType
		{
			Bmp,
			Png,
			None
		};

		Texture();
		~Texture();

		HRESULT Load(const std::wstring& path) override;

		UINT		 GetWidth() { return _width; }
		UINT		 GetHeight() { return _height; }
		HDC			 GetHdc() { return _hdc; }
		eTextureType GetTextureType() {return _textureType;}
		Gdiplus::Image* GetImage() { return _image; }

	private:
		eTextureType _textureType;
		Gdiplus::Image* _image;
		HBITMAP _bitmap;
		HDC _hdc;
		
		UINT _width;
		UINT _height;
	};
}
