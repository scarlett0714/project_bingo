#include <iostream>
using std::cout;
using std::cin;

int main(void) {
	int val1, val2;

	cin >> val1 >> val2;
	char ch;
	cin >> ch;
	cout << val1 << "," << val2 << "," << ch << "\n";

	// 입력 : 100 enter 200 enter a
	// 출력 : 100,200,a
	// 입력 : 100 200 a : 입력버퍼에 모두 저장되고 공백을 기준으로 읽음
	// 출력 : 100,200,a

	return 0;

}