#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(string _name)
{
    setName(_name);
}

void Player::setName(const string& _name)
{
    name = _name;
}

string Player::getName()
{
    return name;
}

void Player::roll(Dice& dice1, Dice& dice2)
{
    cout << name << "�Բ��� �ֻ����� �������ϴ�." << endl;
    dice1.roll();
    dice2.roll();
    total = dice1.getFaceValue() + dice2.getFaceValue();
}

int Player::getTotal()
{
    return total;
}
