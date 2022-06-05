#include "TV.h"
#include <iostream>

using namespace std;


void TV::powerOnOff()
{
	m_isOn = !m_isOn;
	showStatus();
}

void TV::setVolume(int volume)
{
	if (m_isOn) {
		m_volume = volume;
	}
	showStatus();
}

int TV::getVolume()
{
	return m_volume;
}

void TV::setChannel(int channel)
{
	if (m_isOn) {
		m_channel = channel;
	}
	showStatus();
}

int TV::getChannel()
{
	return m_channel;
}

void TV::showStatus()
{
	if (m_isOn) {
		cout << "���� : " << m_volume << endl;
		cout << "ä�� : " << m_channel << "�� ��û��" << endl;
	}
	else {
		cout << "������ ���� ����" << endl;
	}
}
