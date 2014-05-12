//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Vector2.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __VECTOR2_H__
#define __VECTOR2_H__

class Vector2
{
public:
	float X;
	float Y;

	Vector2(const float x = 0, const float y = 0);
	~Vector2(void);

	Vector2 operator+(const Vector2& pVector) const;
	Vector2 operator-(const Vector2& pVector) const;
	Vector2 operator*(const float& num) const;
	Vector2 operator/(const float& num) const;
	Vector2 operator*(const Vector2& vector) const;
	Vector2 operator/(const Vector2& vector) const;
	void operator+=(const Vector2& pVector);
	void operator-=(const Vector2& pVector);
	void operator*=(const float& num);
	void operator/=(const float& num);
	void operator=(const Vector2& pVector);
	bool operator==(const Vector2& vector) const;
	bool operator!=(const Vector2& vector) const;

	void Clamp(const float& value);
	void Clamp(const float& min, const float& max);
	void Clamp(const Vector2& min, const Vector2& max);
	void Normalize(const float& value = 1.0f);
	void Invert(void);

	float Length(void) const;

	Vector2 Copy(void) const;

	static Vector2 Cartesian(const float& x, const float& y);
	static Vector2 Polar(const float& radius, const float& angle);
	static float Dot(const Vector2& pVec1, const Vector2& pVec2);
	static Vector2 Rotate(const Vector2& pVec, const float& angle);
	static float Distance(const Vector2& pVec1, const Vector2& pVec2);
	static const Vector2 Zero;
};

inline Vector2 Vector2::Copy(void) const
{
	return Vector2(X, Y);
}
inline bool Vector2::operator==(const Vector2& vector) const
{
	return X == vector.X && Y == vector.Y;
}
inline bool Vector2::operator!=(const Vector2& vector) const
{
	return X != vector.X || Y != vector.Y;
}
inline Vector2 Vector2::operator+(const Vector2& pVector) const
{
	return Vector2(X + pVector.X, Y + pVector.Y);
}
inline Vector2 Vector2::operator-(const Vector2& pVector) const
{
	return Vector2(X - pVector.X, Y - pVector.Y);
}
inline Vector2 Vector2::operator*(const float& num) const
{
	return Vector2(X * num, Y * num);
}
inline Vector2 Vector2::operator/(const float& num) const
{
	return Vector2(X / num, Y / num);
}
inline Vector2 Vector2::operator*(const Vector2& vector) const
{
	return Vector2(X * vector.X, Y * vector.Y);
}
inline Vector2 Vector2::operator/(const Vector2& vector) const
{
	return Vector2(X / vector.X, Y / vector.Y);
}
#endif