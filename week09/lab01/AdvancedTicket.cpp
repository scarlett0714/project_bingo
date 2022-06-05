#include "AdvancedTicket.h"
#include <iostream>
using namespace std;

AdvancedTicket::AdvancedTicket()
	:AdvancedTicket(0.0, 0)
{
}

AdvancedTicket::AdvancedTicket(double price, int days)
	: Ticket(price) //�θ� ������
{
	this->advanceDays = days;
}

AdvancedTicket::~AdvancedTicket()
{
}

double AdvancedTicket::getPrice() const
{
	if (this->getAdvanceDays() <= 10) {
		return this->price * 0.9;
	}
	else if (this->getAdvanceDays() <= 20) {
		return this->price * 0.7;
	}
	else if (this->getAdvanceDays() <= 30) {
		return this->price * 0.5;
	}
	else {
		return this->price;
	}
	
		
	
}

int AdvancedTicket::getAdvanceDays() const
{
	return this->advanceDays;
}

void AdvancedTicket::show() const
{
	cout << "Ƽ�Ϲ�ȣ : " << number << endl;
	cout << "�������� : " << price << endl;
	cout << "���������� : " << getAdvanceDays() << endl;
	cout << "�������� : " << getPrice() << endl;
}
