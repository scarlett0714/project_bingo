//window API����

#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void setCursorView(bool visible) {
	CONSOLE_CURSOR_INFO cursor = { 1, visible };  //visible : ȭ�鿡 Ŀ���� �����̵��� ���� ���̳� �ƴϳ�
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
	setCursorView(false); //ȭ�鿡�� Ŀ�����ֱ�
	while (true) {
		//_getch() : #include <conio.h>
		
		//cout << _getch() << endl;
		//�ٸ� ���ڿ� �ٸ��� ����Ű�� Ȯ��Ű�� �־� �ι� _getch()�� ����� ���ϴ� �� ���� �� ����
	
		if (_kbhit()) { //Ű���尡 ������
			int keycode = _getch();
			if (keycode == 224) { //Ȯ��Ű �ޱ�
				system("cls"); //ȭ�������
				keycode = _getch();
				switch (keycode) {
				case 75: x -= 2; break; //����
				case 77: x += 2; break; //������
				case 72: y -= 1; break; //����
				case 80: y += 1; break; //�Ʒ���
				}
				
				gotoxy(x, y);
				cout << "��"; //Ư�����ڴ� 2����Ʈ�� ����
			}
		}
	}
}