#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Student.h"
using namespace std;

void printArr(const list<Student>& student) {
	//student의 값이 하나씩 복사되고 있는 중
	//복사하지 않고 참조만 하고 싶다면 : &

	//Q : 왜 오히려 &을 사용하면 오류가 뜰까
	for (auto std : student) {
		cout << std << " ";
	}
}

list<Student> getStudent(const list<list<Student>>& std, const list<Student>& droplist) {
	//매개변수를 복사하지 않고, 레퍼런스로 받기
	//매개변수를 수정하지 않을거야 : cosnt

	list<Student> list;
	//P : 복사하기 싫어서 auto& s로 받으면 오류발생
	//why? std가 const인데 sort()는 변경하는 함수
	//S1 : & 사용 금지
	//S2 : auto&를 사용하고 싶다면, 매개변수의 std의 const삭제
	for (auto s : std) { //auto : list<string>
		s.sort();
		//Student 정보 중, 이름, 성적 둘 중에 무엇으로 sort할건지 모름
		//대소비교 연산자 오버로딩 (<>)
		list.merge(s);
		list.unique();
	}

	for (auto name : droplist) { //auto : string
		list.remove(name);
		//remove를 진행할 때도 ==연산자 오버로딩 필요
		//엥? 분명 operator==정의했는데 왜 호출이 안될까?
		//const객체는 const함수만 호출가능
		//const멤버함수는 오버로딩 대상
	}

	return list;

}

int main() {

	cout << "202110547 황윤선" << endl;
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

	//전체 학생 중에서 droplist에 있는 학생 제외시키기
	auto student = getStudent(std, droplist); //list<string>
	printArr(student);
}