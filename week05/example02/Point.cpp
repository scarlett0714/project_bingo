#include "Point.h"
#include <iostream>
using namespace std;

Point::Point() : Point(0,0)
{
	cout << "����Ʈ ������" << endl;
}

Point::Point(const int& x, const int& y) : m_x(x), m_y(y)
{
	cout << m_x << "," << m_y << " : �����ִ� ������" << endl;
}

Point::~Point()
{
	cout << m_x << "," << m_y << " : �Ҹ���" << endl;
}

void Point::setX(const int& x)
{
	//�̴ϼȶ������� �����ڸ� ���
	m_x = x;
}

void Point::setY(const int& y)
{
	m_x = y;
}

int Point::getX()
{
	return m_x;
}

int Point::getY()
{
	return m_y;
}

void Point::drawPoint()
{
	cout << m_x << "," << m_y << endl;
}
