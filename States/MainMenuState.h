//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: MainMenuState.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __MAIN_MENU_STATE_H__
#define __MAIN_MENU_STATE_H__

#include "MenuState.h"

class MainMenuState : public MenuState
{
protected:
	SDL_Texture* _title;

public:
	MainMenuState();

	void PopulateMenu();
	void OnSelected(int Index);
	void Draw();
};
#endif