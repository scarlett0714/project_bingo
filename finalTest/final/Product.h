#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Product
{
protected:
	string id; //��Ϲ�ȣ
	string type; //��ǰ����
	int cnt; //��ǰ����
	int price; //��ǰ����

	vector<string> customer;

public:
	Product() = default;
	Product(const string& id, const string& type, const int& cnt, const int& price);
	virtual ~Product() = default; //virtual

	virtual void join(const string& customer) {};

	friend ostream& operator<<(ostream& out, Product& p);
	virtual string show() const = 0;
	friend ostream& operator<<(ostream& out, Product* product);

	int getPrice() {
		return price;
	}

};

