#include <iostream>
#include "Salesman.h"
using namespace std;

/*void show(Salesman& s) {
	cout << s.getName() << endl;
}*/

Salesman getSalesman(const string& name) {
	Salesman s(name);
	return s;
}

Salesman getSalesman2(const string& name) {
	return Salesman(name);
}

//��ü�� �������� ���� �� : const (������ �� ��)
void show(const Salesman& s) {
	cout << s.getName() << endl; 
	//P : getName()�� const�Լ��� �ƴ϶� ȣ��Ұ�
	//S : ������Ͽ� getName() const�� const�Լ� �������ָ� �ڵ����� const�Լ� ȣ��
	
	//getName()�� ������� �ʰ� �ٷ� ��������� �����ϰ� ���� ���
	//private��� ���� ��� : ������Ͽ� friendŰ���� ���
	cout << s.m_name << endl;
}

int main() {

	Salesman s1;
	//show(s1);

	Salesman s2("greenjoa");
	
	Salesman* s3 = new Salesman(); //�����Ҵ����� ��ü����
	cout << Salesman::getCount() << endl;
	delete s3;
	cout << Salesman::getCount() << endl;

	//��ü�ε� ���� ���� but static vs non-static���� �򰥸��Ƿ� ��� ����
	cout << s1.getCount() << endl;
	cout << s1.getCount() << endl;

	Salesman s4("greenjoa", 200.0);
	//�����Ϸ��� Ÿ���� ���� ��� �ڵ����� ��������ڸ� ���� ȣ��
	Salesman s5 = s4; //�������� ��ü ����
	Salesman s6(s5);

	cout << s5.getSalesmanInfo() << endl;

	//Salesman s7 = "greenjoa"; 
	//P : �����߻�
	auto str = "greenjoa";
	cout << typeid(str).name() << endl; //const char*
	//S : const char*Ÿ�Կ� ���� ������ �����
	Salesman s7 = "greenjoa"; //���������� const char*������ȣ���ؼ� ����ȯ

	//���� ����� ������� �ʰ�, stringŸ������ �ٲٴ� ���
	//���ڿ� �ڿ� s������ ���
	auto str2 = "greenjoa"s; //stringŸ���� ������ ȣ��
	cout << typeid(str2).name() << endl;

	//�������� ����ȯ ���� : .h���� explicitŰ���� ���
	Salesman s8("greenjoa"); //�����ڸ� ���ؼ��� ��ü ���� ����


	//���� ������
	Salesman copy1(s2);
	Salesman copy2 = s4; //������ ���� ����
	//�� ����� ���� �ʹٸ� ���� ������ �߰� + explicitŰ����
	cout << copy1.getSalesmanInfo() << endl;
	cout << copy2.getSalesmanInfo() << endl;

	Salesman copy3 = Salesman("greenjoa"); //�ӽð�ü�� ����
	//���� �����ڰ� ȣ����� �ʰ� �����Ϸ��� �ٷ� ��ü ����

	cout << "=================" << endl;
	copy3.showFriend(s4);

	cout << "=================" << endl;
	Salesman s9 = getSalesman("greenjoa"); //s��ȯ
	//getSalesman���� ��ü s�� �����ϰ� ��ȯ�� ���� s9�� ���� -> ���� ������ ȣ��

	cout << "=================" << endl;
	Salesman s10 = getSalesman2("greenjoa"); //Salesman(name)��ȯ
	//���� �����ڰ� ȣ����� �ʰ� �����Ϸ��� �ٷ� ��ü ����
}