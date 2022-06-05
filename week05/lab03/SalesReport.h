#pragma once
#include "Salesman.h"
#include <memory>
using std::unique_ptr;
using std::shared_ptr;

class SalesReport
{
private:
	//Salesman* : Salesman이 들어가는 배열
	//Salesman** : *를 저장하는 배열
	
	//Salesman* (*team);
	shared_ptr<Salesman* []> team;
	double highestSales;
	double averageSales;
	size_t m_number;
	size_t m_count = 0; //실제 배열에 들어가 있는 값 count

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



