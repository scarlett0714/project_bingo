#include "SalesReport.h"
using namespace std;
using std::make_unique;

SalesReport::SalesReport() : SalesReport(0){

}
SalesReport::SalesReport(const size_t& number) 
	: m_number(number), averageSales(0.0), highestSales(0.0){ 
	//이니셜라이저에서 team 초기화 하기 : team(new Salesman[number]) / team(make_unique<Salesman[]>(number))
	//m_number가 아직 초기화되지 않았기 때문에, 이니셜라이저에서 배열을 생성할 땐, number사용
	//아니면 초기화되는 순서를 바꿔주기 : class멤버 선언 시, team보다 m_number를 먼저 선언
	
	if (m_number > 0) { //팀 멤버가 0명보다 많을때만 team 동적할당
		//1. team = new Salesman[m_number]; //디폴트 객체 생성
		//2. team = make_unique<Salesman[]>(m_number); //Salesman배열을 동적할당 : m_number개 만큼
		//3. 
		team = shared_ptr<Salesman[]>(new Salesman[m_number]);
		//Salesman배열을 동적할당 : 직접 배열 생성 new Salesman[m_number]


		for (size_t i = 0; i < m_number; i++) {
			team[i].readInput(); //객에체 관한 정보를 하나하나읽어 저장
		}
	}
	else
		team = nullptr;
}
SalesReport::~SalesReport() {
	//unique_ptr을 사용했으므로 delete구문 필요x
	/*
	if (team != nullptr) { //동적할당을 했으므로 delete
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
Salesman& SalesReport::getBestClerk() { //최고판매량 기록하는 사원정보 반환
	size_t bestIndex = 0;
	for (size_t i = 0; i < m_number; i++) {
		if (team[bestIndex].getSales() < team[i].getSales()) {
			bestIndex = i;
		}
	}
	return team[bestIndex];
}
string SalesReport::getTeamInfo() { //팀에 관한 정보 반환
	string info = "인원수 : " + to_string(m_number); //to_string 사용 : using namespace std;
	info += "\n평균 판매량 : " + to_string(averageSales);
	info += "\n최고 판매량 : " + to_string(highestSales) + "\n";

	return info;
}

size_t SalesReport::getNumber() {
	return m_number;
}
