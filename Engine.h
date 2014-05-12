//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Engine.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "Engine.h"
#include "GameStates.h"
#include "Timer.h"
#include <SDL.h>
#include <vector>

class GameState;

class Engine
{
private:
	static Timer _delta;
	static Timer _fps;
	static bool _running;
	static std::vector<GameState*> _states;
	static SDL_Texture* _target;
	static bool _modified;

	static bool Initialize(void);
	static void Dispose(void);

	static void Update(Uint32 Delta);
	static void Draw(void);

public:
	static SDL_Window* Window;
	static SDL_Renderer* Renderer;
	static SDL_Rect Bounds;

	static void Resize();
	static void CalculateBounds();
	static int Run(void);
	static void Quit(void);
	static void Event(SDL_Event* Event);

	static void AddState(GameState* State);
	static void RemoveState(GameState* State);
	static void ReplaceStates(GameState* State);
};
#endif