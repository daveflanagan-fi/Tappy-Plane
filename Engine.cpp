//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Engine.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "Engine.h"
#include "GameStates.h"
#include "Log.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "SettingsManager.h"
#include <SDL_ttf.h>

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "SDL2_mixer.lib")
#pragma comment(lib, "SDL2_ttf.lib")

Timer Engine::_delta = Timer();
Timer Engine::_fps = Timer();
SDL_Window* Engine::Window = NULL;
SDL_Renderer* Engine::Renderer = NULL;
bool Engine::_running = false;
std::vector<GameState*> Engine::_states = std::vector<GameState*>();
SDL_Texture* Engine::_target = NULL;
bool Engine::_modified = false;
SDL_Rect Engine::Bounds;

int main(int argc, char **argv)
{
	return Engine::Run();
}

int Engine::Run(void)
{
	_running = Initialize();

	SDL_Event event;
	_delta.Start();
	while (_running)
	{
		while (SDL_PollEvent(&event))
			Event(&event);

		_fps.Start();
		Update(_delta.GetTicks());
		_delta.Start();
		Draw();

		Uint32 ticks = _fps.GetTicks();
		if (ticks < 1000 / 30)
			SDL_Delay((1000 / 30) - ticks);
	}

	Dispose();
	return 0;
}
bool Engine::Initialize(void)
{
	TTF_Init();
	Log::Initialize();
	SettingsManager::Load();

	Window = SDL_CreateWindow("Fenix", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SettingsManager::Get<int>("Graphics.Resolution.Width"), SettingsManager::Get<int>("Graphics.Resolution.Height"), SettingsManager::Get<bool>("Graphics.Resolution.Fullscreen") ? SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (Window == NULL)
	{
		Log::Write(SDL_GetError());
		return false;
	}

	CalculateBounds();

	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

	if (Renderer == NULL)
	{
		Log::Write(SDL_GetError());
		return false;
	}

	_target = SDL_CreateTexture(Renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 854, 480);

	if (_target == NULL)
	{
		Log::Write(SDL_GetError());
		return false;
	}

	Log::Write("Engine Initialized Successfully");

	AudioManager::Initialize();
	AddState(new BackgroundState());
	AddState(new MainMenuState());
	return true;
}
void Engine::Resize()
{
	Log::Write("Resizing Screen");

	SDL_DisplayMode mode;
	SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(Window), &mode);
	mode.w = SettingsManager::Get<int>("Graphics.Resolution.Width");
	mode.h = SettingsManager::Get<int>("Graphics.Resolution.Height");

	SDL_SetWindowDisplayMode(Window, &mode);
	SDL_SetWindowSize(Window, mode.w, mode.h);

	SDL_RaiseWindow(Window);
	SDL_SetWindowPosition(Window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	CalculateBounds();
}
void Engine::CalculateBounds()
{
	float oldRatio = 854.f / 480.f;
	float newRatio = SettingsManager::Get<float>("Graphics.Resolution.Width") / SettingsManager::Get<float>("Graphics.Resolution.Height");

	if (oldRatio > newRatio)
	{
		Bounds.w = SettingsManager::Get<int>("Graphics.Resolution.Width");
		Bounds.h = (int)((float)Bounds.w / oldRatio);
	}
	else
	{
		Bounds.h = SettingsManager::Get<int>("Graphics.Resolution.Height");
		Bounds.w = (int)((float)Bounds.h * oldRatio);
	}

	Bounds.x = (SettingsManager::Get<int>("Graphics.Resolution.Width") - Bounds.w) / 2;
	Bounds.y = (SettingsManager::Get<int>("Graphics.Resolution.Height") - Bounds.h) / 2;

}
void Engine::Dispose(void)
{
	for (unsigned int i = 0; i < _states.size(); i++)
		_states.at(i)->Unload();
	SDL_DestroyTexture(_target);
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	TTF_Quit();
	SettingsManager::Save();
	AudioManager::Dispose();
	Log::Write("Engine Shutdown Successfully");
	Log::Close();
}

void Engine::Update(Uint32 Delta)
{
	bool otherStateHasFocus = false;
	for (std::vector<GameState*>::reverse_iterator it = _states.rbegin(); it != _states.rend(); ++it)
	{
		if (_modified) break;
		if (!(*it)->IsVisible()) continue;

		(*it)->Update(Delta, otherStateHasFocus);

		if (!otherStateHasFocus)
		{
			if (_modified) break;
			otherStateHasFocus = true;
			(*it)->HandleInput();
		}
	}

	_modified = false;
	InputManager::Update();
}
void Engine::Draw(void)
{
	SDL_SetRenderTarget(Renderer, _target);
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
	SDL_RenderClear(Renderer);

	for (std::vector<GameState*>::iterator it = _states.begin(); it != _states.end(); ++it)
	{
		if ((*it)->IsVisible())
			(*it)->Draw();
	}

	SDL_SetRenderTarget(Renderer, NULL);
	SDL_RenderCopy(Renderer, _target, NULL, &Bounds);
	SDL_RenderPresent(Renderer);
}

void Engine::Event(SDL_Event* event)
{
	switch (event->type)
	{
	case SDL_QUIT:
		_running = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		InputManager::ButtonDown(event->button.button);
		break;
	case SDL_MOUSEBUTTONUP:
		InputManager::ButtonUp(event->button.button);
		break;
	case SDL_KEYDOWN:
		InputManager::KeyDown(event->key.keysym.scancode);
		break;
	case SDL_KEYUP:
		InputManager::KeyUp(event->key.keysym.scancode);
		break;
	case SDL_MOUSEMOTION:
		InputManager::MouseMove(event->motion.x, event->motion.y);
		break;
	}
}
void Engine::AddState(GameState* State)
{
	_modified = true;
	_states.push_back(State);
	State->Load();
}
void Engine::RemoveState(GameState* State)
{
	for (std::vector<GameState*>::iterator it = _states.begin(); it != _states.end(); it++)
	{
		if ((*it) == State)
		{
			_modified = true;
			(*it)->Unload();
			delete (*it);
			_states.erase(it);
			break;
		}
	}
}
void Engine::ReplaceStates(GameState* State)
{
	for (std::vector<GameState*>::iterator it = _states.begin(); it != _states.end(); it++)
	{
		_modified = true;
		(*it)->Unload();
		delete (*it);
	}
	_states.clear();
	AddState(State);
}
void Engine::Quit(void)
{
	_running = false;
}