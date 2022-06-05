#include <iostream>
#include "CMyPoint.h"
using namespace std;
//템플릿 함수 미사용 시
/*void printArr(int* arr, size_t N) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}
}
void printArr(double* arr, size_t N) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}
}
void printArr(string* arr, size_t N){
	for (int i = 0; i < N; i++) {
	cout << arr[i] << endl;
	}
}*/

//템플릿 함수 사용시
template<typename T>
void printArr(T* arr, size_t N) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}
}

//특수화(전문화) 템플릿 함수
template<>
void printArr(char* arr, size_t N) {
	cout << arr << endl;
}

//숫자를 받기
//P : 사용자가 정의한 타입에 대해서는 오류발생
//whu? <<연산자가 사용자가 정의한 타입을 모르기 때문
//S : <<연산자 재정의
template<typename T, size_t N>
void showArr(T(&arr)[N]) {
	for (T i : arr) { //auto i : arr도 가능
		cout << i << endl;
	}
}

//내림차순 정렬
//P: 예제3처럼 사용자가 정의한 타입에 대해서도 사용하려니 오류발생
//why? 크기비교 연산자 <가 정의X
//S: 연산자 <재정의
template<typename T, size_t N>
void sortDesc(T(&arr)[N]) {
	for (size_t i = 0; i < N - 1; i++) {
		for (size_t j = i + 1; j < N; j++) {
			if (arr[i] < arr[j]) {
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template<typename T, size_t N>
void sortAsc(T(&arr)[N]) {
	for (size_t i = 0; i < N - 1; i++) {
		for (size_t j = i + 1; j < N; j++) {
			if (arr[i] > arr[j]) {
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main() {

	/*cout << "예제1" << endl;
	int arr1[]{ 1,2,3,4,5 };
	double arr2[]{ 1.1,2.2,3.3,4.4,5.5,6.6 };
	string arr3[]{ "greenjoa1", "greenjoa2", "greenjoa3" };

	char arr4[]{ 'a', 'b', 0 };

	//arr1, arr2, arr3는 배열의 시작주소 출력
	//arr4는 배열의 원소 출력(nullptr전까지) : char 배열은 특별취급

	printArr<int>(arr1, size(arr1)); //타입명시
	printArr(arr2, size(arr2)); //타입명시 생략가능 : 유추가능한 경우
	printArr(arr3, size(arr3));

	printArr(arr4, size(arr3));

	showArr(arr1); //배열의 사이즈를 넘겨주지 않아도 사용가능

	cout <<"==========================" << endl;
	cout << "예제2 : 사용자가 정의한 타입 템플릿사용" << endl;

	CMyPoint arr[]{ CMyPoint(10,20), CMyPoint(25,30), CMyPoint(15,10) };
	sortDesc(arr);
	showArr(arr);


	cout << "==========================" << endl;
	cout << "예제3 : 정렬" << endl;

	sortDesc(arr1);
	showArr(arr1);
	
	sortDesc(arr2);
	showArr(arr2);
	
	sortDesc(arr3);
	showArr(arr3);*/

	//실습1. 배열 정렬하기
	cout << "202110547 황윤선" << endl;
	cout << "Template showArr 함수" << endl;

	CMyPoint arr[]{ CMyPoint(20,30), CMyPoint(10,20), CMyPoint(40,50) };
	sortAsc(arr);
	showArr(arr);


}