#pragma once
#include "pch.h"
class CustomTime
{
public:
	static void Init();
	static void Update();
	static void Render(HDC hdc);

	static float DeltaTime() { return _DeltaTime; };

private:
	static LARGE_INTEGER _CpuFrequency;  //내 cpu 고유 진동수
	static LARGE_INTEGER _PrevFrequency; //이전 진동수
	static LARGE_INTEGER _CurrentFrequency;//현재 진동수
	static float _DeltaTime;
};

