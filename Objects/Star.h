//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Star.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __STAR_H__
#define __STAR_H__

#include "Object.h"
#include "Map.h"

class Star : public Object
{
private:
	Map* _map;
	float _rotation;
	float _time;
	bool _collected;

public:
	Star(Map* Map, int x, int y);

	void Update(Uint32 Delta);
	void Draw(Camera* Camera);

	bool Collides(Object* Object);
	void Collided(Object* Object);
};
#endif