#include <iostream>
#include <list>
#include <functional>
#include "Student.h"
using namespace std;
using namespace std::placeholders;

int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}

//C : �Լ��� ���ڷ� �����ϴ� ���
//int (*func)(int, int) : return(int), parameter(int, int), �Լ��̸��� �ּҰ�(*�� �ޱ�)
int calculate(int a, int b, int (*func)(int, int)) {
	return func(a, b);
}

//��� 1 : C++ �Լ� ��ü ����ϴ� ���
//auto calculate(int a, int b, plus<int> func) {
//	return func(a, b);
//}
//
//auto calculate(int a, int b, minus<int> func) {
//	return func(a, b);
//}

//��� 2: template
template<typename T>
auto calculate(int a, int b, T func) {
	return func(a, b);
}


//list
//���1. ��������
bool sortdesc(int a, int b) {
	return a > b;
}

//���1.
bool removescore(int a) {
	return a < 40;
}
int main() {
	//C���
	cout << calculate(10, 20, add) << endl;
	cout << calculate(10, 20, sub) << endl;

	//C++
	plus<int> p1;
	minus<int> m1;
	cout << p1(10, 20) << endl;
	cout << calculate(10, 20, p1) << endl;
	cout << calculate(10, 20, m1) << endl;

	list<int> mylist = { 50,60,10,30,40,90 };
	//���1. mylist.sort();
	
	//��������
	//���1.
	//mylist.sort(sortdesc); //sort�� ���ڴ� �ݵ�� less than�̳� greater than�� �����Ǿ��־����
	//���2.
	mylist.sort(greater<>());
	for (auto it = mylist.begin(); it != mylist.end(); it++) {
		cout << *it << endl;
	}

	//����� ���� ������ Ÿ��
	list<Student> stdlist;
	stdlist.push_back(Student("greenjoa1", "ȫ�浿", 80));
	stdlist.push_back(Student("greenjoa2", "�̱浿", 90));
	stdlist.push_back(Student("greenjoa3", "���浿", 60));
	stdlist.push_back(Student("greenjoa4", "�ֱ浿", 50));
	//�������� ����
	stdlist.sort(); //sort�� ���� ���� �ʿ� -> Student.h�� < or > ������ �����ε�

	//�������� ����
	stdlist.sort(greater<>());
	
	for (auto it = stdlist.begin(); it != stdlist.end(); it++) {
		cout << *it << endl;
	}

	//����
	//���1.
	//mylist.remove_if(removescore);
	//���2. bind() ���
	mylist.remove_if(bind(less<>(), _1, 40));
	//���3. lambda ǥ���� ���
	mylist.remove_if([](auto i) {return i < 40; });

	//����� ���� ������ Ÿ��
	//equal_to ���� ���� �ʿ� -> Student.h�� == ������ �����ε�
	//���1. bind() ���
	stdlist.remove_if(bind(equal_to<>(), _1, Student("greenjoa3", "���浿", 60)));
	//���2. lambda ǥ���� ���
	stdlist.remove_if([](auto i) {return i == Student("greenjoa3", "���浿", 60); });
}