//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: MainMenuState.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "Engine.h"
#include "GameStates.h"
#include "AssetStore.h"

MainMenuState::MainMenuState()
	: MenuState("Main Menu")
{

}
void MainMenuState::PopulateMenu()
{
	_items.push_back(MenuItem("Play Game"));
	_items.push_back(MenuItem("Options"));
	_items.push_back(MenuItem("Credits"));
	_items.push_back(MenuItem("Quit"));

	_title = AssetStore::GetTexture("Content/Textures/title.png");
}
void MainMenuState::OnSelected(int Index)
{
	switch (Index)
	{
	case 0:
		Engine::ReplaceStates(new GamePlayState());
		break;
	case 1:
		Engine::RemoveState(this);
		Engine::AddState(new OptionsState());
		break;
	case 2:
		Engine::RemoveState(this);
		Engine::AddState(new CreditsState());
		break;
	case 3:
		Engine::Quit();
		break;
	}
}
void MainMenuState::Draw()
{
	SDL_Rect Destination;
	Destination.x = (854 - 344) / 2;
	Destination.y = 50;
	Destination.w = 344;
	Destination.h = 136;

	SDL_RenderCopy(Engine::Renderer, _title, NULL, &Destination);

	MenuState::Draw();
}