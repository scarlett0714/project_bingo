#include <iostream>
#include "Lamp.h"
#include "User.h"

using namespace std;

int main() {
	cout << "202110547 È²À±¼±" << endl;

	/*cout << "Lamp" << endl;
	Lamp lamp;
	lamp.powerOnOff();
	lamp.changeLight();
	lamp.changeLight();
	lamp.changeLight();
	lamp.changeLight();
	lamp.changeLight();

	cout << "Lamp0" << endl;
	Lamp lamp0;
	lamp0.changeLight();*/

	Lamp lamp1, lamp2;
	User user1, user2;
	cout << "lamp1" << endl;
	user1.turnOnOff(lamp1);
	user1.changeLight(lamp1);
	user1.changeLight(lamp1);
	user1.changeLight(lamp1);
	user2.changeLight(lamp1);
	user2.turnOnOff(lamp1);

	cout << "lamp2" << endl;
	user2.turnOnOff(lamp2);
	user1.changeLight(lamp2);
	user1.changeLight(lamp2);
	user1.changeLight(lamp2);
	user1.changeLight(lamp2);

	return 0;
}