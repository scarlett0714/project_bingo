#include <iostream>
#include <string>
#include <ctime>

using namespace std;
int main() {
	
	constexpr int ROW = 6;
	constexpr int COL = 4;
	bool seats[ROW][COL]{};

	while (1) {
		system("cls"); //화면 지우기
		cout << "202110547 황윤선" << endl;
		for (int i = 0; i < COL; i++) {
			cout << '\t' << i + 1;
		}
		cout << "\n\n";
		for (int i = 0; i < ROW; i++) {
			cout << static_cast<char>('A' + i) << '\t';
			for (int j = 0; j < COL; j++) {
				cout << (seats[i][j] ? "●" : "○") << '\t';
			}
			cout << "\n\n";
		}

		cout << "종료하려면 qq를 입력하세요.\n";
		cout << "좌석 입력 (ex==> A1) : ";
		char x, y;
		cin >> x >> y;
		if (!(x == 'q' && y == 'q')) {
			if (x >= 'A' && x <= 'F' && y >= '1' && y <= '4') {
				if (seats[x - 'A'][y - '1']) {
					cout << "이미 예약된 자리입니다.\n";
				}
				else {
					seats[x - 'A'][y - '1'] = true;
					cout << "예약이 완료되었습니다.\n";
				}
				system("pause"); //잠깐 멈춰
			}
			else {
				cout << "정해진 범위 내의 좌석을 입력하세요." << endl;
				system("pause");

			}
		}
		else {
			cout << "종료합니다." << endl;
			return 0;
		}
	}

	return 0;
}