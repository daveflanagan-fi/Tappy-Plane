//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: GamePlayState.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __GAME_PLAY_STATE_H__
#define __GAME_PLAY_STATE_H__

#include "GameState.h"
#include "Camera.h"
#include "Map.h"

class GamePlayState : public GameState
{
private:
	Map* _map;
	Camera* _camera;

public:
	void Load(void);
	void Unload(void);

	void Update(Uint32 Delta, bool OtherScreenHasFocus);
	void HandleInput();
	void Draw(void);
};
#endif