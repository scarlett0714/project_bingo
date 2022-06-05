#pragma once
#include <string>
#include <memory>
#include "Product.h"
using std::string;
using std::unique_ptr;

class Customer
{
private:
	string m_name;
	int m_number = 0;
	int m_count = 0;

	//���1.
	//�������� ������ ���� : ���������� ���
	//Product** items; //Product* items[10] : �������� ������ ������ �� �ִ� �����۰��� ������ ���
	
	//���2. unique_ptr
	unique_ptr<unique_ptr<Product>[]> items;
public:
	Customer(const string& name, const int& number);
	~Customer();
	void buy(unique_ptr<Product> item); //void buy(Product* item);
	string getName() const;
	int getCount() const;
	void showlist() const;
	
	//���� ���ϴ� ��ǰ�� ����ϱ�
	void showTVlist() const;
	void showVegetablelist() const;
};

