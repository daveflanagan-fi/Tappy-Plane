//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: MenuState.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __MENU_STATE_H__
#define __MENU_STATE_H__

#include "GameState.h"
#include "SpriteSheet.h"
#include <vector>

class MenuItem
{
private:
	std::string _text;
	SpriteSheet _texture;
	SDL_Texture* _font;
	int _width;
	int _height;

public:
	MenuItem(std::string Text);
	void Destroy();
	void Draw(int X, int Y);
	void SetText(std::string Text);
};

class MenuState : public GameState
{
protected:
	std::vector<MenuItem> _items;
	unsigned int _select;
	std::string _title;

public:
	MenuState(std::string Title);

	virtual void Load(void);
	virtual void Unload(void);

	virtual void HandleInput();

	virtual void Update(Uint32 Delta, bool OtherScreenHasFocus);
	virtual void Draw(void);

	virtual void PopulateMenu() = 0;
	virtual void OnSelected(int Index) = 0;
};
#endif