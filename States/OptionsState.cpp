//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: OptionsState.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "Engine.h"
#include "GameStates.h"

OptionsState::OptionsState()
	: MenuState("Options")
{

}
void OptionsState::PopulateMenu()
{
	_items.push_back(MenuItem("Back"));
}
void OptionsState::OnSelected(int Index)
{
	switch (Index)
	{
	case 0:
		Engine::RemoveState(this);
		Engine::AddState(new MainMenuState());
		break;
	}
}
void OptionsState::Draw()
{
	MenuState::Draw();
}