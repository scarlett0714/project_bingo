#include "Salesman.h"
#include <iostream>
using namespace std;

//���� �ʱ�ȭ
//int Salesman::count = 0;

Salesman::Salesman()
	:Salesman("NoInfo", 0.0)
{
}

Salesman::Salesman(const Salesman& man)
	: Salesman(man.m_name, man.m_sales)
{
	cout << "���� ������" << endl;
}

Salesman::Salesman(const char* name)
	: Salesman(name, 0.0)
{
}

Salesman::Salesman(const string& name)
	: Salesman(name, 0.0)
{
}

Salesman::Salesman(const string& name, const double& sales)
	: m_name(name), m_sales(sales)
{
	count++; //��ü�� ������ ������ count���� 1�� ����
}

Salesman::~Salesman()
{
	count--; //��ü�� �Ҹ�� ������ count���� 1�� ����
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

void Salesman::showFriend(Salesman s)
{
	cout << s.getSalesmanInfo() << endl;
}

string Salesman::getSalesmanInfo()
{
	return "�̸� : " + m_name + ", �Ǹž� : " + to_string(m_sales);
}

void Salesman::setSales(const int& sales)
{
	m_sales = sales;
}

