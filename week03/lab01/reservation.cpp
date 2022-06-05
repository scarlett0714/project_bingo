#include <iostream>
#include <string>
#include <fstream>
using namespace std;
typedef int* INT;
int** loadSeat(const string& filename, int& row, int& col, int& reserved);
void menu(const string& filename, int** (&seat), const int row, const int col, int& reserved);

void showSeat(int** (&seat), const int row, const int col);
void reserveSeat(int** (&seat), const int row, const int col, int& reserved);
void cancelSeat(int** (&seat), const int row, const int col, int& reserved);
void saveSeat(const string& filename, int** (&seat), const int row, const int col);
void deleteSeat(int** (&seat), const int row);

int main() {
	string filename = "testdata.txt";
	int row, col, reserved = 0;
	int** seat = loadSeat(filename, row, col, reserved);
	if (seat != nullptr) {
		menu(filename, seat, row, col, reserved);
	}

	return 0;
}

void showSeat(int** (&seat), const int ROW, const int COL) {
	cout << "******* �¼� ��Ȳ *****" << endl;
	cout << '\t';
	for (int i = 1; i <= COL; i++) {
		cout << i << '\t';
	}
	cout << endl;
	for (int i = 0; i < ROW; i++) {
		cout << static_cast<char>(i + 'A') << '\t';
		for (int j = 0; j < COL; j++) {
			cout << (seat[i][j] ? "��" : "��") << '\t';
		}
		cout << endl;
	}
}
void reserveSeat(int** (&seat), const int ROW, const int COL, int& reserved) {
	showSeat(seat, ROW, COL);
	cout << reserved << endl;
	if (reserved == ROW * COL) {
		cout << "�¼��� ���� ����Ǿ����ϴ�." << endl;
		system("pause");
		return;
	}
	while (true) {
		char seat_row;
		int seat_col;
		cout << "�¼� ����(ex) A1, B2)(���� : 00) : ";
		cin >> seat_row >> seat_col;
		if (cin.fail()) {
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (seat_row == '0' && seat_col == 0) {
			cout << "�޴��� �̵��մϴ�." << endl;
			break;
		}
		else if (seat_row < 'A' || seat_row >('A' + ROW) || seat_col < 1 || seat_col > COL) {
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���" << endl;
		}
		else if (seat[seat_row - 'A'][seat_col - 1])
			cout << "�̹� ����� �ڸ��Դϴ�." << endl;
		else {
			reserved++;
			int num = static_cast<int>(seat_row) * 100 + seat_col;
			seat[seat_row - 'A'][seat_col - 1] = num;
			cout << "�����ȣ " << num << "���� ����Ǿ����ϴ�." << endl;
			break;
		}
		system("pause");
	}
}
void cancelSeat(int** (&seat), const int ROW, const int COL, int& reserved) {
	showSeat(seat, ROW, COL);
	cout << reserved << endl;
	if (reserved == 0) {
		cout << "����� �¼��� �����ϴ�." << endl;
		system("pause");
		return;
	}
	while (true) {
		char seat_row;
		int seat_col;
		cout << "�¼� ����(ex) A1, B2)(���� : 00) : ";
		cin >> seat_row >> seat_col;
		if (cin.fail()) {
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (seat_row == '0' && seat_col == 0) {
			cout << "�޴��� �̵��մϴ�." << endl;
			break;
		}
		else if (seat_row < 'A' || seat_row >('A' + ROW) || seat_col < 1 || seat_col > COL) {
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���" << endl;
		}
		else if (seat[seat_row - 'A'][seat_col - 1]) {
			cout << "�����ȣ�� �Է��ϼ��� : ";
			int num;
			cin >> num;
			if ((static_cast<int>(seat_row) * 100 + seat_col) == num) {
				reserved--;
				cout << "�����ȣ " << num << "�� ���� ��ҵǾ����ϴ�." << endl;
				seat[seat_row - 'A'][seat_col - 1] = 0;
				break;
			}
			else {
				cout << "�����ȣ�� �߸��Ǿ����ϴ�. Ȯ�κ�Ź�帳�ϴ�." << endl;
			}
		}
		else { //���� �ȵ� �ڸ�
			cout << "������� ���� �¼��Դϴ�." << endl;
		}
		system("pause");
	}
	
}
void saveSeat(const string& filename, int** (&seat), const int row, const int col) {
	ofstream fout(filename);
	if (!fout.is_open()) {
		cerr << "���� ���� ����" << endl;
		return;
	}
	fout << row << " " << col << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fout << seat[i][j] << " ";
		}
		fout << endl;
	}
	cout << "���� ���� �Ϸ�" << endl;
}
void deleteSeat(int** (&seat), const int row) {
	for (int i = 0; i < row; i++)
		delete[] seat[i];
	delete[] seat;
	seat = nullptr;
}


void menu(const string& filename, int** (&seat),
	const int row, const int col, int& reserved) {

	int select = 0;
	do {
		system("cls");
		cout << "202110547 Ȳ����" << endl;
		cout << "1)�¼���Ȳ 2)�¼����� 3)������� 4)����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		cin >> select;
		switch (select) {
		case 1: showSeat(seat, row, col); break;
		case 2: reserveSeat(seat, row, col, reserved); break;
		case 3: cancelSeat(seat, row, col, reserved); break;
		}
		system("pause");
	} while (select != 4);
	saveSeat(filename, seat, row, col);
	deleteSeat(seat, row);
}

int** loadSeat(const string& filename, int& row, int& col, int& reserved) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		cerr << "���� �б� ����\n";
		return nullptr;
		// exit(0);
	}
	fin >> row >> col;

	INT(*seat) = new INT[row];
	for (int i = 0; i < row; i++)
		seat[i] = new int[col];
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
