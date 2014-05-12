//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: AssetStore.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __ASSET_STORE_H__
#define __ASSET_STORE_H__

#include <SDL.h>
#include <string>
#include <map>

class AssetStore
{
private:
	static std::map<std::string, SDL_Texture*> _textures;

public:
	static SDL_Texture* GetTexture(std::string File);

	static SDL_Surface* CreateSurface(int Width, int Height);
};
#endif