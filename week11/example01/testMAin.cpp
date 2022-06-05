#include <iostream>
#include "CMyPoint.h"
using namespace std;
//���ø� �Լ� �̻�� ��
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

//���ø� �Լ� ����
template<typename T>
void printArr(T* arr, size_t N) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}
}

//Ư��ȭ(����ȭ) ���ø� �Լ�
template<>
void printArr(char* arr, size_t N) {
	cout << arr << endl;
}

//���ڸ� �ޱ�
//P : ����ڰ� ������ Ÿ�Կ� ���ؼ��� �����߻�
//whu? <<�����ڰ� ����ڰ� ������ Ÿ���� �𸣱� ����
//S : <<������ ������
template<typename T, size_t N>
void showArr(T(&arr)[N]) {
	for (T i : arr) { //auto i : arr�� ����
		cout << i << endl;
	}
}

//�������� ����
//P: ����3ó�� ����ڰ� ������ Ÿ�Կ� ���ؼ��� ����Ϸ��� �����߻�
//why? ũ��� ������ <�� ����X
//S: ������ <������
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

	/*cout << "����1" << endl;
	int arr1[]{ 1,2,3,4,5 };
	double arr2[]{ 1.1,2.2,3.3,4.4,5.5,6.6 };
	string arr3[]{ "greenjoa1", "greenjoa2", "greenjoa3" };

	char arr4[]{ 'a', 'b', 0 };

	//arr1, arr2, arr3�� �迭�� �����ּ� ���
	//arr4�� �迭�� ���� ���(nullptr������) : char �迭�� Ư�����

	printArr<int>(arr1, size(arr1)); //Ÿ�Ը��
	printArr(arr2, size(arr2)); //Ÿ�Ը�� �������� : ���߰����� ���
	printArr(arr3, size(arr3));

	printArr(arr4, size(arr3));

	showArr(arr1); //�迭�� ����� �Ѱ����� �ʾƵ� ��밡��

	cout <<"==========================" << endl;
	cout << "����2 : ����ڰ� ������ Ÿ�� ���ø����" << endl;

	CMyPoint arr[]{ CMyPoint(10,20), CMyPoint(25,30), CMyPoint(15,10) };
	sortDesc(arr);
	showArr(arr);


	cout << "==========================" << endl;
	cout << "����3 : ����" << endl;

	sortDesc(arr1);
	showArr(arr1);
	
	sortDesc(arr2);
	showArr(arr2);
	
	sortDesc(arr3);
	showArr(arr3);*/

	//�ǽ�1. �迭 �����ϱ�
	cout << "202110547 Ȳ����" << endl;
	cout << "Template showArr �Լ�" << endl;

	CMyPoint arr[]{ CMyPoint(20,30), CMyPoint(10,20), CMyPoint(40,50) };
	sortAsc(arr);
	showArr(arr);


}