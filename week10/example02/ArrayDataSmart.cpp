#include "ArrayDataSmart.h"
#include <iostream>
using namespace std;

ArrayDataSmart::ArrayDataSmart()
	:ArrayDataSmart(3)
{
}

ArrayDataSmart::ArrayDataSmart(ArrayDataSmart& arr)
	:ArrayData(arr), usedB(arr.usedB), backdata(make_unique<double[]>(arr.capacity))
{
	cout << "ArrayDataSmart 복사생성자" << endl;
	for (size_t i = 0; i < usedB; i++) {
		backdata[i] = arr.backdata[i];
	}
}

ArrayDataSmart::ArrayDataSmart(ArrayDataSmart&& arr) noexcept
	:ArrayData(move(arr)), usedB(arr.usedB), backdata(move(arr.backdata))
{
	cout << "ArrayDataSmart 이동생성자" << endl;
	for (size_t i = 0; i < usedB; i++) {
		backdata[i] = arr.backdata[i];
	}
}

ArrayDataSmart::ArrayDataSmart(const int& capacity, const int& used)
	:ArrayData(capacity, used), usedB(0), backdata(make_unique<double[]>(capacity))
{
	cout << "ArrayDataSmart 생성자" << endl;
}

ArrayDataSmart::~ArrayDataSmart()
{
	cout << "ArrayDataSmart 소멸자" << endl;
}

void ArrayDataSmart::backup()
{
	if (backdata != nullptr) {
		usedB = used;
		for (size_t i = 0; i < usedB; i++) {
			backdata[i] = data[i];
		}
	}
}

void ArrayDataSmart::restore()
{
	if (backdata != nullptr) {
		used = usedB;
		for (size_t i = 0; i < used; i++) {
			data[i] = backdata[i];
		}
	}
}

ArrayDataSmart& ArrayDataSmart::operator=(const ArrayDataSmart& rhs)
{
	cout << "ArrayDataSmart 대입연산자" << endl;
	if (this == &rhs) { //자기가 그대로 들어옴
		return *this;
	}

	//다르면, 부모의 멤버에게 넘김
	ArrayData::operator=(rhs); //부모의 scope지정

	//내 멤버에게 넘김
	usedB = rhs.usedB;
	backdata = make_unique<double[]>(rhs.capacity);
	for (size_t i = 0; i < usedB; i++) {
		backdata[i] = rhs.backdata[i];
	}
	return *this;
}

ArrayDataSmart& ArrayDataSmart::operator=(ArrayDataSmart&& rhs) noexcept
{
	cout << "ArrayDataSmart 이동대입연산자" << endl;
	
	if (this == &rhs) { //자기가 그대로 들어옴
		return *this;
	}

	//다르면, 부모의 멤버에게 넘김
	ArrayData::operator=(move(rhs)); //부모의 scope지정

	//내 멤버에게 넘김
	usedB = rhs.usedB;
	backdata = move(rhs.backdata); //얕은 대입이므로 방:방 대입 필요없음
	
	return *this;
}


