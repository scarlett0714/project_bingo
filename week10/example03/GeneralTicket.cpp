#include "GeneralTicket.h"
#include <iostream>

using namespace std;


GeneralTicket::GeneralTicket(const double& price, const bool& payByCredit)
	: Ticket(price), payByCredit(payByCredit)
{
}

double GeneralTicket::getPrice() const
{
	if (getPayByCredit()) {
		return price * 1.1;
	}
	else {
		return price;
	}
}

bool GeneralTicket::getPayByCredit() const
{
	return this->payByCredit;
}

void GeneralTicket::show() const
{
	Ticket::show();
	cout << "카드결재여부 : "<< boolalpha << getPayByCredit() << endl; //boolalpha : bool값을 문자열로 출력하기 위함
	cout << "가격정보 : " << getPrice() << endl << endl;
}
