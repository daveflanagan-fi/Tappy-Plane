//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: AUdioManager.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "SettingsManager.h"
#include "AudioManager.h"
#include "Log.h"

std::vector<Mix_Chunk*> AudioManager::SoundList;
Mix_Music* AudioManager::music = NULL;
bool AudioManager::Initialized = false;

bool AudioManager::Initialize()
{
	int audioRate = SettingsManager::Get<int>("Audio.Rate");
	Uint16 audioFormat = MIX_DEFAULT_FORMAT;
	int audioChannels = SettingsManager::Get<int>("Audio.Channels");
	int audioBuffers = SettingsManager::Get<int>("Audio.Buffers");

	int ret = Mix_OpenAudio(audioRate, audioFormat, audioChannels, audioBuffers);

	if (ret >= 0)
	{
		Mix_QuerySpec(&audioRate, &audioFormat, &audioChannels);
		Log::Write("Initialized Audio Device, R: %d - F: %d - C: %d", audioRate, audioFormat, audioChannels);
		Initialized = true;
		return true;
	}
	else
	{
		Log::Write("Unable To Open Audio Device! - %s", Mix_GetError());
		return false;
	}
	return true;
}
unsigned int AudioManager::LoadEffect(std::string File)
{
	if (!Initialized) return -1;

	Mix_Chunk* TempSound = NULL;

	if ((TempSound = Mix_LoadWAV(File.c_str())) == NULL)
	{
		Log::Write("Error Loading Sound Effect - %s", Mix_GetError());
		return -1;
	}

	Log::Write("Loaded Sound Effect '%s'", File.c_str());
	SoundList.push_back(TempSound);
	return SoundList.size() - 1;
}
bool AudioManager::LoadSong(std::string File, bool AutoPlay)
{
	if (!Initialized || SettingsManager::Get<int>("Audio.Music.Volume") == 0) return false;

	if (music != NULL)
	{
		Mix_HaltMusic();
		Mix_FreeMusic(music);
		music = NULL;
	}

	if ((music = Mix_LoadMUS(File.c_str())) == NULL)
	{
		Log::Write("Error Loading Song - %s", Mix_GetError());
		return false;
	}

	Log::Write("Loaded Song '%s'", File.c_str());
	if (AutoPlay) PlaySong();
	return true;
}
void AudioManager::Dispose()
{
	for (unsigned int i = 0; i < SoundList.size(); i++)
		Mix_FreeChunk(SoundList[i]);
	SoundList.clear();

	Mix_HaltMusic();
	Mix_FreeMusic(music);
	music = NULL;

	Mix_CloseAudio();
	Log::Write("Audio Device Shutdown Successfully");
}
void AudioManager::PlayEffect(unsigned int Index)
{
	if (!Initialized) return;
	if (Index < 0 || Index >= SoundList.size()) return;
	if (SoundList[Index] == NULL) return;
	Mix_PlayChannel(-1, SoundList[Index], 0);
	Mix_Volume(-1, SettingsManager::Get<int>("Audio.Effects.Volume"));
}
void AudioManager::PlaySong()
{
	if (!Initialized || music == NULL || SettingsManager::Get<int>("Audio.Music.Volume") == 0) return;
	Mix_HaltMusic();
	Mix_PlayMusic(music, -1);
	Mix_VolumeMusic(SettingsManager::Get<int>("Audio.Music.Volume"));
}
void AudioManager::StopSong()
{
	if (!Initialized || music == NULL) return;
	Mix_HaltMusic();
}