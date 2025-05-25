#pragma once
#include "pch.h"
#include "GameObject.h"

class OGApplication
{
public: 
	OGApplication() ;
	~OGApplication();

	void Init(HWND mHwnd, UINT width, UINT height);
	void Run();
	void Update();
	void LateUpdate();
	void Render();

	HDC GetHdc() { return _mHdc; }

private:
	void clearRenderTarget();
	void copyRenderTarget(HDC source,HDC dset);
	void adjustWindowRect(HWND hwnd,UINT width,UINT height);
	void createBuffer(UINT width, UINT height);
	void initializeEtc();

private:
	
	HWND _mHwnd;
	HDC _mHdc;

	//백버퍼 용 비트맵
	HDC _backHdc;
	HBITMAP _backbuffer;

	//프로그램 사이즈
	UINT _width;
	UINT _height;

	//std::vector<Scene*> _Scenes;
};

