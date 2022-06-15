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

//C : 함수를 인자로 전달하는 방법
//int (*func)(int, int) : return(int), parameter(int, int), 함수이름은 주소값(*로 받기)
int calculate(int a, int b, int (*func)(int, int)) {
	return func(a, b);
}

//방법 1 : C++ 함수 객체 사용하는 방법
//auto calculate(int a, int b, plus<int> func) {
//	return func(a, b);
//}
//
//auto calculate(int a, int b, minus<int> func) {
//	return func(a, b);
//}

//방법 2: template
template<typename T>
auto calculate(int a, int b, T func) {
	return func(a, b);
}


//list
//방법1. 내림차순
bool sortdesc(int a, int b) {
	return a > b;
}

//방법1.
bool removescore(int a) {
	return a < 40;
}
int main() {
	//C언어
	cout << calculate(10, 20, add) << endl;
	cout << calculate(10, 20, sub) << endl;

	//C++
	plus<int> p1;
	minus<int> m1;
	cout << p1(10, 20) << endl;
	cout << calculate(10, 20, p1) << endl;
	cout << calculate(10, 20, m1) << endl;

	list<int> mylist = { 50,60,10,30,40,90 };
	//방법1. mylist.sort();
	
	//내림차순
	//방법1.
	//mylist.sort(sortdesc); //sort의 인자는 반드시 less than이나 greater than이 구현되어있어야함
	//방법2.
	mylist.sort(greater<>());
	for (auto it = mylist.begin(); it != mylist.end(); it++) {
		cout << *it << endl;
	}

	//사용자 정의 데이터 타입
	list<Student> stdlist;
	stdlist.push_back(Student("greenjoa1", "홍길동", 80));
	stdlist.push_back(Student("greenjoa2", "이길동", 90));
	stdlist.push_back(Student("greenjoa3", "엄길동", 60));
	stdlist.push_back(Student("greenjoa4", "최길동", 50));
	//오름차순 정렬
	stdlist.sort(); //sort의 기준 정의 필요 -> Student.h에 < or > 연산자 오버로딩

	//내림차순 정렬
	stdlist.sort(greater<>());
	
	for (auto it = stdlist.begin(); it != stdlist.end(); it++) {
		cout << *it << endl;
	}

	//삭제
	//방법1.
	//mylist.remove_if(removescore);
	//방법2. bind() 사용
	mylist.remove_if(bind(less<>(), _1, 40));
	//방법3. lambda 표현식 사용
	mylist.remove_if([](auto i) {return i < 40; });

	//사용자 정의 데이터 타입
	//equal_to 기준 정의 필요 -> Student.h에 == 연산자 오버로딩
	//방법1. bind() 사용
	stdlist.remove_if(bind(equal_to<>(), _1, Student("greenjoa3", "엄길동", 60)));
	//방법2. lambda 표현식 사용
	stdlist.remove_if([](auto i) {return i == Student("greenjoa3", "엄길동", 60); });
}