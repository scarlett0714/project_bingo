#pragma once
#include <iostream>
using namespace std;
class CMyPoint
{
private:
	int x;
	int y;
public:
	CMyPoint();
	~CMyPoint();
	CMyPoint(const int x, const int y);
	CMyPoint(const CMyPoint& pt); //복사생성자
	CMyPoint(const CMyPoint&& pt) noexcept; //이동생성자

	friend ostream& operator<<(ostream& out, CMyPoint& ptr);
	bool operator<(const CMyPoint& pt);
	bool operator>(const CMyPoint& pt);
	bool operator==(const CMyPoint& pt);
};

