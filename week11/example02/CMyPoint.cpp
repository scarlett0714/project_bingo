#include "CMyPoint.h"


CMyPoint::CMyPoint(const int x, const int y)
	: x(x), y(y)
{
}

bool CMyPoint::operator<(const CMyPoint& pt)
{
	return x < pt.x;
}

bool CMyPoint::operator>(const CMyPoint& pt)
{
	return x > pt.x;
}

ostream& operator<<(ostream& out, CMyPoint& pt) {
	//x, y가 private이라 접근할 수 없으므로 friend함수로 선언
	out << pt.x << ", " << pt.y << endl;
	return out;
}
