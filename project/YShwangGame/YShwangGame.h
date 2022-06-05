#pragma once
#include "ComputerBingo.h"
#include "UserBingo.h"
class YShwangGame
{
public:
	int bingoSize;
	ComputerBingo computer;
	UserBingo user;


	YShwangGame() = default; //������
	~YShwangGame(); //�Ҹ���

	void play(); //play
	void menu(); //menu

	void newGame(); //menu1 : �� ����
	void show(); //���� ���� �����Ȳ ���

	void input(); //���� ���� �Է¹ޱ�
	void replay(); //���� ���� �� ���� ���� ���� �ڵ����� ���÷���
	
};

