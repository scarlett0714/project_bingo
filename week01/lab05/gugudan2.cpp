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
	while (1) {
		if (start <= end) {
			int i = 1;
			for (; i < 10; i++) {
				for (int j = start; j <= end; j++) {
					cout << j << "*" << i << "=" << setw(2) << j * i << "\t";
				}
				cout << endl;
			}
			break;
		}
		else {
			cout << "첫 번째 입력 숫자가 더 크므로, 시작과 끝의 값을 바꿔서 출력할까요(y/n)?";
			char ch;
			cin >> ch;
			if (ch == 'y') {
				int temp;
				temp = start;
				start = end;
				end = temp;
			}
			else if (ch == 'n') {
				break;
			}
		}
	}

	return 0;
}
