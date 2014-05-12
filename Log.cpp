//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Log.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include <SDL_cpuinfo.h>
#include <SDL_video.h>
#include <time.h>
#include "Engine.h"
#include "Log.h"
#include "Math.h"

SDL_RWops* Log::File = NULL;
bool Log::WriteTime = false;
std::string Log::spam = "";
std::vector<std::string> Log::Logs;

bool Log::Initialize(void)
{
	time_t rawtime;
	struct tm timeinfo;
	char buffer[255];
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	strftime(buffer, 255, "Logs/%b-%d-%Y-%H-%M-%S.dpl", &timeinfo);
	File = SDL_RWFromFile(buffer, "w");
	if (File == NULL)
		return false;

	Write("//========= Copyright © 2014, DeadPixel, All rights reserved. =========//");
	Write("// Platform: %s", SDL_GetPlatform());
	Write("// CPU Cores: %d", SDL_GetCPUCount());
	Write("// Has SSE: %s", SDL_HasSSE() ? "Yes" : "No");

	SDL_DisplayMode mode;
	for (int i = 0; i < SDL_GetNumVideoDisplays(); ++i)
	{
		SDL_GetCurrentDisplayMode(i, &mode);
		Write("// Display %d Size: %d x %d at %dHz", i + 1, mode.w, mode.h, mode.refresh_rate);
	}

	Write("//=====================================================================//");
	Write("");

	WriteTime = true;
	return true;
}
void Log::Write(const char *msg, ...)
{
	va_list args; va_start(args, msg);
	char szBuf[1024];
	vsprintf_s(szBuf, msg, args);

	std::string Line = std::string(szBuf) + '\n';
	if (Line == spam)
		return;

	spam = Line;
	if (WriteTime)
	{
		Logs.push_back(Line);
		Line = GetTime() + Line;
	}

	SDL_RWwrite(File, Line.c_str(), 1, strlen(Line.c_str()));
}
void Log::Close(void)
{
	SDL_RWclose(File);
}
std::string Log::GetTime(void)
{
	time_t rawtime;
	struct tm timeinfo;
	char buffer[100];
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	strftime(buffer, 100, "[%H:%M:%S] ", &timeinfo);
	return buffer;
}