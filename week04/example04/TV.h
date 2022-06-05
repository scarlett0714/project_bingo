#pragma once
class TV {
private:
	bool m_isOn = false; //디폴트 값으로 자동 초기화x
	int m_volume =10;
	int m_channel=11;

public:
	void powerOnOff();
	void setVolume(int volume);
	int getVolume();
	void setChannel(int channel);
	int getChannel();
	void showStatus();
};
