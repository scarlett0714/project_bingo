#include <iostream>
#include "TV.h"
#include "User.h"

using namespace std;

int main() {
	cout << "202110547 È²À±¼±" << endl;
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
	user1.setName("È«±æµ¿");
	user2.setName("±è±æµ¿");
	cout << "tv1" << endl;
	user1.turnOnOff(tv1);
	user1.changeChannel(tv1, 15);
	user1.changeVolume(tv1, 20);
	user2.turnOnOff(tv1); //Àü¿ø²¨Á®ÀÖÀ½
	tv1.showStatus();

	user2.turnOnOff(tv2);
	tv2.showStatus();

	return 0;
}