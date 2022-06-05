#include "CMyPoint.h"
CMyPoint::CMyPoint() : x(0), y(0)
{
	cout << x << "," << y << " ����Ʈ ������" << endl;
}

CMyPoint::~CMyPoint()
{
	cout << x << "," << y << " �Ҹ���" << endl;
}

CMyPoint::CMyPoint(const int x, const int y)
	: x(x), y(y)
{
	cout << x << "," << y << " ������" << endl;
}

CMyPoint::CMyPoint(const CMyPoint& pt) : x(pt.x), y(pt.y)
{
	cout << x << "," << y << " ���� ������" << endl;
}

CMyPoint::CMyPoint(const CMyPoint&& pt) noexcept : x(pt.x), y(pt.y)
{
	cout << x << "," << y << " �̵� ������" << endl;
}

bool CMyPoint::operator<(const CMyPoint& pt)
{
	return x < pt.x;
}

bool CMyPoint::operator>(const CMyPoint& pt)
{
	return x > pt.x;
}

bool CMyPoint::operator==(const CMyPoint& pt)
{
	return x == pt.x && y == pt.y;
}

ostream& operator<<(ostream& out, CMyPoint& pt) {
	//x, y�� private�̶� ������ �� �����Ƿ� friend�Լ��� ����
	out << pt.x << ", " << pt.y << endl;
	return out;
}
