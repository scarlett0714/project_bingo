#include <iostream>
#include "ArrayData.h"
#include <vector> //가변 배열
using namespace std;

//void showArr(const ArrayData& arr1) { //(ArrayData& arr1) : l-value라 r-value참조 불가
//	//const를 붙이면 r-value 참조 가능
//	cout << __FUNCTION__ << "(&)" << endl; //함수이름 호출
//	arr1.showData();
//}

void showArr(ArrayData& arr1) { //(ArrayData& arr1) : l-value라 r-value참조 불가
	//const를 붙이면 r-value 참조 가능
	cout << __FUNCTION__ << "(&)" << endl; //함수이름 호출
	arr1.showData();
}

void showArr(ArrayData&& arr1) { //(ArrayData& arr1) : l-value라 r-value참조 불가
	//const를 붙이면 r-value 참조 가능
	cout << __FUNCTION__ << "(&&)" << endl; //함수이름 호출
	arr1.showData();
}

ArrayData getArr(const int& num) {
	ArrayData arr(num); //생성자-1
	return arr;
}

int main() {
	cout << "202110547 황윤선" << endl;
	//r-value
	showArr(getArr(10)); //임시객체 : 생성자-2, 복사 생성자

	//vector
	vector<ArrayData> vec;
	for (size_t i = 0; i < 4; i++) {
		cout << "iteration" << i << endl;
		vec.push_back(ArrayData(5)); //data가 하나 생성되고 삽입
		//vector는 기본적으로 데이터를 복사해서 생성
		cout << endl;
	}
	//기존객체도 계속 복사해서 새로운 데이터 추가
	//P : 앞의 객체 생성자 계속 호출 : -_-
	//S : 이동생성자

	ArrayData arr1 = getArr(10);
	arr1.addElement(5.5);
	arr1.addElement(2.5);

	arr1.showData();
}