#include <iostream>
#include <iomanip>
#include "YShwangGame.h"
using namespace std;

YShwangGame::~YShwangGame()
{
}

void YShwangGame::play()
{
	cout << "202110547 Ȳ����" << endl;
	menu();
}

void YShwangGame::menu()
{
	int menu; //menu����
	
	while (true) {

		cout << "1) �� ���� 2) �̾��ϱ� 3) ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		cin >> menu;

		switch (menu) {
		case 1:
			newGame();
			break;
		case 2:
			break;
		case 3:
			//�������� �� ����Ǵ� ��� �߰�
			cout << "������ �����մϴ�." << endl;
			return;
		default:
			cout << "���� ������ ������ϴ�. �ٽ� �������ּ���." << endl;
		}
	}
	
}

void YShwangGame::newGame()
{
	//������ ũ�� ����
	while (true) {
		cout << "�������� ũ�⸦ �Է��ϼ���(3 ~ 9) : ";
		cin >> bingoSize;

		if (bingoSize >= 3 && bingoSize <= 9) {
			cout << bingoSize << "x" << bingoSize << " ���� �����մϴ�." << endl;
			break;
		}
		else {
			cout << "������ ���� ���� ���ڸ� �Է��ϼ���." << endl;
		}
	}

	//ComputerBingo ��ü ����
	
	//UserBingo ��ü ����
	

}

void YShwangGame::show()
{
	system("cls");
	cout << "202110547 Ȳ����" << endl;

	//�������
	//computer
	cout.setf(ios::right);
	for (int i = 0; i < (bingoSize * bingoSize); i++) {
		for (int j = 0; j < (bingoSize * bingoSize); j++) {
			//computer�� cStatus�� 0�̸� ���� �״�� ���
			//computer�� cStatus�� 1�̸� �����
			cout << setw(5); //�ڵ� �߰�
		}
		cout << endl;
	}

	//user
	cout.setf(ios::right);
	for (int i = 0; i < (bingoSize * bingoSize); i++) {
		for (int j = 0; j < (bingoSize * bingoSize); j++) {
			//user�� uStatus�� 0�̸� ���� �״�� ���
			//user�� uStatus�� 1�̸� �����
			cout << setw(5); //�ڵ� �߰�
		}
		cout << endl;
	}

}

void YShwangGame::input()
{
	
	
	//user �����Է�
	int num;
	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> num;

	//computer �����Է�
	//computer.find(num);
	//computer.check();

	//��������
	//if (computer.check() == true && user.check() == false) { //��ǻ�Ͱ� �̱�
	//	cout << "��ǻ�Ͱ� �¸��Ͽ����ϴ�." << endl;
	// 	show();
	// 	replay();
	//}
	//else if (computer.check() == false && user.check() == true) { //������ �̱�
	//	cout << "������ �¸��Ͽ����ϴ�." << endl;
	// 	show();
	// 	replay();
	//}
	//else if (computer.check() == true && user.check() == true) { //���º�
	//	cout << "���º��Դϴ�." << endl;
	// 	show();
	// 	replay();
	//}

	
}

void YShwangGame::replay()
{
	//user->computer ������ ���� ��������
	//for (int i = 0; i < bingoSize; i++) {
	//	for (int j = 0; j < bingoSize; j++) {
	//		uStatus[i][j] = 0; //ó�����·� �ʱ�ȭ
	//	}
	//}
	//for (int i = 0; i < bingoSize; i++) {
	//	for (int j = 0; j < bingoSize; j++) {
	//		cStatus[i][j] = 0; //ó�����·� �ʱ�ȭ
	//	}
	//}

	int i = 0; //�ݺ�����
	while (true) {
		//uSave���� ���� �Ѱ� ���� find, check ����
		//cSave���� ���� �Ѱ� ���� find, check ����

		//���а� �������� �ݺ�

		//show();
		//Sleep(5000);
		//system("cls");
	}
}


