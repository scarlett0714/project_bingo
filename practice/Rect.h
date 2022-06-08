#pragma once
#include "../week05/example02/Point.h"
//Rect.h
class Rect
{
protected:
	Point _topLeft;
	Point _bottionRight;
public:
	Rect();
	Rect(const Point& topLeft, const Point& bottomRight);
	Rect(int left, int top, int right, int bottom);
};

