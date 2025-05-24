#include "CustomTime.h"

LARGE_INTEGER CustomTime::_CpuFrequency = {};  //내 cpu 고유 진동수
LARGE_INTEGER CustomTime::_PrevFrequency = {}; //이전 진동수
LARGE_INTEGER CustomTime::_CurrentFrequency = {};//현재 진동수
float CustomTime::_DeltaTime = 0.0f;

void CustomTime::Init()
{
	//Cpu 고유 진동 수
	QueryPerformanceFrequency(&_CpuFrequency);

	//프로그램이 시작 시 현재 진동 수
	QueryPerformanceCounter(&_PrevFrequency);
}

void CustomTime::Update()
{
	QueryPerformanceCounter(&_CurrentFrequency);

	float differenceFrequency = static_cast<float>(_CurrentFrequency.QuadPart - _PrevFrequency.QuadPart);
	_DeltaTime = differenceFrequency / static_cast<float>(_CpuFrequency.QuadPart);
	_PrevFrequency.QuadPart = _CurrentFrequency.QuadPart;
}

void CustomTime::Render(HDC hdc)
{
	static float time = 0.0f;

	time += _DeltaTime;
	float fps = 1.0f / _DeltaTime;

	wchar_t str[50] = L"";
	swprintf_s(str,50,L"Time : %d", (int)fps);
	int length = wcsnlen_s(str,50);

	TextOut(hdc,0,0,str, length);
}
