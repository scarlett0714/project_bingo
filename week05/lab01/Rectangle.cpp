#include "Rectangle.h"

Rectangle::Rectangle() : Rectangle(0, 0) {
}
Rectangle::Rectangle(int x, int y) : width(x), height(y){
}
Rectangle::Rectangle(int x) : Rectangle(x, x){
}

bool Rectangle::isSquare()
{
	if (width == height) {
		return true;
	}
	else {
		return false;
	}
}
