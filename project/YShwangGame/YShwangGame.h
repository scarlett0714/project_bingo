#pragma once
#include "Bingo.h"
#include "ComputerBingo.h"
#include "UserBingo.h"
class YShwangGame
{
public:
	int bingoSize;
	int cnt = 0; //���º� Ƚ��
	unique_ptr<unique_ptr<Bingo>[]> bingo = nullptr;

	YShwangGame(); //������
	~YShwangGame(); //�Ҹ���

	void play(); //play
	void menu(); //menu

	void bingoLogo(); //���� �ΰ� ȭ��
	void VSLogo(); //VS �ΰ� ȭ��

	void newGame(); //menu1 : �� ����
	void makeBingo(); //menu2 : �̾��ϱ⸦ ���� �����Ǹ����
	void show(); //���� ���� �����Ȳ ���

	void input(); //���� ���� �Է¹ޱ�
	void judge(); //���� ����
	void replay(); //���� ���� �� ���� ���� ���� �ڵ����� ���÷���

	void save();
	void readfile(); //����� ���� �о����
	void writefile(); //���Ͽ� ���

	
};

