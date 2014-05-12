//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: GameState.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <SDL.h>

class GameState
{
private:
	bool _otherScreenHasFocus;

public:
	virtual void Load(void) = 0;
	virtual void Unload(void) = 0;

	virtual void HandleInput();

	virtual void Update(Uint32 Delta, bool OtherScreenHasFocus);
	virtual void Draw(void) = 0;

	virtual bool IsVisible() { return !_otherScreenHasFocus; }
};
#endif