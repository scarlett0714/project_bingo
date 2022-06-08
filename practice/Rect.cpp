#include "Rect.h"

Rect::Rect()
{
}

Rect::Rect(const Point& topLeft, const Point& bottomRight)
	:_topLeft(topLeft), _bottionRight(bottomRight)
{
}

Rect::Rect(int left, int top, int right, int bottom)
	:_topLeft(left, top), _bottionRight(right, bottom)
{
}
