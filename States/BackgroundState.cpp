//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: BackgroundState.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "BackgroundState.h"
#include "AudioManager.h"
#include <time.h>

void BackgroundState::Load()
{
	_camera = new Camera();
	_map = new Map(_camera, true);

	char buffer[50];
	srand((unsigned int)time(NULL));
	sprintf_s(buffer, "Content/Sound/Music/%d.mp3", rand() % 3 + 1);
	AudioManager::LoadSong(buffer, true);
}
void BackgroundState::Unload()
{
	AudioManager::StopSong();
	delete _camera;
	delete _map;
}
void BackgroundState::Update(Uint32 Delta, bool OtherScreenHasFocus)
{
	GameState::Update(Delta, false);
	if (_map != NULL) _map->Update(Delta);
}
void BackgroundState::Draw()
{
	if (_map != NULL) _map->Draw(_camera);
}