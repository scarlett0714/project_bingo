#include <iostream>
#include <string>
using namespace std;

int main() {

	//�����Ҵ�
	int arr[3][4];
	/*cout << typeid(arr).name() << endl; //typeid(����) : ������ type����, name() : �̸����� ��ȯ
	cout << typeid(arr[0]).name() << endl; //�迭�� �� �̸�
	cout << typeid(arr[0][0]).name() << endl; //�迭�� �� �̸� */

	//int* parr = arr; //(x) parr�� intŸ�Կ� ���� ������, arr�� int[3][4]
	int(*parr)[3][4] = &arr; //arr : int[3][4] (x) 
	int(*parr1)[4] = arr; //arr == &arr[0] == &int[4]

	//�����Ҵ� (1����)
	int col1;
	cin >> col1;
	int* parr2 = new int[col1];
	delete[] parr2;
	parr2 = nullptr;

	//�����Ҵ� (2����)
	int row, col;
	cin >> row >> col;
	//int (*parr3)[col] = new int[row][col]; //(x) ���������� �ݵ�� Ÿ���� �����Ǿ��־���� (col �����Ҵ�x)
	int(*parr3)[4] = new int[row][4]; //(o)

	//�����Ҵ� (2���� : ��, �� ��� �����Ҵ�)
	int* (*parr4) = new int* [row]; //�� ����
	for (int i = 0; i < row; i++) {
		parr4[i] = new int[col]; //�� ����
	} //����� �׳� ���� 2�����迭ó�� ���

	for (int i = 0; i < row; i++) { //�迭 ���� : �������� �ݴ������ (col->row)
		delete[] parr4[i];
	} delete[] parr4;
	parr4 = nullptr;

	return 0;
}