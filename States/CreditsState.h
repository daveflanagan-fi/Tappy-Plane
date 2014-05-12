//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: CreditsState.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __CREDITS_STATE_H__
#define __CREDITS_STATE_H__

#include "MenuState.h"

class CreditsState : public MenuState
{
public:
	CreditsState();

	void PopulateMenu();
	void OnSelected(int Index);
	void Draw();
};
#endif