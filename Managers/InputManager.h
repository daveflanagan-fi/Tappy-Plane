//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: InputManager.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include "Vector2.h"
#include <Sdl.h>

class InputManager
{
	friend class Engine;

private:
	static int LastMouseX;
	static int LastMouseY;
	static int MouseX;
	static int MouseY;

	static char KeyStates[512];
	static char PrevKeyStates[512];
	static char ButtonStates[12];
	static char PrevButtonStates[12];

	static void ButtonDown(Uint8 Button);
	static void ButtonUp(Uint8 Button);
	static void MouseMove(int X, int Y);
	static void KeyDown(SDL_Scancode Key);
	static void KeyUp(SDL_Scancode Key);

public:
	static void Update(void);

	static Vector2 GetMousePosition() { return Vector2((float)MouseX, (float)MouseY); }

	static bool IsButtonPress(Uint8 Button);
	static bool IsButtonDown(Uint8 Button);
	static bool IsKeyPress(SDL_Scancode Key);
	static bool IsKeyDown(SDL_Scancode Key);
	static SDL_Scancode GetPressedKey();
};
#endif