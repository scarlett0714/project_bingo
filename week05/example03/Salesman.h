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
	~Salesman(); //소멸자

	void setName(string name);
	void readInput(); //정보 입력받기
	string getSalesmanInfo();
	void setSales(const int& sales);
	double getSales();
};

