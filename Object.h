//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Object.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "SpriteSheet.h"
#include "Vector2.h"

class Camera;

class Object
{
protected:
	SpriteSheet _texture;
	Vector2 _position;
	int _width;
	int _height;
	int _textureX;
	int _textureY;
	int _textureWidth;
	int _textureHeight;

	bool _visible;

public:
	Object();

	bool GetVisible(void) { return _visible; }
	void SetVisible(bool Visible) { _visible = Visible; }

	Vector2 GetPosition(void) { return _position; }
	virtual void SetPosition(int x, int y);

	bool valueInRange(int value, int min, int max);
	bool LineRectangleIntersect(SDL_Rect rect, int x0, int y0, int x1, int y1);

	virtual SDL_Rect GetBounds();
	virtual SDL_Rect GetTextureBounds();

	virtual void Dispose();
	virtual void Update(Uint32 Delta);
	virtual void HandleInput();
	virtual void Draw(Camera* Camera);
	virtual bool Collides(Object* Object) { return false; }

	virtual void Die() { }
	virtual void Collided(Object* Object) { }
};
#endif;