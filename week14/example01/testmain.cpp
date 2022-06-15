#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"
using namespace std;

int random() {
	return rand() % 100;
}

bool checkKim(const Student& std) {
	//�̸��� "��"�� �������� �� ã��
	if (std.getName().find("��") != string::npos) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	vector<int> vec(10);

	//generate() : �ʱ�ȭ
	//generate(vec.begin(), vec.end(), random);
	generate(vec.begin(), vec.end(), [] {return rand() % 100; }); //lambda
	
	//sort() : ����
	sort(vec.begin(), vec.end()); //��������
	sort(vec.begin(), vec.end(), greater<int>()); //��������

	//swap() : vector�� size�� �޶� ����
	//how? ������ �ּҰ� swap -> data() : �ּҰ� ��ȯ
	vector<int> vec2(5);
	generate(vec.begin(), vec.end(), [] {return rand() % 50; }); //lambda
	vec.swap(vec2); 

	//for_each
	for_each(vec.begin(), vec.end(), [](const int i) {cout << i << " "; });
	cout << endl;

	cout << "����� ���� ������ Ÿ��" << endl;
	vector<Student> std;
	std.push_back(Student("2001", "ȫ�浿", 80));
	std.push_back(Student("2004", "��浿", 70));
	std.push_back(Student("2003", "�ֱ浿", 90));
	std.push_back(Student("2002", "�̱浿", 100));
	std.push_back(Student("2002", "�����", 60));
	std.push_back(Student("2002", "�ֱ���", 95));
	std.push_back(Student("2002", "��ö��", 75));

	sort(std.begin(), std.end()); //��������
	sort(std.begin(), std.end(), greater<Student>()); //��������
	//P : greater<Student>��� �����ϸ� �����߻�
	//why? greater�̳� less�� ���ڸ� ���� ��, const�� ����
	//S : operator�� const �Լ��� ���� : ����� �������� �ʰڴ�

	//Q : �̹� score���ķ� ������ ���¿��� sid�� ������ �ϰ� �ʹٸ�?
	//A : ���� �Լ��� �����ؼ� �Լ���ü�� �����ϰų�, �����Լ��̿�
	sort(std.begin(), std.end(), [](const Student& left, const Student& right) {
		return left.getId() > right.getId(); //left�� const�̹Ƿ� getId()�� const�� �����
		});

	for_each(std.begin(), std.end(), [](const Student& i) {cout << i; });

	//find
	//operator==�� ���ǵǾ�����
	//vector<Student>::iterator it = find(std.begin(), std.end(), Student("2003", "�ֱ浿", 90));
	//operator==������ �ʿ�
	//vector<Student>::iterator it = find(std.begin(), std.end(), "�ֱ浿");
	
	//find_if
	vector<Student>::iterator it = std.begin();
	while (true) { //�ݺ��ؼ� ������ "��"�� �� �ָ� �� ã�ƺ�
		//1. it = find_if(it, std.end(), checkKim);
		// 
		//P : it = find_if(it, std.end(), Student("2003", "�ֱ浿", 90)); Student�� �Լ��� �ƴ�
		//S : ������ �����ε�
		//2. it = find_if(it, std.end(), Student("2003", "�ֱ浿", 90));
		// 
		//3. 
		it = find_if(it, std.end(), [](const Student& s) {return s.getScore() >= 90; });
		if (it != std.end()) {
			cout << distance(std.begin(), it) << "��° ������ : " << *it << endl;
			it++; //iterator ���� ��ġ�� ����
		}
		else {
			cout << "����" << endl;
			break;
		}
	}

	////remove
	//vector<Student>::iterator it = remove(std.begin(), std.end(), "��浿");
	////P : "��浿"�� ��������
	////S : erase�� ���� ���
	//std.erase(it, std.end());

	////remove_if
	//vector<Student>::iterator it = remove_if(std.begin(), std.end(), [](const Student& s) {return s.getScore() >= 90; });
	//std.erase(it, std.end());

	
}