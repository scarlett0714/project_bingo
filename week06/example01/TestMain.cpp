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

//객체를 수정하지 않을 것 : const (참조만 할 것)
void show(const Salesman& s) {
	cout << s.getName() << endl; 
	//P : getName()은 const함수가 아니라서 호출불가
	//S : 헤더파일에 getName() const로 const함수 선언해주면 자동으로 const함수 호출
	
	//getName()을 사용하지 않고 바로 멤버변수를 접근하고 싶은 경우
	//private멤버 접근 허용 : 헤더파일에 friend키워드 사용
	cout << s.m_name << endl;
}

int main() {

	Salesman s1;
	//show(s1);

	Salesman s2("greenjoa");
	
	Salesman* s3 = new Salesman(); //동적할당으로 객체생성
	cout << Salesman::getCount() << endl;
	delete s3;
	cout << Salesman::getCount() << endl;

	//객체로도 접근 가능 but static vs non-static인지 헷갈리므로 사용 지양
	cout << s1.getCount() << endl;
	cout << s1.getCount() << endl;

	Salesman s4("greenjoa", 200.0);
	//컴파일러가 타입이 같을 경우 자동으로 복사생성자를 만들어서 호출
	Salesman s5 = s4; //대입으로 객체 생성
	Salesman s6(s5);

	cout << s5.getSalesmanInfo() << endl;

	//Salesman s7 = "greenjoa"; 
	//P : 오류발생
	auto str = "greenjoa";
	cout << typeid(str).name() << endl; //const char*
	//S : const char*타입에 대한 생성자 만들기
	Salesman s7 = "greenjoa"; //묵시적으로 const char*생성자호출해서 형변환

	//위의 방법을 사용하지 않고, string타입으로 바꾸는 방법
	//문자열 뒤에 s연산자 사용
	auto str2 = "greenjoa"s; //string타입의 생성자 호출
	cout << typeid(str2).name() << endl;

	//묵시적인 형변환 제한 : .h에서 explicit키워드 사용
	Salesman s8("greenjoa"); //생성자를 통해서만 객체 생성 가능


	//복사 생성자
	Salesman copy1(s2);
	Salesman copy2 = s4; //대입을 통해 생성
	//위 방법을 막고 싶다면 복사 생성자 추가 + explicit키워드
	cout << copy1.getSalesmanInfo() << endl;
	cout << copy2.getSalesmanInfo() << endl;

	Salesman copy3 = Salesman("greenjoa"); //임시객체를 대입
	//복사 생성자가 호출되지 않고 컴파일러가 바로 객체 생성

	cout << "=================" << endl;
	copy3.showFriend(s4);

	cout << "=================" << endl;
	Salesman s9 = getSalesman("greenjoa"); //s반환
	//getSalesman에서 객체 s를 생성하고 반환한 것을 s9에 대입 -> 복사 생성자 호출

	cout << "=================" << endl;
	Salesman s10 = getSalesman2("greenjoa"); //Salesman(name)반환
	//복사 생성자가 호출되지 않고 컴파일러가 바로 객체 생성
}