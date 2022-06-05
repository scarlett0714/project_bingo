#include "ArrayData.h"
#include <iostream>
using namespace std;
//디폴트 생성자를 이용해서 배열을 만들면 capacity : 3
ArrayData::ArrayData() :ArrayData(3)
{
}

ArrayData::ArrayData(const int& capacity, const int& used)
	: capacity(capacity), used(used)
{
	cout << "생성자" << endl;
	//data = new double[this->capacity];
	//data = make_unique<double[]>(this->capacity);
	data = shared_ptr<double[]>(new double[this->capacity]);
}

ArrayData::ArrayData(ArrayData& arr)
	:ArrayData(arr.capacity, arr.used)
{
	cout << "복사 생성자" << endl;
	//배열을 위임생성자로 할당 받고 복사 작업 진행
	for (size_t i = 0; i < used; i++) {
		data[i] = arr.data[i]; //방:방으로 복사
		//서로 다른 메모리를 가지지만, 값은 same
	}
}

ArrayData::ArrayData(ArrayData&& arr) noexcept
	:capacity(arr.capacity), used(arr.used), data(arr.data)
	//unique_ptr일 경우 : data(move(arr.data))로 초기화
{
	cout << "이동 생성자" << endl;
	arr.data = nullptr;
	//unique_ptr일 경우 : move함수에서 이미 nullptr되기 때문에 위에 코드 필요x
}

ArrayData::~ArrayData()
{
	//unique_ptr, shared_ptr사용할 경우 delete기능 필요x
	/*if (data != nullptr)
		delete[] data;
	data = nullptr;*/
}

void ArrayData::addElement(const double& num)
{
	if (!full())
		data[used++] = num;
	//used++ : 다음 방의 위치를 가리킴
	else
		cout << "빈방이 없음\n";
}

bool ArrayData::full() const
{
	return this->capacity == this->used;
}

void ArrayData::emptyArray()
{
	//배열 지우기
	//방법 1. 모든 방 초기화
	//방법 2. used를 0으로 초기화
	this->used = 0;
}

void ArrayData::showData() const
{
	for (size_t i = 0; i < used; i++)
		cout << data[i] << " ";
	cout << endl;
}
