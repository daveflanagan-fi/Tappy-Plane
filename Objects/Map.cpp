//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Map.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "Map.h"
#include "Camera.h"
#include "Engine.h"
#include "Player.h"
#include "Spike.h"
#include "Star.h"
#include "UI.h"
#include "AudioManager.h"
#include <time.h>

Map::Map(Camera* Camera, bool Background)
{
	_texture.Load("Content/Textures/enviroment.png");
	_collect = AudioManager::LoadEffect("Content/Sound/collect.wav");

	x = 800;
	_score = 0;

	_hasTapped = Background;
	_player = new Player(this);
	_player->SetVisible(!Background);
	_objects.push_back(_player);
	Camera->Follow(_player);

	_ui = new UI(this);
	_ui->SetVisible(!Background);

	srand((unsigned int)time(NULL));
	_type = rand() % MT_COUNT;
}
void Map::Update(Uint32 Delta)
{
	if (_gameOver) return;

	for (unsigned int i = 0; i < _objects.size(); i++)
	{
		Object* obj = _objects.at(i);
		if (obj == NULL) continue;

		if (_player->GetVisible() && obj->Collides(_player))
			obj->Collided(_player);

		obj->Update(Delta);
	}

	if (_hasTapped)
	{
		while (x < _player->GetPosition().X + 1000)
		{
			invert = !invert;
			float size = (float)(rand() % 40 + 90) / 100.f;
			_objects.push_back(new Spike(this, x, invert, size));

			if (size > 1.f)
			{
				_objects.push_back(new Star(this, (int)(x - 10), (int)(invert ? 270 / size : 210 * size)));
				_objects.push_back(new Star(this, (int)(x + ((108 / 2) / size) - 10), (int)(invert ? 300 / size : 180 * size)));
				_objects.push_back(new Star(this, (int)(x + (((108 / 2) / size) * 2)) - 10, (int)(invert ? 270 / size : 210 * size)));
			}
			else
				_objects.push_back(new Star(this, (int)(x + ((108 / 2) / size) - 10), (int)(invert ? 300 / size : 180 * size)));

			x += rand() % 200 + 300;
		}
	}

	_ui->Update(Delta);
}
void Map::HandleInput()
{
	for (unsigned int i = 0; i < _objects.size(); i++)
	{
		Object* obj = _objects.at(i);
		if (obj == NULL) continue;
		obj->HandleInput();
	}
}
void Map::Draw(Camera* Camera)
{
	int x = (int)(Camera->Position().X * -.6f) % 854;
	int fx = (int)(Camera->Position().X * -1.f) % 854;

	_texture.Draw(0, 355, 800, 480, 0 - x, 0, 854, 480);
	_texture.Draw(0, 355, 800, 480, 0 - x + 854, 0, 854, 480);

	for (unsigned int i = 0; i < _objects.size(); i++)
		_objects.at(i)->Draw(Camera);

	switch (_type)
	{
	default:
	case MT_GRASS:
		_texture.Draw(0, 142, 808, 71, 0 - fx, 409, 854, 71);
		_texture.Draw(0, 142, 808, 71, 0 - fx + 854, 409, 854, 71);
		break;
	case MT_DIRT:
		_texture.Draw(0, 0, 808, 71, 0 - fx, 409, 854, 71);
		_texture.Draw(0, 0, 808, 71, 0 - fx + 854, 409, 854, 71);
		break;
	case MT_ICE:
		_texture.Draw(0, 71, 808, 71, 0 - fx, 409, 854, 71);
		_texture.Draw(0, 71, 808, 71, 0 - fx + 854, 409, 854, 71);
		break;
	//case MT_ROCK:
	//	_texture.Draw(0, 284, 808, 71, 0 - fx, 409, 854, 71);
	//	_texture.Draw(0, 284, 808, 71, 0 - fx + 854, 409, 854, 71);
	//	break;
	case MT_SNOW:
		_texture.Draw(0, 213, 808, 71, 0 - fx, 409, 854, 71);
		_texture.Draw(0, 213, 808, 71, 0 - fx + 854, 409, 854, 71);
		break;
	}

	_ui->Draw(Camera);
}
void Map::AddPoint()
{
	AudioManager::PlayEffect(_collect);
	_score++;
}
void Map::SetTapped(bool Tapped)
{
	_hasTapped = Tapped; 
	x = (int)_player->GetPosition().X + 500;
}
void Map::SetGameOver(bool GameOver)
{
	_gameOver = GameOver;
}