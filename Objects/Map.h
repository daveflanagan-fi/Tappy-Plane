//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Map.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include "Object.h"

class UI;
class Player;

enum MAP_TYPE
{
	MT_GRASS,
	MT_DIRT,
	MT_ICE,
	MT_SNOW,
	//MT_ROCK,
	MT_COUNT
};

class Map : public Object
{
private:
	std::vector<Object*> _objects;
	unsigned int _collect;
	Player* _player;
	UI* _ui;
	int _score;
	bool _hasTapped;
	bool _gameOver;
	int _type;
	int x;
	bool invert;

public:
	Map(Camera* Camera, bool Background = false);

	void Update(Uint32 Delta);
	void HandleInput();
	void Draw(Camera* Camera);

	void AddPoint();

	int GetScore() { return _score; }

	bool GetTapped() { return _hasTapped; }
	void SetTapped(bool Tapped);

	bool GetGameover() { return _gameOver; }
	void SetGameOver(bool GameOver);

	int GetType() { return _type; }
};
#endif