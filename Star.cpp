//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Star.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "Star.h"
#include "Camera.h"

Star::Star(Map* Map, int x, int y)
{
	_map = Map;
	_position.X = (float)x;
	_position.Y = (float)y;
	_collected = false;

	_texture.Load("Content/Textures/enviroment.png");
	_textureX = 369;
	_textureY = 1444;
	_width = 39;
	_height = 37;
}
void Star::Update(Uint32 Delta)
{
	_time += Delta;
	float pulse = 0.5f * (1 + sin(2 * 3.14f * 1 * _time)) - 0.5f;
	_rotation += Delta * 0.1f;
	_position.Y += pulse * Delta * 0.1f;
}
void Star::Draw(Camera* Camera)
{
	if (!_visible) return;
	if (!Camera->InView(_position)) return;
	_texture.Draw(_textureX, _textureY, _width, _height, (int)(_position.X + Camera->Position().X), (int)_position.Y, _width, _height, _rotation);
}
bool Star::Collides(Object* Object)
{
	if (!_visible) return false;

	SDL_Rect A = GetBounds();
	SDL_Rect B = Object->GetBounds();

	bool xOverlap = valueInRange(A.x, B.x, B.x + B.w) || valueInRange(B.x, A.x, A.x + A.w);
	bool yOverlap = valueInRange(A.y, B.y, B.y + B.h) || valueInRange(B.y, A.y, A.y + A.h);

	return xOverlap && yOverlap;
}
void Star::Collided(Object* Object)
{
	_visible = false;
	_map->AddPoint();
}