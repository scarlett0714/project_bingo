#include "AdvancedTicket.h"
#include <iostream>
using namespace std;

AdvancedTicket::AdvancedTicket()
	:AdvancedTicket(0.0, 0)
{
}

AdvancedTicket::AdvancedTicket(double price, int days)
	: Ticket(price) //부모 생성자
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
	cout << "티켓번호 : " << number << endl;
	cout << "가격정보 : " << price << endl;
	cout << "사전예약일 : " << getAdvanceDays() << endl;
	cout << "가격정보 : " << getPrice() << endl;
}
