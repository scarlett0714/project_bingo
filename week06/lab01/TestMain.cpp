#include <iostream>
#include "ArrayData.h"
using namespace std;

//void showArr(ArrayData arr1) { //복사 생성자 호출
//	arr1.showData();
//}

void showArr(ArrayData& arr1) { //복사 생성자 호출x
	arr1.showData();
}

ArrayData getArr(const int& num) {
	/*ArrayData arr(num);
	return arr;*/
	return ArrayData(num); //복사 생성자 호출x by 컴파일러의 최적화 작업
}

int main(){
	cout << "202110547 황윤선" << endl;

	ArrayData data1; //디폴트는 방 3개짜리 배열 생성
	data1.addElement(5.5);
	data1.addElement(5.5);
	data1.addElement(5.5);
	data1.addElement(5.5); //빈 방 없음 출력
	data1.showData();

	//ArrayData* parr = new ArrayData(10);
	//parr->addElement(10.5); //포인터타입은 ->로 접근
	//parr->addElement(10.5);
	//parr->addElement(10.5);
	//parr->addElement(10.5);
	//parr->showData();
	//delete parr;  //delete[] parr; (X) 객체 1개 생성함

	cout << "==================" << endl;

	//복사 생성자 호출
	ArrayData copy1(data1);
	//ArrayData copy1 = data1;
	//copy1.showData();
	//P : runTime 오류 발생 why? 복사 생성자가 없어서 얕은 복사 수행
	//동적할당이 있는 경우 깊은 복사 수행
	//S : 복사 생성자 추가
	//위임생성자->복사생성자 : 생성자 2번 호출

	showArr(copy1);

	cout << "==================" << endl;

	//getArr함수 안에 객체 arr생성하면서 생성자 호출-1
	//copy2만들면서 생성자 호출-2, 복사 생성자 호출
	ArrayData copy2 = getArr(10);

	cout << "==================" << endl;

	ArrayData arr1(10);
	arr1.addElement(5.5);
	arr1.addElement(2.5);

	ArrayData arr2(arr1);
	arr2.addElement(3.5);

	arr1.showData();
	arr2.showData();
}