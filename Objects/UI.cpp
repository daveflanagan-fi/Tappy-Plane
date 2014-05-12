//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: UI.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "UI.h"
#include <string>
#include <sstream>

UI::UI(Map* Map)
{
	_map = Map;
	_texture.Load("Content/Textures/enviroment.png");
}
void UI::Update(Uint32 Delta)
{
	_ticks += Delta;
}
void UI::Draw(Camera* Camera)
{
	if (!_visible) return;

	std::string score = static_cast<std::ostringstream*>(&(std::ostringstream() << _map->GetScore()))->str();

	int x = 50;
	for (unsigned int i = 0; i < score.size(); i++)
	{
		switch (score.at(i))
		{
		case '0':
			_texture.Draw(432, 1743, 53, 78, x, 50, 53 / 2, 78 / 2);
			x += 53 / 2 + 5;
			break;
		case '1':
			_texture.Draw(512, 1093, 37, 76, x, 50, 37 / 2, 76 / 2);
			x += 37 / 2 + 5;
			break;
		case '2':
			_texture.Draw(477, 1350, 51, 77, x, 50, 51 / 2, 77 / 2);
			x += 51 / 2 + 5;
			break;
		case '3':
			_texture.Draw(485, 1679, 51, 78, x, 50, 51 / 2, 78 / 2);
			x += 51 / 2 + 5;
			break;
		case '4':
			_texture.Draw(432, 1537, 55, 76, x, 50, 55 / 2, 76 / 2);
			x += 55 / 2 + 5;
			break;
		case '5':
			_texture.Draw(485, 1823, 50, 76, x, 50, 50 / 2, 76 / 2);
			x += 50 / 2 + 5;
			break;
		case '6':
			_texture.Draw(432, 1885, 53, 77, x, 50, 53 / 2, 77 / 2);
			x += 53 / 2 + 5;
			break;
		case '7':
			_texture.Draw(478, 1173, 51, 76, x, 50, 51 / 2, 76 / 2);
			x += 51 / 2 + 5;
			break;
		case '8':
			_texture.Draw(461, 899, 51, 78, x, 50, 51 / 2, 78 / 2);
			x += 51 / 2 + 5;
			break;
		case '9':
			_texture.Draw(458, 1962, 53, 77, x, 50, 53 / 2, 77 / 2);
			x += 53 / 2 + 5;
			break;
		}
	}

	if (!_map->GetTapped())
	{
		_texture.Draw(0, 1996, 85, 42, 200, 220, 85, 42);
		_texture.Draw(85, 1996, 85, 42, 10, 220, 85, 42);

		if (_ticks / 500 % 2 == 1)
			_texture.Draw(156, 1712, 40, 40, 140, 300, 40, 40);
		else
			_texture.Draw(418, 1350, 59, 59, 140 - 19, 300 - 19, 59, 59);
	}
}