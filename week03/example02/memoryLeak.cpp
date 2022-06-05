#include <iostream>
#include <string>
using namespace std;

//메모리 누수 체크 매크로
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int* makeArray(const int SIZE) {
	int* temp = new int[SIZE];
	for (int i = 0; i < SIZE; i++) {
		temp[i] = rand() % 10;
	}
	return temp;
}

void printArray(int* (&arr), const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리 누수 체크 플래그

	int* arr = makeArray(10);
	printArray(arr, 10);

	delete[] arr;
	arr = nullptr;

	return 0;
}