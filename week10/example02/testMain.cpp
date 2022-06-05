#include <iostream>
#include "ArrayData.h"
#include "ArrayDataSmart.h"
using namespace std;

//data 멤버들 출력 : const객체 출력
void showArr(const ArrayData& arr) {
	for (size_t i = 0; i < arr.getUsed(); i++) {
		cout << arr[i] << endl;
	}
}

int main() {

	/*ArrayData arr1(5);
	arr1.addElement(10.5);
	arr1.addElement(10.5);
	showArr(arr1);

	cout << "=============" << endl;
	ArrayData arr2;
	arr2 = arr1; //대입 연산자 호출
	for (int i = 0; i < arr2.getUsed(); i++) {
		cout << arr2[i] << endl;
	}
	cout << "=============" << endl;

	ArrayData arr3;
	arr3 = move(arr2); //r-value : 이동대입연산자 호출
	for (int i = arr3.getUsed(); i < arr3.getCapacity(); i++) {
		arr3[i] = 10.0; //arr3 : l-value -> double& ArrayData::operator[](size_t num) 호출
		arr3.setUsed();
	}

	cout << arr3 << endl;*/

	ArrayDataSmart arr1(5);
	arr1.addElement(10.1);
	arr1.addElement(10.2);
	arr1.addElement(10.3);
	arr1.addElement(10.4);
	arr1.backup();
	arr1.addElement(10.5);
	arr1.addElement(10.6);

	cout << "arr1 : " << arr1 << endl;
	cout << "------ restore ------" << endl;
	arr1.restore();
	cout << "arr1 : " << arr1 << endl;

	cout << "------ 대입 ------" << endl;
	ArrayDataSmart arr2(20);
	arr2 = arr1;
	cout << "arr2 : " << arr2 << endl;

	cout << "------ 이동 대입 ------" << endl;
	ArrayDataSmart arr3(3);
	arr3 = move(arr1);
	cout << "arr3 : " << arr3 << endl;
}