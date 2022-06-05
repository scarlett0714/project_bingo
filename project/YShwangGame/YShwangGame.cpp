#include <iostream>
#include <iomanip>
#include "YShwangGame.h"
using namespace std;

YShwangGame::~YShwangGame()
{
}

void YShwangGame::play()
{
	cout << "202110547 황윤선" << endl;
	menu();
}

void YShwangGame::menu()
{
	int menu; //menu선택
	
	while (true) {

		cout << "1) 새 게임 2) 이어하기 3) 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		cin >> menu;

		switch (menu) {
		case 1:
			newGame();
			break;
		case 2:
			break;
		case 3:
			//종료했을 때 저장되는 기능 추가
			cout << "게임을 종료합니다." << endl;
			return;
		default:
			cout << "선택 범위를 벗어났습니다. 다시 선택해주세요." << endl;
		}
	}
	
}

void YShwangGame::newGame()
{
	//빙고판 크기 선택
	while (true) {
		cout << "빙고판의 크기를 입력하세요(3 ~ 9) : ";
		cin >> bingoSize;

		if (bingoSize >= 3 && bingoSize <= 9) {
			cout << bingoSize << "x" << bingoSize << " 빙고를 시작합니다." << endl;
			break;
		}
		else {
			cout << "정해진 범위 내의 숫자만 입력하세요." << endl;
		}
	}

	//ComputerBingo 객체 생성
	
	//UserBingo 객체 생성
	

}

void YShwangGame::show()
{
	system("cls");
	cout << "202110547 황윤선" << endl;

	//빙고출력
	//computer
	cout.setf(ios::right);
	for (int i = 0; i < (bingoSize * bingoSize); i++) {
		for (int j = 0; j < (bingoSize * bingoSize); j++) {
			//computer의 cStatus가 0이면 숫자 그대로 출력
			//computer의 cStatus가 1이면 ○출력
			cout << setw(5); //코드 추가
		}
		cout << endl;
	}

	//user
	cout.setf(ios::right);
	for (int i = 0; i < (bingoSize * bingoSize); i++) {
		for (int j = 0; j < (bingoSize * bingoSize); j++) {
			//user의 uStatus가 0이면 숫자 그대로 출력
			//user의 uStatus가 1이면 ●출력
			cout << setw(5); //코드 추가
		}
		cout << endl;
	}

}

void YShwangGame::input()
{
	
	
	//user 숫자입력
	int num;
	cout << "숫자를 입력하세요 : ";
	cin >> num;

	//computer 숫자입력
	//computer.find(num);
	//computer.check();

	//승패판정
	//if (computer.check() == true && user.check() == false) { //컴퓨터가 이김
	//	cout << "컴퓨터가 승리하였습니다." << endl;
	// 	show();
	// 	replay();
	//}
	//else if (computer.check() == false && user.check() == true) { //유저가 이김
	//	cout << "유저가 승리하였습니다." << endl;
	// 	show();
	// 	replay();
	//}
	//else if (computer.check() == true && user.check() == true) { //무승부
	//	cout << "무승부입니다." << endl;
	// 	show();
	// 	replay();
	//}

	
}

void YShwangGame::replay()
{
	//user->computer 순서로 빙고 게임진행
	//for (int i = 0; i < bingoSize; i++) {
	//	for (int j = 0; j < bingoSize; j++) {
	//		uStatus[i][j] = 0; //처음상태로 초기화
	//	}
	//}
	//for (int i = 0; i < bingoSize; i++) {
	//	for (int j = 0; j < bingoSize; j++) {
	//		cStatus[i][j] = 0; //처음상태로 초기화
	//	}
	//}

	int i = 0; //반복변수
	while (true) {
		//uSave에서 값을 한개 꺼내 find, check 수행
		//cSave에서 값을 한개 꺼내 find, check 수행

		//승패가 날때까지 반복

		//show();
		//Sleep(5000);
		//system("cls");
	}
}


