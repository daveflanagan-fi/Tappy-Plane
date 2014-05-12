//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Spike.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "Spike.h"
#include "Engine.h"
#include "Camera.h"

Spike::Spike(Map* Map, int X, bool Top, float Scale)
{
	_scale = Scale;
	_top = Top;
	_position.X = (float)X;
	_position.Y = _top ? 0 : 480 - (239 / _scale);
	_texture.Load("Content/Textures/enviroment.png");
	_map = Map;

	switch (Map->GetType())
	{
	default:
	case MT_GRASS:
		_textureX = Top ? 264 : 0;
		_textureY = Top ? 986 : 1757;
		break;
	case MT_DIRT:
		_textureX = Top ? 324 : 114;
		_textureY = Top ? 1489 : 1400;
		break;
	case MT_ICE:
		_textureX = Top ? 222 : 216;
		_textureY = Top ? 1250 : 1639;
		break;
	case MT_SNOW:
		_textureX = Top ? 108 : 324;
		_textureY = Top ? 1757 : 1728;
		break;
	//case MT_ROCK:
	//	_textureX = Top ? 324 : 114;
	//	_textureY = Top ? 1489 : 1400;
	//	break;
	}

	_textureWidth = 108;
	_textureHeight = 239;

	_width = (int)(108 / _scale);
	_height = (int)(239 / _scale);
}
void Spike::Draw(Camera* Camera)
{
	if (!_visible) return;
	if (!Camera->InView(_position)) return;
	_texture.Draw(_textureX, _textureY, _textureWidth, _textureHeight, (int)(_position.X + Camera->Position().X), (int)_position.Y, _width, _height);
}
bool Spike::Collides(Object* Object)
{
	SDL_Rect A = GetBounds();
	SDL_Rect B = Object->GetBounds();

	bool xOverlap = valueInRange(A.x, B.x, B.x + B.w) || valueInRange(B.x, A.x, A.x + A.w);
	bool yOverlap = valueInRange(A.y, B.y, B.y + B.h) || valueInRange(B.y, A.y, A.y + A.h);

	if (xOverlap && yOverlap)
	{
		int x0 = A.x;
		int y0 = _top ? 0 : 480;
		int x1 = A.x + (A.w / 2);
		int y1 = _top ? A.h : 480 - A.h;
		int x2 = A.x + A.w;
		int y2 = _top ? 0 : 480;

		return LineRectangleIntersect(B, x0, y0, x1, y1)
			|| LineRectangleIntersect(B, x1, y1, x2, y2)
			|| LineRectangleIntersect(B, x2, y2, x0, y0);
	}

	return false;
}
void Spike::Collided(Object* Object)
{
	Object->Die();
}