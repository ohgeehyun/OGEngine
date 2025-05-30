#pragma once
#include "pch.h"

class CustomInput
{
public:
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class eKeyCode
	{
		Q,W,E,R,T,Y,U,I,O,P,A,S,D,F,G,H,J,K,L,Z,X,C,V,B,N,M,Left,Right,Down,Up,End,
	};

public :


	CustomInput();
	~CustomInput();
	struct Key
	{
		eKeyCode keyCode;
		eKeyState state;
		bool bPressed;
	};

	static void Init();
	static void Update();

	static bool GetKeyDown(eKeyCode code);
	static bool GetKeyUp(eKeyCode code);
	static bool GetKey(eKeyCode code);
	
private:
	eKeyState _state ;
	static std::vector<Key> _Keys;
};


