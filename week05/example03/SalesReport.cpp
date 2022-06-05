#include "SalesReport.h"
using namespace std;
using std::make_unique;

SalesReport::SalesReport() : SalesReport(0){

}
SalesReport::SalesReport(const size_t& number) 
	: m_number(number), averageSales(0.0), highestSales(0.0){ 
	//�̴ϼȶ��������� team �ʱ�ȭ �ϱ� : team(new Salesman[number]) / team(make_unique<Salesman[]>(number))
	//m_number�� ���� �ʱ�ȭ���� �ʾұ� ������, �̴ϼȶ��������� �迭�� ������ ��, number���
	//�ƴϸ� �ʱ�ȭ�Ǵ� ������ �ٲ��ֱ� : class��� ���� ��, team���� m_number�� ���� ����
	
	if (m_number > 0) { //�� ����� 0���� �������� team �����Ҵ�
		//1. team = new Salesman[m_number]; //����Ʈ ��ü ����
		//2. team = make_unique<Salesman[]>(m_number); //Salesman�迭�� �����Ҵ� : m_number�� ��ŭ
		//3. 
		team = shared_ptr<Salesman[]>(new Salesman[m_number]);
		//Salesman�迭�� �����Ҵ� : ���� �迭 ���� new Salesman[m_number]


		for (size_t i = 0; i < m_number; i++) {
			team[i].readInput(); //����ü ���� ������ �ϳ��ϳ��о� ����
		}
	}
	else
		team = nullptr;
}
SalesReport::~SalesReport() {
	//unique_ptr�� ��������Ƿ� delete���� �ʿ�x
	/*
	if (team != nullptr) { //�����Ҵ��� �����Ƿ� delete
		delete[] team;
	}*/
}

void SalesReport::computeStats() {
	if (team != nullptr) {
		double sum = team[0].getSales();
		highestSales = team[0].getSales();
		for (size_t i = 0; i < m_number; i++) {
			if (highestSales < team[i].getSales()) {
				highestSales = team[i].getSales();
			}
			sum += team[i].getSales();
		}
		averageSales = sum / m_number;
	}
}
Salesman& SalesReport::getBestClerk() { //�ְ��Ǹŷ� ����ϴ� ������� ��ȯ
	size_t bestIndex = 0;
	for (size_t i = 0; i < m_number; i++) {
		if (team[bestIndex].getSales() < team[i].getSales()) {
			bestIndex = i;
		}
	}
	return team[bestIndex];
}
string SalesReport::getTeamInfo() { //���� ���� ���� ��ȯ
	string info = "�ο��� : " + to_string(m_number); //to_string ��� : using namespace std;
	info += "\n��� �Ǹŷ� : " + to_string(averageSales);
	info += "\n�ְ� �Ǹŷ� : " + to_string(highestSales) + "\n";

	return info;
}

size_t SalesReport::getNumber() {
	return m_number;
}
