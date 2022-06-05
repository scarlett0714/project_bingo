#include "Salesman.h"
#include <iostream>
using namespace std;

//전역 초기화
//int Salesman::count = 0;

Salesman::Salesman()
	:Salesman("NoInfo", 0.0)
{
}

Salesman::Salesman(const Salesman& man)
	: Salesman(man.m_name, man.m_sales)
{
	cout << "복사 생성자" << endl;
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
	count++; //객체가 생성될 때마다 count변수 1씩 증가
}

Salesman::~Salesman()
{
	count--; //객체가 소멸될 때마다 count변수 1씩 감소
}

void Salesman::setName(const string& name)
{
	m_name = name;
}

void Salesman::readInput()
{
	cout << "이름 : ";
	cin >> m_name;

	cout << "실적 : ";
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
	return "이름 : " + m_name + ", 판매액 : " + to_string(m_sales);
}

void Salesman::setSales(const int& sales)
{
	m_sales = sales;
}

