//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: InputManager.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "InputManager.h"
#include "Log.h"

int InputManager::LastMouseX = 0;
int InputManager::LastMouseY = 0;
int InputManager::MouseX = 0;
int InputManager::MouseY = 0;

char InputManager::ButtonStates[12];
char InputManager::PrevButtonStates[12];
char InputManager::KeyStates[512];
char InputManager::PrevKeyStates[512];

void InputManager::MouseMove(int X, int Y)
{
	MouseX = X;
	MouseY = Y;
}

void InputManager::ButtonDown(Uint8 Button)
{
	ButtonStates[Button] = 1;
}
void InputManager::ButtonUp(Uint8 Button)
{
	ButtonStates[Button] = 0;
}
void InputManager::KeyDown(SDL_Scancode Key)
{
	KeyStates[(int)Key] = 1;
}
void InputManager::KeyUp(SDL_Scancode Key)
{
	KeyStates[(int)Key] = 0;
}

void InputManager::Update(void)
{
	for (int i = 0; i < 512; i++)
		PrevKeyStates[i] = KeyStates[i];
	for (int i = 0; i < 12; i++)
		PrevButtonStates[i] = ButtonStates[i];
}

bool InputManager::IsButtonDown(Uint8 Button)
{
	return ButtonStates[Button] == 1;
}
bool InputManager::IsButtonPress(Uint8 Button)
{
	return ButtonStates[Button] == 1 && PrevButtonStates[Button] == 0;
}
bool InputManager::IsKeyDown(SDL_Scancode Key)
{
	return KeyStates[(int)Key] == 1;
}
bool InputManager::IsKeyPress(SDL_Scancode Key)
{
	return KeyStates[(int)Key] == 1 && PrevKeyStates[(int)Key] == 0;
}
SDL_Scancode InputManager::GetPressedKey()
{
	for (int i = 0; i < 512; i++)
	{
		if (KeyStates[i] == 1 && PrevKeyStates[i] == 0)
			return (SDL_Scancode)i;
	}
	return SDL_NUM_SCANCODES;
}