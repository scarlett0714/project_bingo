#pragma once
#include <memory> //스마트 포인터 사용
using namespace std;

template <typename T>
class ArrayData
	//capacity만큼 동적 할당으로 배열생성
	//그 주소값을 data가 가리킴
{
protected:
	//double* data = nullptr;
	unique_ptr<T[]> data;
	//shared_ptr<double[]> data;

	int capacity; //배열의 용량 (동적 할당)
	int used; //실제로 사용된 방의 개수
public:
	ArrayData();
	ArrayData(const int& capacity, const int& used=0);
	ArrayData(const ArrayData& arr); //복사 생성자
	ArrayData(ArrayData&& arr) noexcept; //이동 생성자 : const사용x
	~ArrayData();


	void addElement(const T& num); //값 추가
	bool full() const; //값이 꽉 차있는가?
	void emptyArray(); //배열을 비움
	void showData() const; //배열을 출력

	//반환 get : inline으로 구현
	int getCapacity() const {
		return this->capacity;
	};
	int getUsed() const {
		return this->used;
	};
	void setUsed() {
		used++;
	}

	//대입 연산자 오버로딩
	ArrayData& operator=(const ArrayData& rhs);
	ArrayData& operator=(ArrayData&& rhs) noexcept;

	//배열 연산자 오버로딩
	//1.
	T& operator[](size_t num);
	//2. const는 오버로딩 대상O
	const T& operator[](size_t num) const;

	template <typename T1>
	friend ostream& operator<<(ostream& out, const ArrayData<T1>& arr);
};

#include "ArrayDataDef.h"

