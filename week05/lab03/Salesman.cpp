#include "Salesman.h"
#include <iostream>
using namespace std;

Salesman::Salesman()
	:Salesman("NoInfo", 0.0)
{
}

Salesman::Salesman(const string& name)
	: Salesman(name, 0.0)
{
}

Salesman::Salesman(const string& name, const double& sales)
	: m_name(name), m_sales(sales)
{
}

Salesman::~Salesman()
{
}

void Salesman::setName(const string& name)
{
	m_name = name;
}

void Salesman::readInput()
{
	cout << "�̸� : ";
	cin >> m_name;

	cout << "���� : ";
	cin >> m_sales;
}

double Salesman::getSales()
{
	return m_sales;
}

string Salesman::getSalesmanInfo()
{
	return "�̸� : " + m_name + ", �Ǹž� : " + to_string(m_sales);
}

void Salesman::setSales(const int& sales)
{
	m_sales = sales;
}

