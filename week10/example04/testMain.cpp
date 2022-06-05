//window API사용법

#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void setCursorView(bool visible) {
	CONSOLE_CURSOR_INFO cursor = { 1, visible };  //visible : 화면에 커서가 깜빡이도록 놔둘 것이냐 아니냐
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

}

void gotoxy(int x, int y) {
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main() {
	int x = 10;
	int y = 10;
	gotoxy(x, y);
	setCursorView(false); //화면에서 커서없애기
	while (true) {
		//_getch() : #include <conio.h>
		
		//cout << _getch() << endl;
		//다른 문자와 다르게 방향키는 확장키가 있어 두번 _getch()를 해줘야 원하는 값 얻을 수 있음
	
		if (_kbhit()) { //키보드가 눌리면
			int keycode = _getch();
			if (keycode == 224) { //확장키 받기
				system("cls"); //화면지우기
				keycode = _getch();
				switch (keycode) {
				case 75: x -= 2; break; //왼쪽
				case 77: x += 2; break; //오른쪽
				case 72: y -= 1; break; //위쪽
				case 80: y += 1; break; //아래쪽
				}
				
				gotoxy(x, y);
				cout << "■"; //특수문자는 2바이트씩 차지
			}
		}
	}
}