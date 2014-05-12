//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: UI.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __UI_H__
#define __UI_H__

#include "Object.h"
#include "Camera.h"
#include "Map.h"

class UI : public Object
{
private:
	Map* _map;
	Uint32 _ticks;

public:
	UI(Map* Map);

	void Update(Uint32 Delta);
	void Draw(Camera* Camera);
};
#endif