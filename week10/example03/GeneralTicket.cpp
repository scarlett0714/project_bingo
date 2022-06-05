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
	cout << "ī����翩�� : "<< boolalpha << getPayByCredit() << endl; //boolalpha : bool���� ���ڿ��� ����ϱ� ����
	cout << "�������� : " << getPrice() << endl << endl;
}
