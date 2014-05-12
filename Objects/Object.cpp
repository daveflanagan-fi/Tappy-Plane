//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Object.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "Camera.h"
#include "Engine.h"
#include "Log.h"
#include "Object.h"

Object::Object()
{
	_position = Vector2(0, 0);
	_visible = true;
}

void Object::Dispose()
{
	_texture.Dispose();
}

void Object::Update(Uint32 Delta)
{
}

void Object::HandleInput()
{
}

void Object::Draw(Camera* Camera)
{
}

void Object::SetPosition(int x, int y)
{
	_position = Vector2((float)x, (float)y);
}

bool Object::valueInRange(int value, int min, int max)
{
	return (value >= min) && (value <= max);
}

bool Object::LineRectangleIntersect(SDL_Rect rect, int x0, int y0, int x1, int y1)
{
	int m = (y1 - y0) / (x1 - x0);
	int c = y0 - (m * x0);

	int top_intersection = 0;
	int bottom_intersection = 0;
	int toptrianglepoint = 0;
	int bottomtrianglepoint = 0;

	if (m > 0)
	{
		top_intersection = (m * rect.x + c);
		bottom_intersection = (m * (rect.x + rect.w) + c);
	}
	else
	{
		top_intersection = (m * (rect.x + rect.w) + c);
		bottom_intersection = (m * rect.x + c);
	}

	if (y0 < y1)
	{
		toptrianglepoint = y0;
		bottomtrianglepoint = y1;
	}
	else
	{
		toptrianglepoint = y1;
		bottomtrianglepoint = y0;
	}

	int topoverlap;
	int botoverlap;

	topoverlap = top_intersection>toptrianglepoint ? top_intersection : toptrianglepoint;
	botoverlap = bottom_intersection<bottomtrianglepoint ? bottom_intersection : bottomtrianglepoint;

	return topoverlap < botoverlap && !(botoverlap < rect.y || topoverlap > rect.y + rect.h);
}

SDL_Rect Object::GetBounds()
{
	SDL_Rect bounds;
	bounds.x = (int)_position.X;
	bounds.y = (int)_position.Y;
	bounds.w = _width;
	bounds.h = _height;
	return bounds;
}

SDL_Rect Object::GetTextureBounds()
{
	SDL_Rect bounds;
	bounds.x = _textureX;
	bounds.y = _textureY;
	bounds.w = _width;
	bounds.h = _height;
	return bounds;
}