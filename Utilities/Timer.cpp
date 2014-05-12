//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Timer.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "Timer.h"

Timer::Timer(void)
{
	StartTicks = 0;
	PausedTicks = 0;
	Paused = false;
	Started = false;
}
void Timer::Start()
{
	Started = true;
	Paused = false;
	StartTicks = SDL_GetTicks();
}
void Timer::Stop()
{
	Started = false;
	Paused = false;
}
Uint32 Timer::GetTicks()
{
	if (Started == true)
	if (Paused == true)
		return PausedTicks;
	else
		return SDL_GetTicks() - StartTicks;
	return 0;
}
void Timer::Pause()
{
	if ((Started == true) && (Paused == false))
	{
		Paused = true;
		PausedTicks = SDL_GetTicks() - StartTicks;
	}
}
void Timer::Unpause()
{
	if (Paused == true)
	{
		Paused = false;
		StartTicks = SDL_GetTicks() - PausedTicks;
		PausedTicks = 0;
	}
}
bool Timer::IsStarted()
{
	return Started;
}
bool Timer::IsPaused()
{
	return Paused;
}