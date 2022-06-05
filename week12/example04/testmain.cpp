#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Student.h"
using namespace std;

void printArr(const list<Student>& student) {
	//student�� ���� �ϳ��� ����ǰ� �ִ� ��
	//�������� �ʰ� ������ �ϰ� �ʹٸ� : &

	//Q : �� ������ &�� ����ϸ� ������ ���
	for (auto std : student) {
		cout << std << " ";
	}
}

list<Student> getStudent(const list<list<Student>>& std, const list<Student>& droplist) {
	//�Ű������� �������� �ʰ�, ���۷����� �ޱ�
	//�Ű������� �������� �����ž� : cosnt

	list<Student> list;
	//P : �����ϱ� �Ⱦ auto& s�� ������ �����߻�
	//why? std�� const�ε� sort()�� �����ϴ� �Լ�
	//S1 : & ��� ����
	//S2 : auto&�� ����ϰ� �ʹٸ�, �Ű������� std�� const����
	for (auto s : std) { //auto : list<string>
		s.sort();
		//Student ���� ��, �̸�, ���� �� �߿� �������� sort�Ұ��� ��
		//��Һ� ������ �����ε� (<>)
		list.merge(s);
		list.unique();
	}

	for (auto name : droplist) { //auto : string
		list.remove(name);
		//remove�� ������ ���� ==������ �����ε� �ʿ�
		//��? �и� operator==�����ߴµ� �� ȣ���� �ȵɱ�?
		//const��ü�� const�Լ��� ȣ�Ⱑ��
		//const����Լ��� �����ε� ���
	}

	return list;

}

int main() {

	cout << "202110547 Ȳ����" << endl;
	list<list<Student>> std;
	std.push_back({ Student("greenjoa1", 10), Student("bluejoa1", 10), Student("greenjoa3", 30) });
	std.push_back({ Student("greenjoa1", 10), Student("greenjoa3", 30) });
	std.push_back({ Student("redjoa1", 10), Student("greenjoa2", 20), Student("bluejoa2", 20) });
	list<Student> droplist({ Student("greenjoa2", 20), Student("bluejoa1", 10) });

	for (auto s : std) {
		for (auto s1 : s) {
			cout << s1 << endl;
		}
	}

	//��ü �л� �߿��� droplist�� �ִ� �л� ���ܽ�Ű��
	auto student = getStudent(std, droplist); //list<string>
	printArr(student);
}