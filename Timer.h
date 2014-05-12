//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Timer.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __TIMER_H__
#define __TIMER_H__

#include <SDL.h>

class Timer
{
private:
	Uint32 StartTicks;
	Uint32 PausedTicks;

	bool Paused;
	bool Started;

public:
	Timer(void);

	void Start(void);
	void Stop(void);
	void Pause(void);
	void Unpause(void);

	Uint32 GetTicks(void);

	bool IsStarted(void);
	bool IsPaused(void);
};
#endif