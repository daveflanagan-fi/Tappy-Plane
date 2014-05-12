//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Spike.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __SPIKE_H__
#define __SPIKE_H__

#include "Object.h"
#include "Map.h"

class Spike : public Object
{
private:
	bool _top;
	Map* _map;
	float _scale;
	float _bob;

public:
	Spike(Map* Map, int x, bool Top, float Scale = 1);

	void Draw(Camera* Camera);

	bool Collides(Object* Object);
	void Collided(Object* Object);
};

#endif