#include <iostream>
#include <string>
using namespace std;

//�޸� ���� üũ ��ũ��
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int* makeArray(int &num) {
	cout << "�л� �� : ";
	cin >> num;
	int* temp = new int[num];
	for (int i = 0; i < num; i++) {
		cout << i + 1 << "�� �л� ���� : ";
		cin >> temp[i];
	}
	return temp;
}

void printArray(int* (&arr), const int SIZE) {
	cout << "���� ������ : " << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void deleteArray(int* (&arr)) {
	delete[] arr;
	arr = nullptr;
}

//�����͹迭 ���� �� ����
int** sortArray(const int* std, const int num){
	int**arr = new int* [num];
	for (int i = 0; i < num; i++) {
		arr[i] = const_cast<int*>(&std[i]); //int* != const int*
	}
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			if (*arr[i] > *arr[j]) {
				int* temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	return arr;
}

void printSortedArray(int** (&arr), const int SIZE) {
	cout << "���� ������ : " << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << *arr[i] << "\t";
	}
	cout << endl;
}

void deleteSortedArray(int** (&arr)) {
	delete[] arr;
	arr = nullptr;
}

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� üũ �÷���

	int num;
	int* std = makeArray(num);
	printArray(std, num);
	int** sortedStd = sortArray(std, num);
	printSortedArray(sortedStd, num);
	deleteArray(std);
	deleteSortedArray(sortedStd);
	if (std == nullptr) {
		cout << "�޸� ���� ��" << endl;
	}

	if (std == nullptr) {
		cout << "int** �޸� ���� ��" << endl;
	}

	return 0;
}