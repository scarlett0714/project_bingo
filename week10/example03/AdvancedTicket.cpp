#include "AdvancedTicket.h"
#include <iostream>
using namespace std;

AdvancedTicket::AdvancedTicket(const double& price, const int& days)
	: Ticket(price), advanceDays(days)
{
}

double AdvancedTicket::getPrice() const
{
	if (getAdvanceDays() >= 30) {
		return price * 0.5;
	}
	else if (getAdvanceDays() >= 20) {
		return price * 0.7;
	}
	else if (getAdvanceDays() >= 10) {
		return price * 0.9;
	}
	else
		return price;
	
		
	
}

int AdvancedTicket::getAdvanceDays() const
{
	return advanceDays;
}

void AdvancedTicket::show() const
{
	Ticket::show();
	cout << "사전예약일 : " << getAdvanceDays() << endl;
	cout << "가격정보 : " << getPrice() << endl << endl;
}
