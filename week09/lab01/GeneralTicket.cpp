#include "GeneralTicket.h"
#include <iostream>

using namespace std;

GeneralTicket::GeneralTicket()
	:GeneralTicket(0.0, true)
{
}

GeneralTicket::GeneralTicket(double price, bool payByCredit)
	: Ticket(price) //부모생성자
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
	cout << "티켓번호 : " << number << endl;
	cout << "가격정보 : " << price << endl;
	cout << "카드결재여부 : "<< boolalpha << getPayByCredit() << endl; //boolalpha : bool값을 문자열로 출력하기 위함
	cout << "가격정보 : " << getPrice() << endl;
}
