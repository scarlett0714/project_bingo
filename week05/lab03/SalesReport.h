#pragma once
#include "Salesman.h"
#include <memory>
using std::unique_ptr;
using std::shared_ptr;

class SalesReport
{
private:
	//Salesman* : Salesman�� ���� �迭
	//Salesman** : *�� �����ϴ� �迭
	
	//Salesman* (*team);
	shared_ptr<Salesman* []> team;
	double highestSales;
	double averageSales;
	size_t m_number;
	size_t m_count = 0; //���� �迭�� �� �ִ� �� count

public:
	SalesReport();
	SalesReport(const size_t& number);
	~SalesReport();
	void computeStats();
	Salesman& getBestClerk();
	string getTeamInfo();
	size_t getNumber();
	void addMember();
};



