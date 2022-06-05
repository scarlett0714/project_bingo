#pragma once
#include <string>
using std::string;

//�߻�Ŭ���� �� ��, abstractŰ���� ���x
class Product
{
protected:
	string m_name;
	int m_price;
public:
	Product(const string& name, const int& price);
	~Product();
	//���������Լ� : = 0
	virtual int getPrice() const = 0;
	string getName() const;
	virtual void show() const;
};

