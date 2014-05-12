//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: OptionssState.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __OPTIONS_STATE_H__
#define __OPTIONS_STATE_H__

#include "MenuState.h"

class OptionsState : public MenuState
{
public:
	OptionsState();

	void PopulateMenu();
	void OnSelected(int Index);
	void Draw();
};
#endif