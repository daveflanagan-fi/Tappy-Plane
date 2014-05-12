//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Log.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __LOG_H__
#define __LOG_H__

#include <string>
#include <vector>
#include <SDL_rwops.h>

class Log
{
private:
	static SDL_RWops* File;
	static bool WriteTime;
	static std::string GetTime(void);
	static std::string spam;
	static std::vector<std::string> Logs;

public:
	static bool Initialize(void);
	static void Write(const char *msg, ...);
	static void Close(void);
};
#endif