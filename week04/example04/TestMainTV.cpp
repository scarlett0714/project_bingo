#include <iostream>
#include "TV.h"
#include "User.h"

using namespace std;

int main() {
	cout << "202110547 Ȳ����" << endl;
	/*cout << "TV1" << endl;
	TV tv;
	tv.powerOnOff();
	tv.setVolume(15);
	tv.setChannel(15);
	tv.powerOnOff();
	tv.setChannel(15);

	cout << "TV2" << endl;
	TV tv2;
	tv2.powerOnOff();

	tv.showStatus();*/

	TV tv1, tv2;
	User user1, user2;
	user1.setName("ȫ�浿");
	user2.setName("��浿");
	cout << "tv1" << endl;
	user1.turnOnOff(tv1);
	user1.changeChannel(tv1, 15);
	user1.changeVolume(tv1, 20);
	user2.turnOnOff(tv1); //������������
	tv1.showStatus();

	user2.turnOnOff(tv2);
	tv2.showStatus();

	return 0;
}