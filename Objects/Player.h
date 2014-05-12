//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Player.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Object.h"
#include "Map.h"

enum PLANE_COLOR
{
	PC_BLUE,
	PC_RED,
	PC_GREEN,
	PC_YELLOW,
	PC_COUNT
};

class Player : public Object
{
private:
	Map* _map;

	bool _dead;
	float _speed;
	float _velocity;
	int _frameCounter;
	int _deadTimer;
	int _color;
	int _frame;
	Uint32 _timer;

	unsigned int _jump;
	unsigned int _die;

public:
	Player(Map* Map);

	void Update(Uint32 Delta);
	void HandleInput();
	void Draw(Camera* Camera);

	void Die();

	SDL_Rect GetBounds()
	{
		SDL_Rect bounds;
		bounds.x = (int)_position.X - 317;
		bounds.y = (int)_position.Y + 10;
		bounds.w = _width - 20;
		bounds.h = _height - 20;
		return bounds;
	}
};
#endif