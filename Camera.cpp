//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Camera.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "Camera.h"
#include "Engine.h"

Camera::Camera(void)
{
	_screenCenter = Vector2((float)854 / 2, (float)480 / 2);
	_target = NULL;
}
void Camera::Follow(Object* Target)
{
	this->_target = Target;
}
bool Camera::InView(Vector2 Position)
{
	Vector2 pos = this->Position() * -1;
	if (Position.X < pos.X - 150) return false;
	//if (Position.Y < pos.Y - 100) return false;
	if (Position.X > pos.X + 854) return false;
	//if (Position.Y > pos.Y + 500) return false;
	return true;
}