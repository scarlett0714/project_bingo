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
	data = make_unique<double[]>(this->capacity);
	//data = shared_ptr<double[]>(new double[this->capacity]);
}

ArrayData::ArrayData(const ArrayData& arr)
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
	:capacity(arr.capacity), used(arr.used), data(move(arr.data))
	//unique_ptr일 경우 : data(move(arr.data))로 초기화
	//스마트 포인터가 아닐 경우 : data(arr.data)로 초기화
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

ArrayData& ArrayData::operator=(const ArrayData& rhs)
{
	//깊은 대입
	cout << "대입연산자" << endl; //a = b;의미 (a값 변경)
	//나를 나에게 대입하는 경우, 굳이 깊은 대입필요X
	if (this == &rhs)
		return *this;

	//나랑 같은 타입인데 다른 객체인 경우
	this->capacity = rhs.capacity;
	this->used = rhs.used;
	
	
	//방법1. unique_ptr, shared_ptr인 경우
	data.reset(new double[capacity]);
	
	//방법2. shared_ptr인 경우 : resource공유 -> 참조 count증가
	//data = static_cast<shared_ptr<double[]>>(new double[capacity]);
	
	//방법3. 스마트 포인터 아닌경우
	//원래 가지고 있던 data를 지워주고 새로운 방을 생성
	/*if (data != nullptr)
		delete[] data;*/
	//data = new double[capacity];

	//방:방으로 값 대입
	for (size_t i = 0; i < used; i++) {
		//방법1.
		data[i] = rhs.data[i];
		//방법2. 방법1 에러날 경우 사용
		//*(data + i) = *(rhs.data + i);
	}
	return *this;
}

ArrayData& ArrayData::operator=(ArrayData&& rhs) noexcept
{
	//얕은 대입 : rhs는 임시객체 : 사라질 객체
	cout << "이동대입연산자" << endl;
	this->capacity = rhs.capacity;
	this->used = rhs.used;

	//스마트 포인터인 경우
	//r-value data로 만들기 : move
	data = move(rhs.data); //rhs.data에 해당하는 것은 자동으로 비워짐 : nullptr로 초기화 필요X
	
	//스마트 포인터 아닌경우
	//기존에 가리키고 있던걸 지우고 수행
	/*if (data != nullptr)
		delete[] data;
	data = rhs.data;*/
	//rhs.data = nullptr; : move를 사용하면 자동으로 수행
	
	return *this;
}

//변경 가능
double& ArrayData::operator[](size_t num)
{
	if (num >= 0 && num < capacity) {
		return data[num];
	}
	else {
		cout << "배열 참조 오류" << endl;
		exit(0);
	}
}

const double& ArrayData::operator[](size_t num) const
{
	if (num >= 0 && num < used) { //num<capacity일 경우, 쓰레기값까지 모두 출력됨
		return data[num];
	}
	else {
		cout << "배열 참조 오류" << endl;
		exit(0);
	}
}

//cout -> out으로 받음
ostream& operator<<(ostream& out, const ArrayData& arr)
{
	for (size_t i = 0; i < arr.getUsed(); i++) {
		//operator<<를 전역함수로 .p에 추가한 경우
		//out << arr[i] << "\t";

		//data를 참조하고싶다면 private이므로 friend함수로 추가
		out << arr.data[i] << "\t";
	}
	out << endl;
	return out;
}
