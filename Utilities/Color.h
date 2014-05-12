//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: Color.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __COLOR_H__
#define __COLOR_H__

class Color
{
public:
	int R;
	int G;
	int B;
	int A;

	Color(int R, int G, int B)
	{
		this->R = R;
		this->G = G;
		this->B = B;
		this->A = 255;
	}
	Color(int R, int G, int B, int A)
	{
		this->R = R;
		this->G = G;
		this->B = B;
		this->A = A;
	}

	static Color White;
	static Color Black;
	static Color Red;
	static Color Green;
	static Color Blue;
	static Color Yellow;
};
#endif