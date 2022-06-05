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
	//new : �迭����, ��ü���� �� ���
	//�����Ҵ��ؼ� �濡 �� �ִ� ��ü���� delete->�迭 delete
	
	/*
	if (team != nullptr) {
		for (int i = 0; i < m_count; i++) {
			delete team[i];
		}

		delete[] team;
	}*/
}

void SalesReport::computeStats() //���� �������� ����
{
	if (team != nullptr) {
		double sum = team[0]->getSales(); //�� ��� : . vs ->
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
	return *team[bestIndex]; //�ּҰ� �����ϴ� ���� ���� : *���
}

string SalesReport::getTeamInfo()
{
	string info = "�ο��� : " + to_string(m_number);
	info += "\n��� �Ǹŷ� : " + to_string(averageSales);
	info += "\n�ְ� �Ǹŷ� : " + to_string(highestSales) + "\n";

	return info;
}

size_t SalesReport::getNumber()
{
	return m_number;
}

void SalesReport::addMember()
{
	if (m_count < m_number) { //���� ����
		//���1
		team[m_count] = new Salesman(); //���⼭ m_count++�ع����� �ڿ� m_count�濡 ���� ����
		team[m_count]->readInput();
		m_count++; //���߿� m_count�� ����

		/*���2
		cout << "�̸� : ";
		string name;
		cin >> name;
		cout << "�Ǹűݾ� : ";
		double sales;
		cin >> sales;
		team[m_count++] = new Salesman(name, sales); //�����Ҵ�*/
	}
	else {
		cout << "��� ����" << endl;
	}
}

