//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: SpriteSheet.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "SpriteSheet.h"
#include "AssetStore.h"
#include "Engine.h"
#include "Log.h"

SpriteSheet::SpriteSheet()
{
	this->_width = 0;
	this->_height = 0;
	this->_texture = NULL;
}
SpriteSheet::SpriteSheet(std::string File)
{
	Load(File);
}
bool SpriteSheet::Load(std::string File)
{
	_texture = AssetStore::GetTexture(File);
	return true;
}
bool SpriteSheet::Draw(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2, Color Color)
{
	SDL_Rect Source;
	Source.x = x1;
	Source.y = y1;
	Source.w = w1;
	Source.h = h1;

	SDL_Rect Destination;
	Destination.x = x2;
	Destination.y = y2;
	Destination.w = w2;
	Destination.h = h2;

	SDL_SetTextureColorMod(_texture, Color.R, Color.G, Color.B);
	SDL_SetTextureAlphaMod(_texture, Color.A);

	if (SDL_RenderCopy(Engine::Renderer, _texture, &Source, &Destination) == 0)
		return true;
	else
	{
		Log::Write(SDL_GetError());
		return false;
	}
}
bool SpriteSheet::Draw(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2, float rotation, SDL_RendererFlip flip, Color Color)
{
	SDL_Rect Source;
	Source.x = x1;
	Source.y = y1;
	Source.w = w1;
	Source.h = h1;

	SDL_Rect Destination;
	Destination.x = x2;
	Destination.y = y2;
	Destination.w = w2;
	Destination.h = h2;

	SDL_Point origin;
	origin.x = w2 / 2;
	origin.y = h2 / 2;

	SDL_SetTextureColorMod(_texture, Color.R, Color.G, Color.B);
	SDL_SetTextureAlphaMod(_texture, Color.A);

	if (SDL_RenderCopyEx(Engine::Renderer, _texture, &Source, &Destination, rotation, &origin, flip) == 0)
		return true;
	else
	{
		Log::Write(SDL_GetError());
		return false;
	}
}
bool SpriteSheet::Draw(SDL_Rect Source, SDL_Rect Destination, Color Color)
{
	SDL_SetTextureColorMod(_texture, Color.R, Color.G, Color.B);
	SDL_SetTextureAlphaMod(_texture, Color.A);

	if (SDL_RenderCopy(Engine::Renderer, _texture, &Source, &Destination) == 0)
		return true;
	else
	{
		Log::Write(SDL_GetError());
		return false;
	}
}
void SpriteSheet::Dispose(void)
{
	if (_texture != NULL)
		SDL_DestroyTexture(_texture);
}