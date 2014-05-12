//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: CreditsState.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "Engine.h"
#include "GameStates.h"

CreditsState::CreditsState()
	: MenuState("Credits")
{

}
void CreditsState::PopulateMenu()
{
	_items.push_back(MenuItem("Back"));
}
void CreditsState::OnSelected(int Index)
{
	switch (Index)
	{
	case 0:
		Engine::RemoveState(this);
		Engine::AddState(new MainMenuState());
		break;
	}
}
void CreditsState::Draw()
{
	MenuState::Draw();
}