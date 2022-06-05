#include "Ticket.h"
#include <iostream>
using namespace std;

Ticket::Ticket(const double& price)
	:price(price), number(++count)
{
}

int Ticket::getNumber() const
{
	return number;
}

//���������Լ�
/*double Ticket::getPrice() const
{
	return price;
}*/

void Ticket::setPrice(const double& price)
{
	this->price = price;
}

void Ticket::show() const
{
	cout << "Ƽ�Ϲ�ȣ : " << number << endl;
	cout << "�������� : " << price << endl;
}
