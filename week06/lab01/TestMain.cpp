#include <iostream>
#include "ArrayData.h"
using namespace std;

//void showArr(ArrayData arr1) { //���� ������ ȣ��
//	arr1.showData();
//}

void showArr(ArrayData& arr1) { //���� ������ ȣ��x
	arr1.showData();
}

ArrayData getArr(const int& num) {
	/*ArrayData arr(num);
	return arr;*/
	return ArrayData(num); //���� ������ ȣ��x by �����Ϸ��� ����ȭ �۾�
}

int main(){
	cout << "202110547 Ȳ����" << endl;

	ArrayData data1; //����Ʈ�� �� 3��¥�� �迭 ����
	data1.addElement(5.5);
	data1.addElement(5.5);
	data1.addElement(5.5);
	data1.addElement(5.5); //�� �� ���� ���
	data1.showData();

	//ArrayData* parr = new ArrayData(10);
	//parr->addElement(10.5); //������Ÿ���� ->�� ����
	//parr->addElement(10.5);
	//parr->addElement(10.5);
	//parr->addElement(10.5);
	//parr->showData();
	//delete parr;  //delete[] parr; (X) ��ü 1�� ������

	cout << "==================" << endl;

	//���� ������ ȣ��
	ArrayData copy1(data1);
	//ArrayData copy1 = data1;
	//copy1.showData();
	//P : runTime ���� �߻� why? ���� �����ڰ� ��� ���� ���� ����
	//�����Ҵ��� �ִ� ��� ���� ���� ����
	//S : ���� ������ �߰�
	//���ӻ�����->��������� : ������ 2�� ȣ��

	showArr(copy1);

	cout << "==================" << endl;

	//getArr�Լ� �ȿ� ��ü arr�����ϸ鼭 ������ ȣ��-1
	//copy2����鼭 ������ ȣ��-2, ���� ������ ȣ��
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