#include "Lamp.h"
#include <iostream>
using namespace std;
void Lamp::powerOnOff()
{
	isOn = !isOn;
}

void Lamp::changeLight()
{
	if (isOn) {
		switch (illuminance) {
		case 1:
			illuminance++;
			cout << "Á¶¸í¹à±â : " << illuminance << endl;
			break;
		case 2:
			illuminance++;
			cout << "Á¶¸í¹à±â : " << illuminance << endl;
			break;
		case 3:
			illuminance = 1;
			cout << "Á¶¸í¹à±â : " << illuminance << endl;
			break;
		}
	}
	else {
		cout << "Àü¿øÀÌ ²¨Á® ÀÖÀ½" << endl;
	}
}
