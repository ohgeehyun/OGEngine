﻿// Editor_Window.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#pragma once
#include "framework.h"
#include "Editor_Window.h"

#include "Common.h"
#include "../SOURCE/OGApplication.h"
#include "../OGEngine_Window/LoadScenes.h"
#include "../OGEngine_Window/LoadResources.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

OGApplication temp_Class;

//Gdi++
ULONG_PTR gpToken;
Gdiplus::GdiplusStartupInput gpsi;


// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, //프로그램의 인스턴스 핸들
                     _In_opt_ HINSTANCE hPrevInstance,//과거에 사용하던 바로 앞에 실행된 프로그램의 인스턴스 핸들,없을경우 null 호환용으로 있지만 현재는 사용하지 않음. 신경꺼도 된다고 함
                     _In_ LPWSTR    lpCmdLine, //명령줄 인자 문자열 (유니코드) main(int argc, char* argv[])의 argv와 유사 (단 문자열 통째로 전달됨)
                     _In_ int       nCmdShow) //	윈도우가 처음 화면에 나타날 방식 (최소화/최대화 등)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EDITORWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOW));

    MSG msg;

    // 기본 메시지 루프입니다:
    // GetMessage를 사용하는데 보통 엔진환경이나 게임에선 peekMessage를 쓴다고 하더라 둘의 차이는 Get은 메세지가 없으면 block대기 하지만 peek는 바로 리턴 해준다.

    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            std::wcout << L"Message: " << msg.message << std::endl;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            //메세지 없으면 처리 렌더링의 경우 메세지가 없으면 렌더링
            //temp_Class.test();
            temp_Class.Run();
        }
    }

    /* while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }*/

    //프로그램 종료시 gdiplus 삭제
    Gdiplus::GdiplusShutdown(gpToken);

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITORWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EDITORWINDOW);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   /*
        // 윈도우 클래스 이름
        // 윈도우 타이틀 (제목)
        // 윈도우 스타일
        // 윈도우의 X 위치
        // 윈도우의 Y 위치
        // 윈도우의 너비
        // 윈도우의 높이
        // 부모 윈도우 핸들 (없으면 nullptr)
        // 메뉴 핸들 (또는 자식 윈도우 ID)
        // 인스턴스 핸들
        // 추가 파라미터 (보통 nullptr)
   */
   const UINT width = 672;
   const UINT height = 846;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr); // 성공시 Handle 반환

   if (!hWnd)
   {
      return FALSE;
   }
   temp_Class.Init(hWnd, width, height);

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   Gdiplus::GdiplusStartup(&gpToken, &gpsi, NULL);

   //loadResource
   LoadResources();
   //load Scenes
   LoadScenes();
   
   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            //DC는 GDI 모듈에 의 해서 관리 된다.
            // 화면 출력에 대한 정보를 가지는 데이터 구조체
         
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
