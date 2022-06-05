#pragma once
class Rectangle
{
public:
	int width;
	int height;

	Rectangle();
	Rectangle(int x, int y);
	Rectangle(int x);

	bool isSquare();
};

