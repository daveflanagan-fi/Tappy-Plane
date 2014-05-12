//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: GameOverState.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __GAME_OVER_STATE_H__
#define __GAME_OVER_STATE_H__

#include "MenuState.h"

class GameOverState : public MenuState
{
private:
	SpriteSheet _texture;

public:
	GameOverState();

	void PopulateMenu(void);
	void OnSelected(int Index);

	void Draw(void);
};
#endif