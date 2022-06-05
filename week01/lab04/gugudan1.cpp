#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;

int main(void) {
	cout << "학번 : 202110547 이름 : 황윤선" << endl;

	cout << "구구단의 출력을 원하는 범위를 입력하세요(시작, 끝) : ";
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
		cout << "두 번째 입력 숫자가 더 커야 합니다." << endl;
	}

	return 0;
}
