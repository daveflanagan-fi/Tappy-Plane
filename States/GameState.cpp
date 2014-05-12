//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: GameState.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "GameState.h"

void GameState::HandleInput()
{

}
void GameState::Update(Uint32 Delta, bool OtherScreenHasFocus)
{
	_otherScreenHasFocus = OtherScreenHasFocus;
}