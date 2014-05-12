//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: MenuState.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "MenuState.h"
#include "AssetStore.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "Engine.h"
#include "Log.h"
#include <SDL_ttf.h>

MenuItem::MenuItem(std::string Text)
{
	_text = Text;
	_texture.Load("Content/Textures/ui.png");

	TTF_Font *font;
	font = TTF_OpenFont("Content/kenvector_future.ttf", 16);
	if (!font)
	{
		Log::Write(TTF_GetError());
		return;
	}

	SDL_Surface* surface = TTF_RenderText_Solid(font, Text.c_str(), { 0, 0, 0 });
	_width = surface->w;
	_height = surface->h;
	_font = SDL_CreateTextureFromSurface(Engine::Renderer, surface);
	SDL_FreeSurface(surface);
	TTF_CloseFont(font);
}
void MenuItem::Destroy()
{
	SDL_DestroyTexture(_font);
}
void MenuItem::Draw(int X, int Y)
{
	_texture.Draw(190, 0, 190, 45, X, Y, 190, 45);

	SDL_Rect Destination;
	Destination.x = X + ((190 - _width) / 2);
	Destination.y = Y + ((45 - _height) / 2);
	Destination.h = _height;
	Destination.w = _width;

	SDL_RenderCopy(Engine::Renderer, _font, NULL, &Destination);
	//TextManager::Draw(Vector2((float)X, (float)Y), _text, Selected ? Color::Yellow : Color::White);
}
void MenuItem::SetText(std::string Text)
{
	_text = Text;
}

MenuState::MenuState(std::string Title)
{
	_title = Title;
}
void MenuState::Load(void)
{
	_items = std::vector<MenuItem>();
	_select = AudioManager::LoadEffect("Content/Sound/click.wav");
	PopulateMenu();
}
void MenuState::Unload(void)
{
	for (std::vector<MenuItem>::reverse_iterator it = _items.rbegin(); it != _items.rend(); ++it)
		(*it).Destroy();
}
void MenuState::HandleInput()
{
	if (InputManager::IsButtonPress(1))
	{
		int x = 30;
		int y = 400;

		Vector2 pos = InputManager::GetMousePosition();

		if (pos.X > 210) return;
		if (pos.X < 30) return;
		if (pos.Y > 445) return;

		int i = _items.size() - 1;
		for (std::vector<MenuItem>::reverse_iterator it = _items.rbegin(); it != _items.rend(); ++it)
		{
			if (pos.Y < y + 45 && pos.Y > y)
			{
				AudioManager::PlayEffect(_select);
				OnSelected(i);
				return;
			}
			i--;
			y -= 60;
		}
	}
}
void MenuState::Update(Uint32 Delta, bool OtherScreenHasFocus)
{
	GameState::Update(Delta, OtherScreenHasFocus);
}
void MenuState::Draw(void)
{
	int x = 30;
	int y = 400;
	for (std::vector<MenuItem>::reverse_iterator it = _items.rbegin(); it != _items.rend(); ++it)
	{
		(*it).Draw(x, y);
		y -= 60;
	}
}