#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Product
{
protected:
	string id; //등록번호
	string type; //제품유형
	int cnt; //제품개수
	int price; //제품가격

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

