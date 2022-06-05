#include <iostream>
#include <string>
#include <vector>
#include "CMyPoint.h"
using namespace std;
template<typename T>
void printArr(vector<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " "; //*it : iterator�� ���� ��
	}
	cout << endl;
}

int main() {
	cout << "vector ����" << endl;
	//vector ���� (����)
	vector<int> intarr1(10); //�ʱ� vector �� 10�� ����
	cout << intarr1.size() << endl;
	cout << intarr1.capacity() << endl;

	//vector ���� (����)
	vector<int> intarr2;
	for (int i = 0; i < 10; i++) {
		intarr2.push_back(i);
		cout << intarr2.size() << endl; //���� ������ ����
		cout << intarr2.capacity() << endl; //vector ���� ���� : �����Ϸ����� ������Ű�� ���� ������ �ٸ�
		cout << intarr2.data() << endl; //vector�� �ּҰ�
		cout << endl;
	}


	cout << endl;
	cout << "vector ������ ����" << endl;
	//vector�� ������ ����
	vector<int> arr1({ 1,2,3,4,5 });

	vector<double> arr2;
	//arr2.insert(arr2.begin()++, 2.5); (x)
	arr2.push_back(10.5);
	arr2.push_back(10.5);
	arr2.push_back(10.5);
	//insert ��� : ó����ġ or �̹� �����Ͱ� �ִ� ���
	arr2.insert(arr2.begin(), 2.5);

	printArr(arr1);
	cout << "===================" << endl;
	printArr(arr2);

	cout << endl;
	cout << "����� ���� ������Ÿ�� ���" << endl;
	CMyPoint arr[] = { CMyPoint(10,20), CMyPoint(10,20), CMyPoint(10,20) };
	
	//���1.
	//vector<CMyPoint> arr3;
	//arr3.push_back(CMyPoint(10,20)); ��밡��

	//���2. vector�� �迭�� �ʱ�ȭ
	vector<CMyPoint> arr3(&arr[0], &arr[2]); //arr�迭�� 0������� 2���������� ������ ����
	//���� arr�迭�� ���� ��� �ְ� �ʹٸ�? (&arr[0], &arr[3])
	printArr(arr3);


	cout << endl;
	cout << "������ �ǽ�" << endl;
	//������ �ǽ�
	vector<CMyPoint> arr4;
	for (int i = 0; i < 5; i++) {
		//r-valueŸ���� ��ü�� ������ �̵������� ȣ��
		//arr4.push_back(CMyPoint(i * 10, i * 10));
		arr4.emplace_back(i * 10, i * 10); //�ٷ� �����ؼ� ���
		cout << endl << endl;
	}

	//������
	vector<CMyPoint*> arr5;
	arr5.push_back(new CMyPoint(10, 10));
	arr5.push_back(new CMyPoint(10, 10));
	arr5.push_back(new CMyPoint(10, 10));
	//printArr(arr5); �ּҰ��� ��µ�
	//�ּҰ� ����Ű�� �� ���
	for (auto it = arr5.begin(); it != arr5.end(); it++) {
		//new�� ���ָ� �Ҹ��� ȣ��X, why? �Ҹ��ڴ� delete�� �� ȣ���
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