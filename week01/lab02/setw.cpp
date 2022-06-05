#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

int main(void) {
	cout << "학번 : 202110547 이름 : 황윤선" << endl;
	int i = 1;

	for (; i < 10; i++) {
		for (int j = 2; j < 10; j++) {
			cout << j << "*" << i << "=" << setw(2) << j * i << "\t";
		}
		cout << endl;
	}

	return 0;
}
