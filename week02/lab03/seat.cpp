#include <iostream>
#include <string>
#include <ctime>

using namespace std;
int main() {
	
	constexpr int ROW = 6;
	constexpr int COL = 4;
	bool seats[ROW][COL]{};

	while (1) {
		system("cls"); //ȭ�� �����
		cout << "202110547 Ȳ����" << endl;
		for (int i = 0; i < COL; i++) {
			cout << '\t' << i + 1;
		}
		cout << "\n\n";
		for (int i = 0; i < ROW; i++) {
			cout << static_cast<char>('A' + i) << '\t';
			for (int j = 0; j < COL; j++) {
				cout << (seats[i][j] ? "��" : "��") << '\t';
			}
			cout << "\n\n";
		}

		cout << "�����Ϸ��� qq�� �Է��ϼ���.\n";
		cout << "�¼� �Է� (ex==> A1) : ";
		char x, y;
		cin >> x >> y;
		if (!(x == 'q' && y == 'q')) {
			if (x >= 'A' && x <= 'F' && y >= '1' && y <= '4') {
				if (seats[x - 'A'][y - '1']) {
					cout << "�̹� ����� �ڸ��Դϴ�.\n";
				}
				else {
					seats[x - 'A'][y - '1'] = true;
					cout << "������ �Ϸ�Ǿ����ϴ�.\n";
				}
				system("pause"); //��� ����
			}
			else {
				cout << "������ ���� ���� �¼��� �Է��ϼ���." << endl;
				system("pause");

			}
		}
		else {
			cout << "�����մϴ�." << endl;
			return 0;
		}
	}

	return 0;
}