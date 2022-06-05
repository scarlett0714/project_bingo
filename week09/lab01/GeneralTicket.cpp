#include "GeneralTicket.h"
#include <iostream>

using namespace std;

GeneralTicket::GeneralTicket()
	:GeneralTicket(0.0, true)
{
}

GeneralTicket::GeneralTicket(double price, bool payByCredit)
	: Ticket(price) //�θ������
{
	this->payByCredit = payByCredit;
}

GeneralTicket::~GeneralTicket()
{
}

double GeneralTicket::getPrice() const
{
	if (this->getPayByCredit() == true) {
		return this->price * 1.1;
	}
	else {
		return this->price;
	}
}

bool GeneralTicket::getPayByCredit() const
{
	return this->payByCredit;
}

void GeneralTicket::show() const
{
	cout << "Ƽ�Ϲ�ȣ : " << number << endl;
	cout << "�������� : " << price << endl;
	cout << "ī����翩�� : "<< boolalpha << getPayByCredit() << endl; //boolalpha : bool���� ���ڿ��� ����ϱ� ����
	cout << "�������� : " << getPrice() << endl;
}
