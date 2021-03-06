#include <iostream>
#include <string>
using namespace std;

int** makeArray() {
	int row, col;
	cout << "생성하고자 하는 행과 열을 입력하세요 : ";
	cin >> row >> col;
	int* (*arr) = new int* [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new int[col];
	}
	return arr;
}

void initArray(int** (&arr)) {
	//stack에 있는 메모리의 경우 : sizeof로 크기 알 수 있음
	//heap에 있는 메모리의 경우 : _msize
	size_t row = _msize(arr) / sizeof(arr[0]); //전체 바이트수 / 한 방의 바이트 수 = 층의 개수
	size_t col = _msize(arr[0]) / sizeof(arr[0][0]);

	//연속된 데이터를 배열에 넣은 뒤, 섞는 방식 사용 (중복 제거)
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