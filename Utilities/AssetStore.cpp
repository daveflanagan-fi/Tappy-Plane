//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: AssetStore.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "AssetStore.h"
#include "Engine.h"
#include "Log.h"
#include <SDL_image.h>

std::map<std::string, SDL_Texture*> AssetStore::_textures = std::map<std::string, SDL_Texture*>();

SDL_Texture* AssetStore::GetTexture(std::string File)
{
	if (_textures.count(File) == 0)
	{
		SDL_Surface* surface = IMG_Load(File.c_str());
		if (surface == NULL)
		{
			Log::Write(SDL_GetError());
			return NULL;
		}

		SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::Renderer, surface);
		SDL_FreeSurface(surface);

		if (texture == NULL)
		{
			Log::Write(SDL_GetError());
			return NULL;
		}

		Log::Write("Loaded Texture '%s'", File.c_str());
		_textures[File] = texture;
	}
	return _textures.at(File);
}
SDL_Surface* AssetStore::CreateSurface(int Width, int Height)
{
	return SDL_CreateRGBSurface(0, Width, Height, 32, 0, 0, 0, 0);
}