//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Player.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "Player.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "Engine.h"
#include "Camera.h"

Player::Player(Map* Map)
{
	_jump = AudioManager::LoadEffect("Content/Sound/jump.wav");
	_die = AudioManager::LoadEffect("Content/Sound/die.wav");
	_texture.Load("Content/Textures/enviroment.png");
	_map = Map;

	_position.X = 500;
	_position.Y = 200;

	_width = 88;
	_height = 73;
	_speed = 0.2f;
	_dead = false;
	_deadTimer = 0;
	_color = rand() % PC_COUNT;
}
void Player::Die()
{
	if (_dead) return;
	_map->SetGameOver(true);
	_dead = true;
	AudioManager::PlayEffect(_die);
}
void Player::Update(Uint32 Delta)
{
	if (_dead) return;
	_timer += Delta;
	_position.X += Delta * _speed;
	_frameCounter += Delta;
	
	if (_visible && _map->GetTapped()) _velocity -= 0.001f * Delta;
	if (_velocity < -.5f) _velocity = -.5f;
	if (_velocity > .4f) _velocity = .4f;

	_position.Y -= _velocity * Delta;

	if (_position.Y <= 0)
		Die();

	if (_position.Y > 320)
	{
		int x = (int)(_position.X + (_width / 2) - 327) % 854;
		int ground = 0;

		if (x <= 35) ground = 37;
		else if (x <= 43) ground = 34;
		else if (x <= 96) ground = 28;
		else if (x <= 143) ground = 32;
		else if (x <= 166) ground = 50;
		else if (x <= 263) ground = 65;
		else if (x <= 324) ground = 55;
		else if (x <= 370) ground = 44;
		else if (x <= 395) ground = 51;
		else if (x <= 462) ground = 59;
		else if (x <= 497) ground = 43;
		else if (x <= 538) ground = 27;
		else if (x <= 564) ground = 23;
		else if (x <= 605) ground = 17;
		else if (x <= 633) ground = 31;
		else if (x <= 673) ground = 46;
		else if (x <= 696) ground = 58;
		else if (x <= 787) ground = 69;
		else if (x <= 808) ground = 58;
		else ground = 40;

		if (_position.Y + 73 > 480 - ground)
			Die();
	}

	if (_frameCounter > 50)
	{
		_frameCounter = 0;
		_frame++;
		if (_frame > 4)
			_frame = 1;
	}
}
void Player::HandleInput()
{
	if (_timer > 100 && _visible && (InputManager::IsKeyPress(SDL_SCANCODE_SPACE) || InputManager::IsButtonPress(1)))
	{
		if (!_map->GetTapped())
			_map->SetTapped(true);
		_velocity += 1;
		AudioManager::PlayEffect(_jump);
	}
}
void Player::Draw(Camera* Camera)
{
	if (!_visible) return;

	switch (_frame)
	{
	case 1:
	default:
		switch (_color)
		{
		default:
		case PC_RED:
			_textureX = 216;
			_textureY = 1878;
			break;
		case PC_GREEN:
			_textureX = 114;
			_textureY = 1639;
			break;
		case PC_YELLOW:
			_textureX = 304;
			_textureY = 1967;
			break;
		case PC_BLUE:
			_textureX = 330;
			_textureY = 1371;
			break;
		}
	case 2:
	case 4:
		switch (_color)
		{
		default:
		case PC_RED:
			_textureX = 372;
			_textureY = 1059;
			break;
		case PC_GREEN:
			_textureX = 216;
			_textureY = 1951;
			break;
		case PC_YELLOW:
			_textureX = 330;
			_textureY = 1298;
			break;
		case PC_BLUE:
			_textureX = 372;
			_textureY = 1132;
			break;
		}
		break;
	case 3:
		switch (_color)
		{
		default:
		case PC_RED:
			_textureX = 372;
			_textureY = 986;
			break;
		case PC_GREEN:
			_textureX = 222;
			_textureY = 1489;
			break;
		case PC_YELLOW:
			_textureX = 330;
			_textureY = 1225;
			break;
		case PC_BLUE:
			_textureX = 222;
			_textureY = 1562;
			break;
		}
		break;
	}

	_texture.Draw(_textureX, _textureY, _width, _height, 100, (int)_position.Y, _width, _height, _velocity * -50);
}