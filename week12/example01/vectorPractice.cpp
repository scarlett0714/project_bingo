#include <iostream>
#include <string>
#include <vector>
#include "CMyPoint.h"
using namespace std;
template<typename T>
void printArr(vector<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " "; //*it : iterator가 가진 값
	}
	cout << endl;
}

int main() {
	cout << "vector 생성" << endl;
	//vector 생성 (고정)
	vector<int> intarr1(10); //초기 vector 방 10개 생성
	cout << intarr1.size() << endl;
	cout << intarr1.capacity() << endl;

	//vector 생성 (동적)
	vector<int> intarr2;
	for (int i = 0; i < 10; i++) {
		intarr2.push_back(i);
		cout << intarr2.size() << endl; //실제 원소의 개수
		cout << intarr2.capacity() << endl; //vector 방의 개수 : 컴파일러마다 증가시키는 방의 개수는 다름
		cout << intarr2.data() << endl; //vector의 주소값
		cout << endl;
	}


	cout << endl;
	cout << "vector 데이터 삽입" << endl;
	//vector에 데이터 삽입
	vector<int> arr1({ 1,2,3,4,5 });

	vector<double> arr2;
	//arr2.insert(arr2.begin()++, 2.5); (x)
	arr2.push_back(10.5);
	arr2.push_back(10.5);
	arr2.push_back(10.5);
	//insert 사용 : 처음위치 or 이미 데이터가 있는 경우
	arr2.insert(arr2.begin(), 2.5);

	printArr(arr1);
	cout << "===================" << endl;
	printArr(arr2);

	cout << endl;
	cout << "사용자 정의 데이터타입 사용" << endl;
	CMyPoint arr[] = { CMyPoint(10,20), CMyPoint(10,20), CMyPoint(10,20) };
	
	//방법1.
	//vector<CMyPoint> arr3;
	//arr3.push_back(CMyPoint(10,20)); 사용가능

	//방법2. vector를 배열로 초기화
	vector<CMyPoint> arr3(&arr[0], &arr[2]); //arr배열의 0번방부터 2번방전까지 데이터 삽입
	//만약 arr배열의 값을 모두 넣고 싶다면? (&arr[0], &arr[3])
	printArr(arr3);


	cout << endl;
	cout << "생성자 실습" << endl;
	//생성자 실습
	vector<CMyPoint> arr4;
	for (int i = 0; i < 5; i++) {
		//r-value타입의 객체가 들어오면 이동생성자 호출
		//arr4.push_back(CMyPoint(i * 10, i * 10));
		arr4.emplace_back(i * 10, i * 10); //바로 생성해서 사용
		cout << endl << endl;
	}

	//포인터
	vector<CMyPoint*> arr5;
	arr5.push_back(new CMyPoint(10, 10));
	arr5.push_back(new CMyPoint(10, 10));
	arr5.push_back(new CMyPoint(10, 10));
	//printArr(arr5); 주소값이 출력됨
	//주소가 가리키는 값 출력
	for (auto it = arr5.begin(); it != arr5.end(); it++) {
		//new만 해주면 소멸자 호출X, why? 소멸자는 delete할 때 호출됨
		delete* it;
		cout << *it << " ";
	}

	//unique_ptr
	vector<unique_ptr<CMyPoint>> arr6;
	arr6.push_back(make_unique<CMyPoint>(10, 10));
	arr6.push_back(make_unique<CMyPoint>(10, 10));
	arr6.push_back(make_unique<CMyPoint>(10, 10));
	arr6.push_back(make_unique<CMyPoint>(10, 10));
	for (auto it = arr6.begin(); it != arr6.end(); it++) {
		cout << *it << " ";
	}
}