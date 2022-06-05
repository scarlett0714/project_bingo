#include "Dice.h"
#include "Player.h"
#include <cstdlib> //rand()���


Dice::Dice() : faceValue(0)
{}

void Dice::roll()
{
	//�ֻ����� ������ �� �ֻ��� ���� ����
	faceValue = rand() % 6 + 1;
}

int Dice::getFaceValue()
{
	//�ֻ����� ������ �� faceValue�� ����
	return faceValue;
}
