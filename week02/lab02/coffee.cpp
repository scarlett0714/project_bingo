#include <iostream>

using namespace std;

int main(void) {
	cout << "202110547 Ȳ����" << endl;

	const int AMERICANO_P = 100;
	const int CAFELATTE_P = 200;

	
	while (1) {
		int americano = 0;
		int cafelatte = 0;
		
		int menu = 0;
		while (menu!=3) {
			cout << "1)�Ƹ޸�ī��(100��) 2)ī���(200��) 3)���� 4)���� �����ϼ���:";

			cin >> menu;

			switch (menu) {
			case 1:
				cout << "�Ƹ޸�ī�븦 �ֹ��ϼ̽��ϴ�.\n" << endl;
				americano++;
				break;
			case 2:
				cout << "ī��󶼸� �ֹ��ϼ̽��ϴ�.\n" << endl;
				cafelatte++;
				break;
			case 3:
				cout << "======================" << endl;
				cout << "       �����ݾ�       " << endl;
				cout << "======================" << endl;
				cout << "�Ƹ޸�ī�� " << americano << "�� " << AMERICANO_P * americano << "��" << endl;
				cout << "ī��� " << cafelatte << "�� " << CAFELATTE_P * cafelatte << "��" << endl;
				cout << "======================" << endl;
				cout << "�� " << (AMERICANO_P * americano) + (CAFELATTE_P * cafelatte) << "��" << endl;
				cout << "=======================\n" << endl;
				cout << "������ �Ϸ�Ǿ����ϴ�.\n" << endl;
				break;
			case 4:
				return 0;
			}

		}
	}
}