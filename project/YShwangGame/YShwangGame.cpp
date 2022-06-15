#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "YShwangGame.h"
#include <Windows.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77
#define UP 80
#define DOWN 72

using namespace std;

//window API
void setCursorView(bool visible) {
	CONSOLE_CURSOR_INFO cursor = { 1, visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void gotoxy(int x, int y) {
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

COORD getXY() {
	COORD Cur;
	CONSOLE_SCREEN_BUFFER_INFO a;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &a);
	Cur.X = a.dwCursorPosition.X;
	Cur.Y = a.dwCursorPosition.Y;
	return Cur;
}


YShwangGame::YShwangGame()
	: bingo(make_unique<unique_ptr<Bingo>[]>(2))
{
}

YShwangGame::~YShwangGame()
{
}

void YShwangGame::play()
{
	srand((unsigned int)time(NULL));
	
	menu();
}

void YShwangGame::menu()
{
	int menu; //menu선택
	
	while (true) {
		gotoxy(52, 0);
		cout << "202110547 황윤선" << endl;

		bingoLogo();

		gotoxy(54, 13);
		cout << "1) 새로하기" << endl;
		gotoxy(54, 15);
		cout << "2) 이어하기" << endl;
		gotoxy(56, 17);
		cout << "3) 종료" << endl;
		

		gotoxy(50, 20);
		cout << "메뉴를 선택하세요";

		int key; int x = getXY().X; int y = getXY().Y;
		while (true) {
			key = _getch();
			if (key == 224 || key == 0) {
				key = _getch();

				if (key == RIGHT) {
					x += 1;
					gotoxy(x, y);
				}
				else if (key == LEFT) {
					x -= 1;
					gotoxy(x, y);
				}
				else if (key == UP) {
					y += 1;
					gotoxy(x, y);
				}
				else if (key == DOWN) {
					y -= 1;
					gotoxy(x, y);
				}
				
			}
			if (key == 13) {
				if (y == 13) {
					
					newGame();
					//gameover = false;
					break;
				}
				else if (y == 15) {
					system("cls");
					gotoxy(52, 0);
					cout << "202110547 황윤선" << endl;

					gotoxy(48, 14);
					cout << "저장된 파일을 불러오는중..." << endl;
					Sleep(2000);
					readfile();

					show();
					input();
					break;
				}
				else if (y == 17) {
					cout << "게임을 종료합니다." << endl;
					return;
					//exit(0);
				}
				else {
					cout << "선택 범위를 벗어났습니다. 다시 선택해주세요." << endl;
				}

			}
			
		}
	}
	
}

void YShwangGame::bingoLogo()
{
	gotoxy(26, 5);
	cout << "■■■■      ■■■■■    ■      ■      ■■■         ■■■   " << endl;
	gotoxy(26, 6);
	cout << "■      ■        ■        ■■    ■    ■             ■      ■ " << endl;
	gotoxy(26, 7);
	cout << "■■■■          ■        ■  ■  ■   ■    ■■■   ■        ■" << endl;
	gotoxy(26, 8);
	cout << "■      ■        ■        ■    ■■    ■     ■      ■      ■ " << endl;
	gotoxy(26, 9);
	cout << "■■■■      ■■■■■    ■      ■      ■■■         ■■■   " << endl;
}

void YShwangGame::VSLogo()
{
	gotoxy(50, 9);
	cout << "■      ■    ■■■   " << endl;
	gotoxy(50, 10);
	cout << " ■    ■    ■        " << endl;
	gotoxy(50, 11);
	cout << "  ■  ■      ■■■   " << endl;
	gotoxy(50, 12);
	cout << "   ■■            ■  " << endl;
	gotoxy(50, 13);
	cout << "    ■        ■■■   " << endl;
}


void YShwangGame::newGame()
{
	//빙고판 크기 선택
	gameover = false;
	cnt = 0;
	while (true) {
		gotoxy(45, 21);
		cout << "빙고판의 크기를 입력하세요(3 ~ 9) : ";
		cin >> bingoSize;

		if (bingoSize >= 3 && bingoSize <= 9) {
			gotoxy(45, 21);
			cout << "                                     " << endl;
			gotoxy(49, 21);
			cout << bingoSize << " x " << bingoSize << " 빙고를 시작합니다" << endl;
			Sleep(2000);
			break;
		}
		else {
			gotoxy(45, 21);
			cout << "정해진 범위의 숫자를 입력하세요." << endl;
			Sleep(2000);
		}
	}

	//ComputerBingo 객체 생성
	bingo[0] = move(make_unique<ComputerBingo>(bingoSize, 1));
	//UserBingo 객체 생성
	bingo[1] = move(make_unique<UserBingo>(bingoSize, 1));

	show();
	input();
}

void YShwangGame::makeBingo()
{
	//ComputerBingo 객체 생성
	bingo[0] = move(make_unique<ComputerBingo>(bingoSize, 2));
	//UserBingo 객체 생성
	bingo[1] = move(make_unique<UserBingo>(bingoSize, 2));
}

void YShwangGame::show()
{
	//빙고출력
	//computer
	system("cls");
	gotoxy(52, 0);
	cout << "202110547 황윤선" << endl;

	gotoxy(58 - ((bingoSize * 3) / 2 + 20 + 2), 8);
	cout << "COMPUTER" << endl;

	gotoxy(58 - (bingoSize * 3 + 20), 11);
	cout.setf(ios::right);
	for (int i = 0; i < (bingoSize); i++) {
		for (int j = 0; j < (bingoSize); j++) {
			
			if (bingo[0]->status[i][j] == 0) {
				cout << setw(3) << bingo[0]->map[i][j];
			}
			else if(bingo[0]->status[i][j] == 1){
				cout << setw(3) << "●";
			}
			else {
				cout << setw(3) << "○";
			}
			
		}
		gotoxy(58 - (bingoSize * 3 + 20), 12+i);
	}

	VSLogo();

	gotoxy(58 + ((bingoSize * 3) / 2 + 20), 8);
	cout << "USER" << endl;
	//user
	gotoxy(78, 11);
	for (int i = 0; i < (bingoSize); i++) {
		for (int j = 0; j < (bingoSize); j++) {
			if (bingo[1]->status[i][j] == 0) {
				cout << setw(3) << bingo[1]->map[i][j];
			}
			else if (bingo[1]->status[i][j] == 1) {
				cout << setw(3) << "●";
			}
			else {
				cout << setw(3) << "○";
			}
		}
		gotoxy(78, 12+i);
	}

}

void YShwangGame::input()
{
	//user 숫자입력
	gotoxy(50, 15);
	int num;
	cout << "숫자를 선택하세요";
	int key; int x = 77; int y = 11;

	while (true) {
		key = _getch();
		if (key == 224 || key == 0) {
			key = _getch();

			if (key == RIGHT) {
				x += 3;
				gotoxy(x, y);
			}
			else if (key == LEFT) {
				x -= 3;
				gotoxy(x, y);
			}
			else if (key == UP) {
				y += 1;
				gotoxy(x, y);
			}
			else if (key == DOWN) {
				y -= 1;
				gotoxy(x, y);
			}

		}
		if (key == 13) {
			int dx = (x - 78) / 3;
			int dy = y - 11;

			num = bingo[1]->find2(dy, dx);
			
			break;
		}

	}
	//cin >> num;

	//bingo[1]->find(num, 1);
	
	bingo[1]->check(cnt);

	bingo[0]->find(num, 1);
	bingo[0]->check(cnt);

	bingo[1]->save.push_back(num);

	judge();
	if (gameover) return;
	show();

	//computer 숫자선택
	gotoxy(49, 15);
	cout << "컴퓨터가 고민중입니다..." << endl;
	Sleep(3000);

	int choice = bingo[0]->find();
	bingo[0]->check(cnt);
	bingo[0]->save.push_back(choice);

	bingo[1]->find(choice, 0);
	bingo[1]->check(cnt);

	judge();
	
	show();


	save();
}

void YShwangGame::judge()
{
	//승패판정
	if (bingo[0]->check(cnt) == true && bingo[1]->check(cnt) == false) { //컴퓨터가 이김
		show();
		gotoxy(49, 15);
		cout << "컴퓨터가 승리하였습니다." << endl;
		Sleep(2000);
		gotoxy(49, 15);
		cout << "방금 게임을 replay합니다." << endl;
		Sleep(2000);
		replay();
		gameover = true;

	}
	else if (bingo[0]->check(cnt) == false && bingo[1]->check(cnt) == true) { //유저가 이김
		
		show();
		gotoxy(49, 15);
		cout << "유저가 승리하였습니다." << endl;
		Sleep(2000);
		gotoxy(49, 15);
		cout << "방금 게임을 replay합니다." << endl;
		Sleep(2000);
		replay();
		gameover = true;

	}
	else if (bingo[0]->check(cnt) == true && bingo[1]->check(cnt) == true) { //무승부
		
		show();
		gotoxy(52, 15);
		cout << "무승부입니다." << endl;
		Sleep(3000);
		cnt++;

		bool ch = true;
		for (int i = 0; i < bingoSize; i++) {
			for (int j = 0; j < bingoSize; j++) {
				if (bingo[0]->status[i][j] == 0) ch = false;
			}
		}

		if (ch == true) { //모든 번호가 선택됨
			show();
			Sleep(3000);
			replay();
			gameover = true;
		}
	}
}

void YShwangGame::replay()
{
	//user->computer 순서로 빙고 게임진행
	for (int i = 0; i < bingoSize; i++) {
		for (int j = 0; j < bingoSize; j++) {
			bingo[0]->status[i][j] = 0; //처음상태로 초기화
		}
	}
	for (int i = 0; i < bingoSize; i++) {
		for (int j = 0; j < bingoSize; j++) {
			bingo[1]->status[i][j] = 0; //처음상태로 초기화
		}
	}

	int i = 0; //반복변수
	while (true) {
		//save에서 값 하나씩 빼와서 find하고 check

		if (bingo[0]->save.size() < bingo[1]->save.size()) { //user로 게임끝난 경우
			bingo[1]->find(bingo[1]->save[i], 1);
			bingo[0]->find(bingo[1]->save[i], 1);
			show();
			Sleep(3000);

			if (bingo[1]->save.size() <= (i + 1)) {
				system("cls");
				break;
			}

			bingo[1]->find(bingo[0]->save[i], 0);
			bingo[0]->find(bingo[0]->save[i], 0);
			show();
			i++;

			Sleep(3000);
			system("cls");

			
		}
		else { //computer로 게임끝난 경우
			bingo[1]->find(bingo[1]->save[i], 1);
			bingo[0]->find(bingo[1]->save[i], 1);
			show();
			Sleep(3000);

			bingo[1]->find(bingo[0]->save[i], 0);
			bingo[0]->find(bingo[0]->save[i], 0);
			show();
			i++;

			Sleep(3000);
			system("cls");
			if (bingo[0]->save.size() <= i) break;
		}
		
	}
	system("cls");
}

void YShwangGame::save()
{
	
	while (true) {
		if (gameover)return;
		gotoxy(56, 15);
		cout << "저장 후,";
		
		gotoxy(44, 16);
		cout << "게임을 종료하시겠습니까? (y/n) : ";

		char check;
		cin >> check;
		switch (check) {
		case 'y':
			gotoxy(56, 15);
			cout << "         ";
			gotoxy(44, 16);
			cout << "                                    ";

			gotoxy(50, 15);
			cout << "파일을 저장 중..." << endl;
			writefile();
			gotoxy(50, 16);
			cout << "게임을 종료합니다" << endl;
			system("cls");
			gameover = true;
			return;
		case 'n':
			gotoxy(48, 15);
			cout << "게임을 계속 진행합니다." << endl;
			Sleep(1000);
			gotoxy(48, 15);
			cout << "                         " << endl;
			gotoxy(44, 16);
			cout << "                                  ";
			input();
			break;
		default:
			gotoxy(50, 17);
			cout << "다시 입력하세요" << endl;
			Sleep(2000);
		}
	}
}

void YShwangGame::readfile()
{
	//computer
	ifstream computer_map;
	computer_map.open("computerMAP.txt");

	int i = 0; int j = 0;
	if (computer_map.is_open()) {
		string str;
		getline(computer_map, str);
		bingoSize = stoi(str);
		makeBingo();
		while (!computer_map.eof() && i <= bingoSize - 1) { 
			
			getline(computer_map, str);
			if (j < bingoSize) {
				bingo[0]->map[i][j++] = stoi(str);
			}
			else {
				j = 0;
				i++;
				if (i == bingoSize)break;
				bingo[0]->map[i][j++] = stoi(str);
			}
			
		}
	}
	computer_map.close();

	ifstream computer_status;
	computer_status.open("computerSTATUS.txt");

	i = 0; j = 0;
	if (computer_status.is_open()) {
		while (!computer_status.eof() && i <= bingoSize - 1) {
			string str;
			getline(computer_status, str);
			if (j < bingoSize) {
				bingo[0]->status[i][j++] = stoi(str);
			}
			else {
				j = 0;
				i++;
				if (i == bingoSize)break;
				bingo[0]->status[i][j++] = stoi(str);
			}

		}
	}
	computer_status.close();

	//user
	ifstream user_map;
	user_map.open("userMAP.txt");

	i = 0; j = 0;
	if (user_map.is_open()) {
		while (!user_map.eof() && i <= bingoSize - 1) {
			string str;
			getline(user_map, str);
			if (j < bingoSize) {
				bingo[1]->map[i][j++] = stoi(str);
			}
			else {
				j = 0;
				i++;
				if (i == bingoSize)break;
				bingo[1]->map[i][j++] = stoi(str);
			}

		}
	}
	user_map.close();

	ifstream user_status;
	user_status.open("userSTATUS.txt");

	i = 0; j = 0;
	if (user_status.is_open()) {
		while (!user_status.eof() && i <= bingoSize - 1) {
			string str;
			getline(user_status, str);
			if (j < bingoSize) {
				bingo[1]->status[i][j++] = stoi(str);
			}
			else {
				j = 0;
				i++;
				if (i == bingoSize)break;
				bingo[1]->status[i][j++] = stoi(str);
			}

		}
	}
	user_status.close();

	//현재까지 게임 진행 순서
	ifstream computer_game;
	computer_game.open("computerGAME.txt");
	
	i = 0; j = 0;
	if (computer_game.is_open()) {
		while (!computer_game.eof()) {
			string str;
			getline(computer_game, str);
			if (str != "") {
				bingo[0]->save.push_back(stoi(str));
			}
	
		}
	}
	computer_game.close();
	
	ifstream user_game;
	user_game.open("userGAME.txt");
	
	i = 0;
	if (user_game.is_open()) {
		while (!user_game.eof()) {
			string str;
			getline(user_game, str);
			if (str != "") {
				bingo[1]->save.push_back(stoi(str));
			}
	
		}
	}
	user_game.close();

	//무승부 횟수
	ifstream same_cnt;
	same_cnt.open("cnt.txt");

	
	if (same_cnt.is_open()) {
		while (!same_cnt.eof()) {
			string str;
			getline(same_cnt, str);
			if (str != "") {
				cnt = stoi(str);
			}

		}
	}
	same_cnt.close();
}

void YShwangGame::writefile()
{
	//computer
	ofstream computer_map;
	computer_map.open("computerMAP.txt");
	string str = to_string(bingoSize) + "\n";
	computer_map.write(str.c_str(), str.size());
	for (int i = 0; i < bingoSize; i++) {
		for (int j = 0; j < bingoSize; j++) {
			str = to_string(bingo[0]->map[i][j]) + "\n";
			computer_map.write(str.c_str(), str.size());
		}
	}
	computer_map.close();

	ofstream computer_status;
	computer_status.open("computerSTATUS.txt");
	for (int i = 0; i < bingoSize; i++) {
		for (int j = 0; j < bingoSize; j++) {
			string str = to_string(bingo[0]->status[i][j]) + "\n";
			computer_status.write(str.c_str(), str.size());
		}
	}
	computer_status.close();

	//user
	ofstream user_map;
	user_map.open("userMAP.txt");
	for (int i = 0; i < bingoSize; i++) {
		for (int j = 0; j < bingoSize; j++) {
			string str = to_string(bingo[1]->map[i][j]) + "\n";
			user_map.write(str.c_str(), str.size());
		}
	}
	user_map.close();

	ofstream user_status;
	user_status.open("userSTATUS.txt");
	for (int i = 0; i < bingoSize; i++) {
		for (int j = 0; j < bingoSize; j++) {
			string str = to_string(bingo[1]->status[i][j]) + "\n";
			user_status.write(str.c_str(), str.size());
		}
	}
	user_status.close();

	//현재까지 게임 진행 순서
	ofstream computer_game;
	computer_game.open("computerGAME.txt");
	for (int i = 0; i < bingo[0]->save.size(); i++) {
		string str = to_string(bingo[0]->save[i]) + "\n";
		computer_game.write(str.c_str(), str.size());
	}
	computer_game.close();

	//현재까지 게임 진행 순서
	ofstream user_game;
	user_game.open("userGAME.txt");
	for (int i = 0; i < bingo[1]->save.size(); i++) {
		string str = to_string(bingo[1]->save[i]) + "\n";
		user_game.write(str.c_str(), str.size());
	}
	user_game.close();

	//무승부 횟수
	ofstream same_cnt;
	same_cnt.open("cnt.txt");
	
	str = to_string(cnt);
	same_cnt.write(str.c_str(), str.size());
	
	same_cnt.close();
}



