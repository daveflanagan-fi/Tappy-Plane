//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: AudioManager.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __AUDIO_MANAGER_H__
#define __AUDIO_MANAGER_H__

#include <string>
#include <SDL_mixer.h>
#include <vector>

class AudioManager
{
private:
	static std::vector<Mix_Chunk*> SoundList;
	static Mix_Music* music;
	static bool Initialized;

public:
	static bool Initialize();
	static unsigned int LoadEffect(std::string File);
	static bool LoadSong(std::string File, bool AutoPlay = false);
	static void Dispose();

	static void PlayEffect(unsigned int Index);
	static void PlaySong();

	static void StopSong();
};
#endif