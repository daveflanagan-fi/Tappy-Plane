//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: GameOverState.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "Engine.h"
#include "GameOverState.h"
#include "AudioManager.h"
#include "InputManager.h"

GameOverState::GameOverState()
	: MenuState("GameOver")
{

}
void GameOverState::PopulateMenu()
{
	_texture.Load("Content/Textures/enviroment.png");
	_items.push_back(MenuItem("Try Again"));
	_items.push_back(MenuItem("Main Menu"));
}
void GameOverState::OnSelected(int Index)
{
	switch (Index)
	{
	case 0:
		Engine::ReplaceStates(new GamePlayState());
		break;
	case 1:
		Engine::ReplaceStates(new BackgroundState());
		Engine::AddState(new MainMenuState());
		break;
	}
}
void GameOverState::Draw(void)
{
	MenuState::Draw();
	_texture.Draw(0, 835, 412, 78, (854 - 412) / 2, 100, 412, 78);
}