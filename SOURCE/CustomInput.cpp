#include "CustomInput.h"


std::vector<CustomInput::Key> CustomInput::_Keys = {};
int ASCII[(UINT)CustomInput::eKeyCode::End] =
{
	'Q','W','E','R','T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',
	VK_LEFT,VK_RIGHT,VK_DOWN,VK_UP,
};
CustomInput::CustomInput()
{

}

CustomInput::~CustomInput()
{
}

void CustomInput::Init()
{
	for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
	{
		Key key = {};
		key.bPressed = false;
		key.state = eKeyState::None;
		key.keyCode = (eKeyCode)i;

		_Keys.push_back(key);
	}
}

void CustomInput::Update()
{
	for (size_t i = 0; i < _Keys.size(); i++)
	{
		if (GetAsyncKeyState(ASCII[i]) & 0x8000) //키가 눌림
		{
			if (_Keys[i].bPressed == true)
				_Keys[i].state = eKeyState::Pressed;
			else
				_Keys[i].state = eKeyState::Down;

			_Keys[i].bPressed = true;
		}
		else //키가 안눌렸다.
		{
			if (_Keys[i].bPressed == true)
				_Keys[i].state = eKeyState::Up;
			else
				_Keys[i].state = eKeyState::None;

			_Keys[i].bPressed = false;
		}
	}
}

bool CustomInput::GetKeyDown(eKeyCode code)
{
	return _Keys[(UINT)code].state == eKeyState::Down;
}

bool CustomInput::GetKeyUp(eKeyCode code)
{
	return  _Keys[(UINT)code].state == eKeyState::Up;
}

bool CustomInput::GetKey(eKeyCode code)
{
	return  _Keys[(UINT)code].state == eKeyState::Pressed;
}
