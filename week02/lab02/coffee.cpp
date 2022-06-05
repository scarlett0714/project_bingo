#include <iostream>

using namespace std;

int main(void) {
	cout << "202110547 황윤선" << endl;

	const int AMERICANO_P = 100;
	const int CAFELATTE_P = 200;

	
	while (1) {
		int americano = 0;
		int cafelatte = 0;
		
		int menu = 0;
		while (menu!=3) {
			cout << "1)아메리카노(100원) 2)카페라떼(200원) 3)결제 4)종료 선택하세요:";

			cin >> menu;

			switch (menu) {
			case 1:
				cout << "아메리카노를 주문하셨습니다.\n" << endl;
				americano++;
				break;
			case 2:
				cout << "카페라떼를 주문하셨습니다.\n" << endl;
				cafelatte++;
				break;
			case 3:
				cout << "======================" << endl;
				cout << "       결제금액       " << endl;
				cout << "======================" << endl;
				cout << "아메리카노 " << americano << "잔 " << AMERICANO_P * americano << "원" << endl;
				cout << "카페라떼 " << cafelatte << "잔 " << CAFELATTE_P * cafelatte << "원" << endl;
				cout << "======================" << endl;
				cout << "총 " << (AMERICANO_P * americano) + (CAFELATTE_P * cafelatte) << "원" << endl;
				cout << "=======================\n" << endl;
				cout << "결제가 완료되었습니다.\n" << endl;
				break;
			case 4:
				return 0;
			}

		}
	}
}