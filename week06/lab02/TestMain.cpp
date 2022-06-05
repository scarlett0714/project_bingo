#include <iostream>
#include "ArrayData.h"
#include <vector> //���� �迭
using namespace std;

//void showArr(const ArrayData& arr1) { //(ArrayData& arr1) : l-value�� r-value���� �Ұ�
//	//const�� ���̸� r-value ���� ����
//	cout << __FUNCTION__ << "(&)" << endl; //�Լ��̸� ȣ��
//	arr1.showData();
//}

void showArr(ArrayData& arr1) { //(ArrayData& arr1) : l-value�� r-value���� �Ұ�
	//const�� ���̸� r-value ���� ����
	cout << __FUNCTION__ << "(&)" << endl; //�Լ��̸� ȣ��
	arr1.showData();
}

void showArr(ArrayData&& arr1) { //(ArrayData& arr1) : l-value�� r-value���� �Ұ�
	//const�� ���̸� r-value ���� ����
	cout << __FUNCTION__ << "(&&)" << endl; //�Լ��̸� ȣ��
	arr1.showData();
}

ArrayData getArr(const int& num) {
	ArrayData arr(num); //������-1
	return arr;
}

int main() {
	cout << "202110547 Ȳ����" << endl;
	//r-value
	showArr(getArr(10)); //�ӽð�ü : ������-2, ���� ������

	//vector
	vector<ArrayData> vec;
	for (size_t i = 0; i < 4; i++) {
		cout << "iteration" << i << endl;
		vec.push_back(ArrayData(5)); //data�� �ϳ� �����ǰ� ����
		//vector�� �⺻������ �����͸� �����ؼ� ����
		cout << endl;
	}
	//������ü�� ��� �����ؼ� ���ο� ������ �߰�
	//P : ���� ��ü ������ ��� ȣ�� : -_-
	//S : �̵�������

	ArrayData arr1 = getArr(10);
	arr1.addElement(5.5);
	arr1.addElement(2.5);

	arr1.showData();
}