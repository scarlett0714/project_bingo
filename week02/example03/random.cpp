#include <iostream>
#include <string>
#include <ctime> //c언어에서 사용하는 시간
using namespace std;
int main() {
	constexpr int SIZE = 10;
	int num[SIZE];

	srand((unsigned)time(NULL)); //seed값
	cout << "==========" << endl;
	cout << "인덱스 값" << endl;
	cout << "==========" << endl;

	for (int i = 0; i < SIZE; i++) {
		num[i] = rand() % 100;
		cout << i << '\t' << num[i] << endl;
	}

	return 0;
}