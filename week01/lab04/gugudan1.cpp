#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;

int main(void) {
	cout << "�й� : 202110547 �̸� : Ȳ����" << endl;

	cout << "�������� ����� ���ϴ� ������ �Է��ϼ���(����, ��) : ";
	int start, end;
	cin >> start >> end;
	if (start <= end) {
		int i = 1;
		for (; i < 10; i++) {
			for (int j = start; j <= end; j++) {
				cout << j << "*" << i << "=" << setw(2) << j * i << "\t";
			}
			cout << endl;
		}
	}
	else {
		cout << "�� ��° �Է� ���ڰ� �� Ŀ�� �մϴ�." << endl;
	}

	return 0;
}
