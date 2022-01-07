//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "InputManager.h"
#include "Keyboard.h"


void KeyboardTest()
{
	Keyboard* key = InputManager::GetKeyboard();

	// Quick and dirty test, if these work the rest do.
	// ---> try a,s,d,<SPACE> keys
	std::string a;
	std::string b;
	std::string c;
	std::string d;

	if (key->GetKeyState(Keyboard::KEY_A))
	{
		a = " A";
	}

	if (key->GetKeyState(Keyboard::KEY_S))
	{
		b = " S";
	}

	if (key->GetKeyState(Keyboard::KEY_D))
	{
		c = " D";
	}

	if (key->GetKeyState(Keyboard::KEY_SPACE))
	{
		d = " <SPACE>";
	}

	std::string total = a + b + c + d;
	Trace::out("Key:%s \n", total.c_str());
}


void MouseTest()
{
	Mouse* mouse = InputManager::GetMouse();

	// Quick and dirty test, if these work the rest do.
	// --> try move the mouse inside the window, click right, click left
	std::string a;
	std::string b;

	float xPos;
	float yPos;

	// get mouse position
	mouse->GetCursor(xPos, yPos);

	// read mouse buttons
	if (mouse->GetKeyState(Mouse::BUTTON_RIGHT))
	{
		a = " <right>";
	}

	if (mouse->GetKeyState(Mouse::BUTTON_LEFT))
	{
		b = " <left>";
	}

	std::string total = a + b;


	Trace::out("mouse:(%d,%d)%s \n", (int)xPos, (int)yPos, total.c_str());
}


// --- End of File ---