//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: GamePlayState.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "GameStates.h"
#include "AudioManager.h"
#include "Engine.h"
#include <time.h>

void GamePlayState::Load()
{
	_camera = new Camera();
	_map = new Map(_camera);

	char buffer[50];
	srand((unsigned int)time(NULL));
	sprintf_s(buffer, "Content/Sound/Music/%d.mp3", rand() % 3 + 1);
	AudioManager::LoadSong(buffer, true);
}
void GamePlayState::Unload()
{
	AudioManager::StopSong();
	delete _camera;
	delete _map;
}
void GamePlayState::Update(Uint32 Delta, bool OtherScreenHasFocus)
{
	GameState::Update(Delta, false);
	_map->Update(Delta);
}
void GamePlayState::HandleInput()
{
	_map->HandleInput();
	if (_map->GetGameover())
		Engine::AddState(new GameOverState());
}
void GamePlayState::Draw()
{
	_map->Draw(_camera);
}