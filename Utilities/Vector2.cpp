//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Vector2.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "Vector2.h"
#include <math.h>

const Vector2 Vector2::Zero = Vector2();

Vector2::Vector2(const float x, const float y)
{
	X = x;
	Y = y;
}
Vector2::~Vector2(void)
{
}

void Vector2::operator+=(const Vector2& pVector)
{
	X += pVector.X;
	Y += pVector.Y;
}
void Vector2::operator-=(const Vector2& pVector)
{
	X -= pVector.X;
	Y -= pVector.Y;
}
void Vector2::operator*=(const float& num)
{
	X *= num;
	Y *= num;
}
void Vector2::operator/=(const float& num)
{
	X /= num;
	Y /= num;
}
void Vector2::operator=(const Vector2& pVector)
{
	X = pVector.X;
	Y = pVector.Y;
}
float Vector2::Length(void) const
{
	return sqrt(pow(X, 2.0f) + pow(Y, 2.0f));
}
void Vector2::Clamp(const float& value)
{
	if (Length() <= value)
		return;
	Normalize();
	*this *= value;
}
void Vector2::Clamp(const float& min, const float& max)
{
	if (this->X < min) this->X = min;
	if (this->Y < min) this->Y = min;
	if (this->X > max) this->X = max;
	if (this->Y > max) this->Y = max;
}
void Vector2::Clamp(const Vector2& min, const Vector2& max)
{
	if (this->X < min.X) this->X = min.X;
	if (this->Y < min.Y) this->Y = min.Y;
	if (this->X > max.X) this->X = max.X;
	if (this->Y > max.Y) this->Y = max.Y;
}
void Vector2::Normalize(const float& value)
{
	float vecLength = Length();

	if (vecLength == 0)
		return;

	X = X / vecLength * value;
	Y = Y / vecLength * value;
}
void Vector2::Invert(void)
{
	X *= -1;
	Y *= -1;
}
Vector2 Vector2::Polar(const float& x, const float& y)
{
	Vector2 pVector = Vector2();
	pVector.X = atan2(y, x);
	pVector.Y = sqrt(x * x + y * y);
	return pVector;
}
Vector2 Vector2::Cartesian(const float& radius, const float& angle)
{
	Vector2 pVector = Vector2();
	pVector.X = radius * cos(angle);
	pVector.Y = radius * sin(angle);
	return pVector;
}
float Vector2::Dot(const Vector2& pVec1, const Vector2& pVec2)
{
	return pVec1.X * pVec2.X + pVec1.Y * pVec2.Y;
}
Vector2 Vector2::Rotate(const Vector2& pVec, const float& angle)
{
	float cosResult = cos(angle);
	float sinResult = sin(angle);
	float newX = pVec.X * cosResult - pVec.Y * sinResult;
	float newY = pVec.X * sinResult + pVec.Y * cosResult;
	return Vector2(newX, newY);
}
float Vector2::Distance(const Vector2& pVec1, const Vector2& pVec2)
{
	return sqrt(pow(pVec2.X - pVec1.X, 2.0f) + pow(pVec2.Y - pVec1.Y, 2.0f));
}