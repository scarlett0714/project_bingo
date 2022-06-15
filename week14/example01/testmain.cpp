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
	//이름에 "김"이 들어가있으면 다 찾음
	if (std.getName().find("김") != string::npos) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	vector<int> vec(10);

	//generate() : 초기화
	//generate(vec.begin(), vec.end(), random);
	generate(vec.begin(), vec.end(), [] {return rand() % 100; }); //lambda
	
	//sort() : 정렬
	sort(vec.begin(), vec.end()); //오름차순
	sort(vec.begin(), vec.end(), greater<int>()); //내림차순

	//swap() : vector의 size가 달라도 가능
	//how? 서로의 주소값 swap -> data() : 주소값 반환
	vector<int> vec2(5);
	generate(vec.begin(), vec.end(), [] {return rand() % 50; }); //lambda
	vec.swap(vec2); 

	//for_each
	for_each(vec.begin(), vec.end(), [](const int i) {cout << i << " "; });
	cout << endl;

	cout << "사용자 정의 데이터 타입" << endl;
	vector<Student> std;
	std.push_back(Student("2001", "홍길동", 80));
	std.push_back(Student("2004", "김길동", 70));
	std.push_back(Student("2003", "최길동", 90));
	std.push_back(Student("2002", "이길동", 100));
	std.push_back(Student("2002", "김길자", 60));
	std.push_back(Student("2002", "최길자", 95));
	std.push_back(Student("2002", "김철수", 75));

	sort(std.begin(), std.end()); //오름차순
	sort(std.begin(), std.end(), greater<Student>()); //내림차순
	//P : greater<Student>라고 선언하면 오류발생
	//why? greater이나 less가 인자를 받을 때, const로 받음
	//S : operator를 const 함수로 선언 : 멤버를 변경하지 않겠다

	//Q : 이미 score정렬로 지정한 상태에서 sid로 정렬을 하고 싶다면?
	//A : 새로 함수를 정의해서 함수객체를 전달하거나, 람다함수이용
	sort(std.begin(), std.end(), [](const Student& left, const Student& right) {
		return left.getId() > right.getId(); //left가 const이므로 getId()도 const로 만들기
		});

	for_each(std.begin(), std.end(), [](const Student& i) {cout << i; });

	//find
	//operator==는 정의되어있음
	//vector<Student>::iterator it = find(std.begin(), std.end(), Student("2003", "최길동", 90));
	//operator==재정의 필요
	//vector<Student>::iterator it = find(std.begin(), std.end(), "최길동");
	
	//find_if
	vector<Student>::iterator it = std.begin();
	while (true) { //반복해서 돌려야 "김"자 들어간 애를 다 찾아봄
		//1. it = find_if(it, std.end(), checkKim);
		// 
		//P : it = find_if(it, std.end(), Student("2003", "최길동", 90)); Student는 함수가 아님
		//S : 연산자 오버로딩
		//2. it = find_if(it, std.end(), Student("2003", "최길동", 90));
		// 
		//3. 
		it = find_if(it, std.end(), [](const Student& s) {return s.getScore() >= 90; });
		if (it != std.end()) {
			cout << distance(std.begin(), it) << "번째 존재함 : " << *it << endl;
			it++; //iterator 다음 위치로 변경
		}
		else {
			cout << "없음" << endl;
			break;
		}
	}

	////remove
	//vector<Student>::iterator it = remove(std.begin(), std.end(), "김길동");
	////P : "김길동"이 남아있음
	////S : erase와 같이 사용
	//std.erase(it, std.end());

	////remove_if
	//vector<Student>::iterator it = remove_if(std.begin(), std.end(), [](const Student& s) {return s.getScore() >= 90; });
	//std.erase(it, std.end());

	
}