//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: BackgroundState.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __BACKGROUND_STATE_H__
#define __BACKGROUND_STATE_H__

#include "GameState.h"
#include "Camera.h"
#include "Map.h"

class BackgroundState : public GameState
{
private:
	Map* _map;
	Camera* _camera;

public:
	void Load(void);
	void Unload(void);

	void Update(Uint32 Delta, bool OtherScreenHasFocus);
	void Draw(void);
};
#endif