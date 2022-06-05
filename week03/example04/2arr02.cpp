#include <iostream>
#include <string>
using namespace std;

int** makeArray() {
	int row, col;
	cout << "�����ϰ��� �ϴ� ��� ���� �Է��ϼ��� : ";
	cin >> row >> col;
	int* (*arr) = new int* [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new int[col];
	}
	return arr;
}

void initArray(int** (&arr)) {
	//stack�� �ִ� �޸��� ��� : sizeof�� ũ�� �� �� ����
	//heap�� �ִ� �޸��� ��� : _msize
	size_t row = _msize(arr) / sizeof(arr[0]); //��ü ����Ʈ�� / �� ���� ����Ʈ �� = ���� ����
	size_t col = _msize(arr[0]) / sizeof(arr[0][0]);

	//���ӵ� �����͸� �迭�� ���� ��, ���� ��� ��� (�ߺ� ����)
	int num = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = num++;
		}
	}

	for (int i = 0; i < 100; i++) {
		int r1 = rand() % row;
		int c1 = rand() % col;

		int r2 = rand() % row;
		int c2 = rand() % col;

		if (r1 != r2 || c1 != c2) {
			int temp = arr[r1][c1];
			arr[r1][c1] = arr[r2][c2];
			arr[r2][c2] = temp;
		}
		else {
			i--;
		}
	}
}

void printArray(int** (&arr)) {
	size_t row = _msize(arr) / sizeof(arr[0]);
	size_t col = _msize(arr[0]) / sizeof(arr[0][0]);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void deleteArray(int** (&arr)) {
	size_t row = _msize(arr) / sizeof(arr[0]);
	for (int i = 0; i < row; i++) {
		delete arr[i];
	}
	delete[] arr;
	arr = nullptr;
}

int main() {
	int** arr = makeArray();
	initArray(arr);
	printArray(arr);
	deleteArray(arr);

	return 0;
}