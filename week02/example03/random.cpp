#include <iostream>
#include <string>
#include <ctime> //c���� ����ϴ� �ð�
using namespace std;
int main() {
	constexpr int SIZE = 10;
	int num[SIZE];

	srand((unsigned)time(NULL)); //seed��
	cout << "==========" << endl;
	cout << "�ε��� ��" << endl;
	cout << "==========" << endl;

	for (int i = 0; i < SIZE; i++) {
		num[i] = rand() % 100;
		cout << i << '\t' << num[i] << endl;
	}

	return 0;
}