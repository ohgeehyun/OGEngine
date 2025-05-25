#include "Texture.h"
#include "OGApplication.h"

extern OGApplication temp_Class;

OG_Utils::graphcis::Texture::Texture() : Resource(OG_Utils::eResourceType::Texture)
{
}

OG_Utils::graphcis::Texture::~Texture()
{
}

HRESULT OG_Utils::graphcis::Texture::Load(const std::wstring& path)
{
	
	std::wstring ext = path.substr(path.find_last_of(L".") + 1);

	if (ext == L"bmp")
	{
		_textureType = eTextureType::Bmp;
		_bitmap = (HBITMAP)LoadImageW(nullptr,path.c_str(),IMAGE_BITMAP,0,0, LR_LOADFROMFILE | LR_CREATEDIBSECTION );

		if (_bitmap == nullptr)
			return S_FALSE;

		BITMAP info = {};
		GetObject(_bitmap, sizeof(BITMAP), &info);

		_width = info.bmWidth;
		_height = info.bmHeight;

		HDC mainDC = temp_Class.GetHdc();
		_hdc = CreateCompatibleDC(mainDC);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(_hdc,_bitmap);
		DeleteObject(oldBitmap);

	}
	else if (ext == L"png")
	{
		_textureType = eTextureType::Png;
		_image = Gdiplus::Image::FromFile(path.c_str());

		if(_image == nullptr)
			return S_FALSE;

		_width = _image->GetWidth();
		_height = _image->GetHeight();
	}

	return S_OK;
}
