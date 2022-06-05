#include <iostream>
#include <map>
#include "Student.h"
using namespace std;
int main() {
	cout << "----------------cppclassA----------------" << endl;
	cout << "-------------map.������ �߰�-------------" << endl;
	map<string, Student> cppclassA;
	//������ �ٲ㼭 �����͸� �߰��ص�, ������ ���ĵǾ ��µ�
	cppclassA["greenjoa1"] = Student("greenjoa1", "ȫ�浿", 60);
	cppclassA.insert({ "greenjoa2", Student("greenjoa2", "��浿", 70) });
	cppclassA.insert({ "greenjoa3", Student("greenjoa3", "�̱浿", 80) });
	cppclassA.emplace("greenjoa4", Student("greenjoa4", "�ֱ浿", 90)); //��ü�̵�, ���� X : pair��ü�� �����ؼ� �ֱ�

	//���
	for (const auto& p : cppclassA) { //pair
		cout << p.first << " : " << p.second << endl; //first : key, second : value
	}

	cout << "---------------map.find()---------------" << endl << endl;
	auto pos = cppclassA.find("greenjoa3"); //find -> iterator�� position���� ��ȯ
	if (pos != cppclassA.end()) { //�����Ͱ� �ִ� ���
		//���� iterator ��� : *pos
		//P : pair��ü�� ���� ���� ����X
		//S : 
		cout << pos->first << " : " << pos->second << endl;
	}

	//����2.
	cout << "----------------cppclassB----------------" << endl;
	map<string, Student> cppclassB;
	//������ �ٲ㼭 �����͸� �߰��ص�, ������ ���ĵǾ ��µ�
	cppclassB.insert({ "greenjoa5", Student("greenjoa5", "�ڱ浿", 77) });
	cppclassB.emplace("greenjoa6", Student("greenjoa6", "��浿", 85));
	cppclassB.insert({ "greenjoa3", Student("greenjoa3", "�̱浿", 80) });
	
	//���
	for (const auto& p : cppclassB) { //pair
		cout << p.first << " : " << p.second << endl; //first : key, second : value
	}

	cout << endl;

	//merge : �Ӽ� -> ���ǥ�� : C++17�� ����
	cout << "-------------map.merge(map)-------------" << endl;
	cppclassA.merge(cppclassB);

	cout << "----------------cppclassA----------------" << endl;
	//���
	for (const auto& p : cppclassA) { //pair
		cout << p.first << " : " << p.second << endl; //first : key, second : value
	}

	cout << "----------------cppclassB----------------" << endl;
	//���
	for (const auto& p : cppclassB) { //pair
		cout << p.first << " : " << p.second << endl; //first : key, second : value
	}

	cout << endl;
	//node
	cout << "---------map.extract(key) : node---------" << endl;
	auto node = cppclassA.extract("greenjoa1");
	cout << node.key() << " : " << node.mapped() << endl;
	//ex) A�� �л��̾��� greenjoa1�� B������ �̵�
	cppclassB.insert(move(node)); //A������ ���ŵ�

	cout << "----------------cppclassA----------------" << endl;
	//���
	for (const auto& p : cppclassA) { //pair
		cout << p.first << " : " << p.second << endl; //first : key, second : value
	}

	cout << "----------------cppclassB----------------" << endl;
	//��� : ������ ���ε� ���
	for (const auto& [key, value] : cppclassB) { //pair
		cout << key << " : " << value << endl;
	}



}