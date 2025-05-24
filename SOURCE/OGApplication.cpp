#include "OGApplication.h"
#include "CustomInput.h"
#include "CustomTime.h"
#include "SceneManager.h"

OGApplication::OGApplication() : _mHwnd(nullptr), _mHdc(nullptr), _width(0),_height(0), _backHdc(nullptr), _backbuffer(nullptr)
{

};

OGApplication::~OGApplication()
{
   
};

void OGApplication::Init(HWND mHwnd,UINT width,UINT height)
{
	adjustWindowRect(mHwnd, width, height);
	createBuffer(width, height);
	initializeEtc();

	SceneManager::Init();

};

void OGApplication::Run()
{
	Update();
    LateUpdate();
    Render();
};

void OGApplication::Update()
{
	CustomInput::Update();
	CustomTime::Update();
	
	SceneManager::Update();
};

void OGApplication::LateUpdate()
{
	SceneManager::LateUpdate();
};

void OGApplication::Render()
{
	clearRenderTarget();
	
	CustomTime::Render(_backHdc);

	SceneManager::Render(_backHdc);

	copyRenderTarget(_mHdc, _backHdc);
	
};

void OGApplication::clearRenderTarget()
{
	Rectangle(_backHdc, -1, -1, 1601, 901);
};

void OGApplication::copyRenderTarget(HDC source,HDC dset)
{
	//프론트 버퍼로 옮기기
	BitBlt(source, 0, 0, _width, _height, dset, 0, 0, SRCCOPY);
};

void OGApplication::adjustWindowRect(HWND hwnd, UINT width, UINT height)
{
	_mHwnd = hwnd;
	_mHdc = GetDC(hwnd);

	RECT rect = { 0,0,width,height };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	_width = rect.right - rect.left;
	_height = rect.bottom - rect.top;

	SetWindowPos(_mHwnd, nullptr, 0, 0, _width, _height, 0);

	ShowWindow(_mHwnd, true);

};

void OGApplication::createBuffer(UINT width, UINT height)
{
	//윈도우 해상도에 맞는 백버퍼 생성(bitmap)
	_backbuffer = CreateCompatibleBitmap(_mHdc, width, height);

	//백퍼를 가르킬 DC 생성
	_backHdc = CreateCompatibleDC(_mHdc);

	HBITMAP oldBitmap = (HBITMAP)SelectObject(_backHdc, _backbuffer);
	DeleteObject(oldBitmap);

};

void OGApplication::initializeEtc()
{
	CustomInput::Init();
	CustomTime::Init();
};