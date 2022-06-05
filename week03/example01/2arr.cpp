#include <iostream>
#include <string>
using namespace std;

int main() {

	//정적할당
	int arr[3][4];
	/*cout << typeid(arr).name() << endl; //typeid(변수) : 변수의 type정보, name() : 이름정보 반환
	cout << typeid(arr[0]).name() << endl; //배열의 층 이름
	cout << typeid(arr[0][0]).name() << endl; //배열의 방 이름 */

	//int* parr = arr; //(x) parr은 int타입에 대한 포인터, arr은 int[3][4]
	int(*parr)[3][4] = &arr; //arr : int[3][4] (x) 
	int(*parr1)[4] = arr; //arr == &arr[0] == &int[4]

	//동적할당 (1차원)
	int col1;
	cin >> col1;
	int* parr2 = new int[col1];
	delete[] parr2;
	parr2 = nullptr;

	//동적할당 (2차원)
	int row, col;
	cin >> row >> col;
	//int (*parr3)[col] = new int[row][col]; //(x) 좌측변수는 반드시 타입이 고정되어있어야함 (col 동적할당x)
	int(*parr3)[4] = new int[row][4]; //(o)

	//동적할당 (2차원 : 행, 열 모두 동적할당)
	int* (*parr4) = new int* [row]; //층 생성
	for (int i = 0; i < row; i++) {
		parr4[i] = new int[col]; //방 생성
	} //사용은 그냥 정적 2차원배열처럼 사용

	for (int i = 0; i < row; i++) { //배열 삭제 : 생성과는 반대순서로 (col->row)
		delete[] parr4[i];
	} delete[] parr4;
	parr4 = nullptr;

	return 0;
}