#include <iostream>
using std::cout;
using std::cin;

int main(void) {
	int val1, val2;

	cin >> val1 >> val2;
	char ch;
	cin >> ch;
	cout << val1 << "," << val2 << "," << ch << "\n";

	// �Է� : 100 enter 200 enter a
	// ��� : 100,200,a
	// �Է� : 100 200 a : �Է¹��ۿ� ��� ����ǰ� ������ �������� ����
	// ��� : 100,200,a

	return 0;

}