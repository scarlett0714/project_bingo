#include <iostream>
#include <map>
#include "Student.h"
using namespace std;
int main() {
	cout << "----------------cppclassA----------------" << endl;
	cout << "-------------map.데이터 추가-------------" << endl;
	map<string, Student> cppclassA;
	//순서를 바꿔서 데이터를 추가해도, 순서가 정렬되어서 출력됨
	cppclassA["greenjoa1"] = Student("greenjoa1", "홍길동", 60);
	cppclassA.insert({ "greenjoa2", Student("greenjoa2", "김길동", 70) });
	cppclassA.insert({ "greenjoa3", Student("greenjoa3", "이길동", 80) });
	cppclassA.emplace("greenjoa4", Student("greenjoa4", "최길동", 90)); //객체이동, 복사 X : pair객체를 생성해서 넣기

	//출력
	for (const auto& p : cppclassA) { //pair
		cout << p.first << " : " << p.second << endl; //first : key, second : value
	}

	cout << "---------------map.find()---------------" << endl << endl;
	auto pos = cppclassA.find("greenjoa3"); //find -> iterator의 position정보 반환
	if (pos != cppclassA.end()) { //데이터가 있는 경우
		//기존 iterator 출력 : *pos
		//P : pair객체라 위와 같이 접근X
		//S : 
		cout << pos->first << " : " << pos->second << endl;
	}

	//예제2.
	cout << "----------------cppclassB----------------" << endl;
	map<string, Student> cppclassB;
	//순서를 바꿔서 데이터를 추가해도, 순서가 정렬되어서 출력됨
	cppclassB.insert({ "greenjoa5", Student("greenjoa5", "박길동", 77) });
	cppclassB.emplace("greenjoa6", Student("greenjoa6", "고길동", 85));
	cppclassB.insert({ "greenjoa3", Student("greenjoa3", "이길동", 80) });
	
	//출력
	for (const auto& p : cppclassB) { //pair
		cout << p.first << " : " << p.second << endl; //first : key, second : value
	}

	cout << endl;

	//merge : 속성 -> 언어표준 : C++17로 변경
	cout << "-------------map.merge(map)-------------" << endl;
	cppclassA.merge(cppclassB);

	cout << "----------------cppclassA----------------" << endl;
	//출력
	for (const auto& p : cppclassA) { //pair
		cout << p.first << " : " << p.second << endl; //first : key, second : value
	}

	cout << "----------------cppclassB----------------" << endl;
	//출력
	for (const auto& p : cppclassB) { //pair
		cout << p.first << " : " << p.second << endl; //first : key, second : value
	}

	cout << endl;
	//node
	cout << "---------map.extract(key) : node---------" << endl;
	auto node = cppclassA.extract("greenjoa1");
	cout << node.key() << " : " << node.mapped() << endl;
	//ex) A반 학생이었던 greenjoa1을 B반으로 이동
	cppclassB.insert(move(node)); //A에서는 제거됨

	cout << "----------------cppclassA----------------" << endl;
	//출력
	for (const auto& p : cppclassA) { //pair
		cout << p.first << " : " << p.second << endl; //first : key, second : value
	}

	cout << "----------------cppclassB----------------" << endl;
	//출력 : 구조적 바인딩 사용
	for (const auto& [key, value] : cppclassB) { //pair
		cout << key << " : " << value << endl;
	}



}