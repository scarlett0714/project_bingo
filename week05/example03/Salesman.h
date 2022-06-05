#pragma once
#include <string>
using std::string;

class Salesman
{
private:
	string m_name;
	double m_sales;

public:
	Salesman();
	Salesman(const string& name);
	Salesman(const string& name, const double& sales);
	~Salesman(); //�Ҹ���

	void setName(string name);
	void readInput(); //���� �Է¹ޱ�
	string getSalesmanInfo();
	void setSales(const int& sales);
	double getSales();
};

