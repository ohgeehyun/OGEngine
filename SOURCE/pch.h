#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include <map>

//PlaySound, waveOut, timeGetTime 등)
//타이머 관련 고해상도 API
#pragma comment(lib,"winmm.lib")
#include <mmsystem.h>

//GDI+ 확장 기능 제공
#pragma comment(lib,"Msimg32.lib")

// DirectInput (DirectX) — 키보드, 마우스, 게임패드 입력 처리 DirectX의 하위 시스템 중 하나로, 고속 입력 처리를 지원 오래된Api라 현대에는 잘 사용되지 않음.
#include <dinput.h>

#pragma comment(lib,"gdiplus.lib")
#include <gdiplus.h>


#include "Vector2.h"
#include "Enums.h"

using namespace OG_Utils;




//Macro


//CRASH
#define CRASH(cause)						\
{											\
	int* crash = nullptr;				\
	__analysis_assume(crash != nullptr);	\
	*crash = 0xDEADBEEF;					\
}

#define ASSERT_CRASH(expr)			\
{									\
	if (!(expr))					\
	{								\
		CRASH("ASSERT_CRASH");		\
		__analysis_assume(expr);	\
	}								\
}

