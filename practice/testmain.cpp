#include <iostream>
#include <string>
using namespace std;

class MP3 {
public:
	void play();
	void stop();
};

class MobilePhone {
public:
	bool sendCall();
	bool receiveCall();
	bool sendSMS();
	bool receiveSMS();
};

class MusicPhone : public MP3, public MobilePhone {
public:
	void dial();
};

void MusicPhone::dial()
{
	play();
	sendCall();
}

int main() {
	MusicPhone hanPhone;
	hanPhone.play();
	hanPhone.sendSMS();
}
