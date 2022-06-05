#include "Ticket.h"
#include <iostream>
using namespace std;
int i = 1;

Ticket::Ticket()
	:Ticket(0.0)
{
}

Ticket::Ticket(double price)
	:price(price), number(i++)
{
}

Ticket::~Ticket()
{
}

int Ticket::getNumber() const
{
	return number;
}

double Ticket::getPrice() const
{
	return price;
}

void Ticket::setPrice(const double& price)
{
	this->price = price;
}

void Ticket::show() const
{
	cout << "티켓번호 : " << number << endl;
	cout << "가격정보 : " << price << endl;
}
