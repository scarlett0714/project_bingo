#pragma once
#include <string>
using std::string;

//추상클래스 일 때, abstract키워드 사용x
class Product
{
protected:
	string m_name;
	int m_price;
public:
	Product(const string& name, const int& price);
	~Product();
	//순수가상함수 : = 0
	virtual int getPrice() const = 0;
	string getName() const;
	virtual void show() const;
};

