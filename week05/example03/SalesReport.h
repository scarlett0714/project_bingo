#pragma once
#include "Salesman.h"
#include <memory> //스마트 포인터 이용
using std::unique_ptr;
using std::shared_ptr;

class SalesReport
{
private:
	//1. Salesman* team; //동적할당
	//2. unique_ptr<Salesman[]> team;
	//3.
	shared_ptr<Salesman[]> team;

	double highestSales;
	double averageSales;
	size_t m_number;

public:
	SalesReport();
	SalesReport(const size_t& number);
	~SalesReport();

	void computeStats();
	Salesman& getBestClerk();
	string getTeamInfo();
	size_t getNumber();
};

