#include "Salesman.h"
#include <iostream>
using namespace std;

Salesman::Salesman() 
	: Salesman("NoInfo", 0.0){

}
Salesman::Salesman(const string& name) 
	: Salesman(name,0.0){

}
Salesman::Salesman(const string& name, const double& sales)
	: m_name(name), m_sales(sales){

}
Salesman::~Salesman() {

} //�Ҹ���

void Salesman::setName(string name) {
	m_name = name;
}
void Salesman::readInput() {
	cout << "�̸� : ";
	cin >> m_name;
	cout << "���� : ";
	cin >> m_sales;

} //���� �Է¹ޱ�
string Salesman::getSalesmanInfo() {
	return "�̸� : " + m_name + ", �Ǹž� : " + to_string(m_sales);
	//double�� �ٷ� string���� ���x -> to_string()���� ���ڿ��� ��ȯ
}
void Salesman::setSales(const int& sales) {
	m_sales = sales;
}
double Salesman::getSales() {
	return m_sales;

}
