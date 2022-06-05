#include <iostream>
#include <string>
#include <fstream>
#include <memory>

//메모리 누수 체크 매크로
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // !DBG_NEW
#endif

using namespace std;
typedef shared_ptr<shared_ptr<int[]>[]> sharedPtr;
sharedPtr loadSeat(const string& filename, int& row, int& col, int& reserved);
void menu(const string& filename, sharedPtr(&seat), const int row, const int col, int& reserved);

void showSeat(sharedPtr(&seat), const int row, const int col);
void reserveSeat(sharedPtr(&seat), const int row, const int col, int& reserved);
void cancelSeat(sharedPtr(&seat), const int row, const int col, int& reserved);
void saveSeat(const string& filename, sharedPtr(&seat), const int row, const int col);

int main() {
	//메모리 누수체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	string filename = "testdata.txt";
	int row, col, reserved = 0;
	sharedPtr seat = loadSeat(filename, row, col, reserved);
	if (seat != nullptr) {
		menu(filename, seat, row, col, reserved);
	}

	return 0;
}

void showSeat(sharedPtr(&seat), const int ROW, const int COL) {
	cout << "******* 좌석 현황 *****" << endl;
	cout << '\t';
	for (int i = 1; i <= COL; i++) {
		cout << i << '\t';
	}
	cout << endl;
	for (int i = 0; i < ROW; i++) {
		cout << static_cast<char>(i + 'A') << '\t';
		for (int j = 0; j < COL; j++) {
			cout << (seat[i][j] ? "●" : "○") << '\t';
		}
		cout << endl;
	}
}
void reserveSeat(sharedPtr(&seat), const int ROW, const int COL, int& reserved) {
	showSeat(seat, ROW, COL);
	cout << reserved << endl;
	if (reserved == ROW * COL) {
		cout << "좌석이 전부 예약되었습니다." << endl;
		system("pause");
		return;
	}
	while (true) {
		char seat_row;
		int seat_col;
		cout << "좌석 선택(ex) A1, B2)(종료 : 00) : ";
		cin >> seat_row >> seat_col;
		if (cin.fail()) {
			cout << "잘못 입력하셨습니다. 다시 입력해주세요" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (seat_row == '0' && seat_col == 0) {
			cout << "메뉴로 이동합니다." << endl;
			break;
		}
		else if (seat_row < 'A' || seat_row >('A' + ROW) || seat_col < 1 || seat_col > COL) {
			cout << "잘못 입력하셨습니다. 다시 입력해주세요" << endl;
		}
		else if (seat[seat_row - 'A'][seat_col - 1])
			cout << "이미 예약된 자리입니다." << endl;
		else {
			reserved++;
			int num = static_cast<int>(seat_row) * 100 + seat_col;
			seat[seat_row - 'A'][seat_col - 1] = num;
			cout << "예약번호 " << num << "으로 예약되었습니다." << endl;
			break;
		}
		system("pause");
	}
}
void cancelSeat(sharedPtr(&seat), const int ROW, const int COL, int& reserved) {
	showSeat(seat, ROW, COL);
	cout << reserved << endl;
	if (reserved == 0) {
		cout << "예약된 좌석이 없습니다." << endl;
		system("pause");
		return;
	}
	while (true) {
		char seat_row;
		int seat_col;
		cout << "좌석 선택(ex) A1, B2)(종료 : 00) : ";
		cin >> seat_row >> seat_col;
		if (cin.fail()) {
			cout << "잘못 입력하셨습니다. 다시 입력해주세요" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (seat_row == '0' && seat_col == 0) {
			cout << "메뉴로 이동합니다." << endl;
			break;
		}
		else if (seat_row < 'A' || seat_row >('A' + ROW) || seat_col < 1 || seat_col > COL) {
			cout << "잘못 입력하셨습니다. 다시 입력해주세요" << endl;
		}
		else if (seat[seat_row - 'A'][seat_col - 1]) {
			cout << "예약번호를 입력하세요 : ";
			int num;
			cin >> num;
			if ((static_cast<int>(seat_row) * 100 + seat_col) == num) {
				reserved--;
				cout << "예약번호 " << num << "번 예약 취소되었습니다." << endl;
				seat[seat_row - 'A'][seat_col - 1] = 0;
				break;
			}
			else {
				cout << "예약번호가 잘못되었습니다. 확인부탁드립니다." << endl;
			}
		}
		else { //예약 안된 자리
			cout << "예약되지 않은 좌석입니다." << endl;
		}
		system("pause");
	}

}
void saveSeat(const string& filename, sharedPtr(&seat), const int row, const int col) {
	ofstream fout(filename);
	if (!fout.is_open()) {
		cerr << "파일 저장 실패" << endl;
		return;
	}
	fout << row << " " << col << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fout << seat[i][j] << " ";
		}
		fout << endl;
	}
	cout << "파일 저장 완료" << endl;
}


void menu(const string& filename, sharedPtr (&seat),
	const int row, const int col, int& reserved) {

	int select = 0;
	do {
		system("cls");
		cout << "202110547 황윤선" << endl;
		cout << "1)좌석현황 2)좌석예약 3)예약취소 4)종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		cin >> select;
		switch (select) {
		case 1: showSeat(seat, row, col); break;
		case 2: reserveSeat(seat, row, col, reserved); break;
		case 3: cancelSeat(seat, row, col, reserved); break;
		}
		system("pause");
	} while (select != 4);
	saveSeat(filename, seat, row, col);
}

sharedPtr loadSeat(const string& filename, int& row, int& col, int& reserved) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		cerr << "파일 읽기 실패\n";
		return nullptr;
		// exit(0);
	}
	fin >> row >> col;
	sharedPtr seat(new shared_ptr<int[]>[row]);
	for (int i = 0; i < row; i++)
		seat[i] = shared_ptr<int[]>(new int[col]);
	//while (!fin.eof()) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fin >> seat[i][j];
			if (seat[i][j] != 0)
				reserved++;
		}
	}
	//}
	return seat;
}

