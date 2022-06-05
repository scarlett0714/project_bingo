#include "Dice.h"
#include "Player.h"
#include <cstdlib> //rand()기능


Dice::Dice() : faceValue(0)
{}

void Dice::roll()
{
	//주사위를 던졌을 때 주사위 값을 결정
	faceValue = rand() % 6 + 1;
}

int Dice::getFaceValue()
{
	//주사위를 던졌을 때 faceValue값 접근
	return faceValue;
}
