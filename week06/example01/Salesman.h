#pragma once
#include <string>
using std::string;
class Salesman
{
private:
	string m_name;
	double m_sales;

	//생성한 Salesman이 몇명인지 알고싶을 때 : count
	//int count = 0;으로 선언하면 객체가 생성될 때마다 count가 0으로 생성됨
	//static으로 선언 (static inline일 경우 : 클래스내부에서 초기화 가능)
	//프로젝트의 속성->구성 속성->일반->C++언어표준->C++17로 변경 : static inline사용
	static inline int count = 0;

	//static inline을 사용하지 않는 경우 : .cpp에 전역으로 초기화
	//static int count;

public:
	Salesman();

	//복사 생성자 정의
	Salesman(const Salesman& man);
	//대입을 통한 복사 생성자 막고 싶을 경우
	//explicit Salesman(const Salesman& man);

	Salesman(const char* name);
	explicit Salesman(const string& name);
	Salesman(const string& name, const double& sales);
	~Salesman();
	void setName(const string& name);

	//inline키워드 없이도 클래스 내부에 선언하면 자동inline
	string getName() {
		return this->m_name;
	}
	string getName() const{ //const는 오버로딩의 대상
		return this->m_name;
	}

	void readInput();
	string getSalesmanInfo();
	void setSales(const int& sales);
	double getSales();

	//friend
	friend void show(const Salesman& s);

	//static함수 : private한 static멤버인 count에 접근하기 위함
	static int getCount() {
		//this사용x : 객체를 생성해야해서
		return count;
	}

	//레퍼런스말고 callByValue : 복사 생성자 호출
	void showFriend(Salesman s); //Salesman s = s4;와 같음
};



