#include <iostream>
#include "Dice.h"
#include "Player.h"
#include <ctime>
using namespace std;

int main() {
	cout << "202110547 Ȳ����" << endl;
	srand((unsigned)time(NULL)); //rand�� �ʱ�ȭ

	Dice dice1, dice2;
	Player player1("�Ϸ���");
	Player player2("�̷���");
	player1.setName("ȫ�浿");
	//player2.setName("��浿");
	
	player1.roll(dice1, dice2);
	player2.roll(dice1, dice2);
	if (player1.getTotal() > player2.getTotal()) {
		cout << player1.getName() << "�� �¸� -> ���� (" << player1.getTotal() << "," << player2.getTotal() << ")" << endl;
	}
	else if (player1.getTotal() < player2.getTotal()) {
		cout << player2.getName() << "�� �¸� -> ���� (" << player1.getTotal() << "," << player2.getTotal() << ")" << endl;
	}
	else {
		cout << "���º� -> ���� (" << player1.getTotal() << "," << player2.getTotal() << ")" << endl;
	}

	return 0;
}