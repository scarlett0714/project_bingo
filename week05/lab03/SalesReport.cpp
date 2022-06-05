#include "SalesReport.h"
#include <iostream>
using namespace std;
using std::make_unique;

SalesReport::SalesReport()
	:SalesReport(0)
{
}

SalesReport::SalesReport(const size_t& number)
	: m_number(number), averageSales(0.0), highestSales(0.0) //team(make_unique<Salesman*[]>(m_number))
{
	if (m_number > 0) {
		team = shared_ptr<Salesman* []>(new Salesman * [m_number]);
		//team = new Salesman* [m_number];		
	}
	else
		team = nullptr;
}

SalesReport::~SalesReport()
{
	//new : 배열생성, 객체생성 시 사용
	//동적할당해서 방에 들어가 있는 객체부터 delete->배열 delete
	
	/*
	if (team != nullptr) {
		for (int i = 0; i < m_count; i++) {
			delete team[i];
		}

		delete[] team;
	}*/
}

void SalesReport::computeStats() //팀의 실적정보 갱신
{
	if (team != nullptr) {
		double sum = team[0]->getSales(); //내 멤버 : . vs ->
		highestSales = team[0]->getSales();
		for (size_t i = 1; i < m_number; i++) {
			if (highestSales < team[i]->getSales()) {
				highestSales = team[i]->getSales();
			}
			sum += team[i]->getSales();
		}
		averageSales = sum / m_number;
	}
}

Salesman& SalesReport::getBestClerk()
{
	size_t bestIndex = 0;
	for (size_t i = 1; i < m_number; i++) {
		if (team[bestIndex]->getSales() < team[i]->getSales()) {
			bestIndex = i;
		}
	}
	return *team[bestIndex]; //주소가 참조하는 값을 리턴 : *사용
}

string SalesReport::getTeamInfo()
{
	string info = "인원수 : " + to_string(m_number);
	info += "\n평균 판매량 : " + to_string(averageSales);
	info += "\n최고 판매량 : " + to_string(highestSales) + "\n";

	return info;
}

size_t SalesReport::getNumber()
{
	return m_number;
}

void SalesReport::addMember()
{
	if (m_count < m_number) { //공간 존재
		//방법1
		team[m_count] = new Salesman(); //여기서 m_count++해버리면 뒤에 m_count방에 값이 없음
		team[m_count]->readInput();
		m_count++; //나중에 m_count값 증가

		/*방법2
		cout << "이름 : ";
		string name;
		cin >> name;
		cout << "판매금액 : ";
		double sales;
		cin >> sales;
		team[m_count++] = new Salesman(name, sales); //동적할당*/
	}
	else {
		cout << "빈방 없음" << endl;
	}
}

