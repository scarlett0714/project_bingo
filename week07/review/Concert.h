#pragma once
#include <string>
#include <memory>
using std::string;
using std::shared_ptr;
using std::unique_ptr;

class Concert
{
private:
	string name;//공연명
	int capacity;//수용가능한 좌석
	int num = 0;//예약한 수
	//string* rList = nullptr;//예약한 사람들의 이름
	//배열로 관리
	//공연이 만들어진 이후에 수용가능한 좌석 수에 맞춰서 관리가 되어야하므로, 동적할당
	
	//동적할당했던 rList를 스마트포인터로 변경하기
	//shared_ptr<string[]> rList = nullptr;
	unique_ptr<string[]> rList = nullptr;
	//unique_ptr은 대입연산 불가

public:
	Concert() = delete; //디폴트 생성자 삭제
	Concert(const string& name, const int& capacity = 10);//생성자
	//capacity가 주어지지 않으면 자동으로 10자리 확보
	Concert(const Concert& concert);//복사 생성자
	//변경시키지 않을 경우 const붙이기
	Concert(Concert&& concert) noexcept;//이동 생성자
	//r-value : 임시객체가 오면 이동 생성자 호출, noexcept한정자
	~Concert();//소멸자
	void reservation();//예약자 이름 입력받는 예약함수

	//const함수 : 위의 name, capacity, num, rList의 값을 변경x
	bool full() const;//만석 여부
	int getCapacity() const;//좌석수 반환
	int getNum();//현재 예약자수 반환
	void show() const;//공연정보 출력
};

