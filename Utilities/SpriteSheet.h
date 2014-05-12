//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: SpriteSheet.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __SPRITE_SHEET_H__
#define __SPRITE_SHEET_H__

#include "Color.h"
#include "Vector2.h"
#include <SDL.h>
#include <string>

class SpriteSheet
{
private:
	SDL_Texture* _texture;
	int _width;
	int _height;

public:
	SpriteSheet();
	SpriteSheet(std::string File);
	bool Load(std::string File);
	bool Draw(int X, int Y, int Width, int Height, Color Color = Color::White);
	bool Draw(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2, Color Color = Color::White);
	bool Draw(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2, float rotation, SDL_RendererFlip flip = SDL_FLIP_NONE, Color Color = Color::White);
	bool Draw(SDL_Rect Position, Color Color = Color::White);
	bool Draw(SDL_Rect Source, SDL_Rect Destination, Color Color = Color::White);
	void Dispose(void);
};
#endif