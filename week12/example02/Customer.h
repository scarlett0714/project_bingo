#pragma once
#include <string>
#include <memory>
#include "Product.h"
#include <vector>
using std::string;
using std::unique_ptr;
using std::vector;

class Customer
{
private:
	string m_name;
	int m_number = 0;
	int m_count = 0;

	//방법1.
	//동적으로 아이템 구매 : 더블포인터 사용
	//Product** items; //Product* items[10] : 정적으로 고객별로 구매할 수 있는 아이템개수 제한할 경우
	
	//방법2. unique_ptr
	//unique_ptr<unique_ptr<Product>[]> items;

	//방법3. vector
	vector<unique_ptr<Product>> items; //배열의 크기에서 free~
public:
	Customer(const string& name, const int& number);
	~Customer();
	void buy(unique_ptr<Product> item); //void buy(Product* item);
	string getName() const;
	int getCount() const;
	void showlist() const;
	
	//내가 원하는 제품만 출력하기
	void showTVlist() const;
	void showVegetablelist() const;
};

