//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Camera.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Object.h"

class Camera : public Object
{
private:
	Object* _target;
	Vector2 _screenCenter;

public:
	Vector2 Position(void) { return ((_target == NULL ? _screenCenter : _target->GetPosition()) * -1) + _screenCenter; }

	Camera(void);
	void Follow(Object* Target);
	bool InView(Vector2 Position);
};
#endif