#include <iostream>
#include <string>
using namespace std;


void func() {
	string* str = new string("Hello");
	str->append(" World");
	cout << *str << endl;
}

void func2() {
	auto str = make_unique<string>("Hello");
	str->append(" World");
	cout << *str << endl;
}

void delete_int(int* ptr) {
	cout << "포인터 삭제" << endl;
	delete ptr;
}

void delete_arr(int* ptr) {
	cout << "배열 삭제" << endl;
	delete[] ptr;
}

void func3(string* str) {
	cout << *str << endl;
}

int main() {
	//메모리 누수체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//int* pnum1 = new int; : 일반 포인터변수
	//unique_ptr<int> pnum1(new int);
	//auto pnum1 = make_unique<int>();

	//내가 만든 delete기능을 사용하고 싶은 경우
	//unique_ptr<int, decltype(&delete_int)> pnum1(new int, &delete_int); //&delete_int의 주소값을 넣어주기, decltype으로 선언
	//{}로 블럭처리해주면 {~}까지만 변수가 살아있음
		
	unique_ptr<int> pnum1 = make_unique<int>(); // 기본 delete기능
	* pnum1 = 100; //사용은 일반 포인터와 same
	cout << *pnum1 << endl;

	//unique_ptr<int> pnum1_copy = pnum1; (x) unique_ptr이 가리키는 객체를 다른 포인터로 가리킬 수 없음
	//강제로 가르키는 방법 move() : pnum1객체를 임시객체로 만듦(가르키던 포인터를 pnum1_copy로 이동시키고 pnum1은 nullptr로)
	unique_ptr<int> pnum1_copy = move(pnum1);
	if (pnum1 == nullptr) {
		cout << "null ptr" << endl;
	}
	else {
		cout << *pnum1 << endl;
	}

	//배열 생성
	//생성자를 통해서 내가 만든 delete기능 사용가능
	//unique_ptr<int[], decltype(&delete_arr)> pnum1(new int[5], &delete_arr);
	unique_ptr<int[]> pnum2 = make_unique<int[]>(5);
	pnum2[0] = 100;
	cout << pnum2[0] << endl;

	//2차원 배열 동적 할당
	//층 만들기
	//int** pnum3 = new int*[5];
	//unique_ptr<unique_ptr<int[]>[]> pnum3 = make_unique<unique_ptr<int[]>[]>(5);
	auto pnum3 = make_unique<unique_ptr<int[]>[]>(5);

	//방 만들기
	/*for (int i = 0; i < 5; i++) {
		pnum3[i] = new int[3];
	}*/

	for (int i = 0; i < 5; i++) {
		pnum3[i] = make_unique<int[]>(3);
	}
	pnum3[0][0] = 100;
	cout << pnum3[0][0] << endl;

	//문자열 동적할당
	//string* pstr = new string("Hello");
	auto pstr = make_unique<string>("Hello");
	cout << *pstr << endl;
	func3(pstr.get()); //pstr은 unique_ptr타입이라 func3에 넣을 때는 string*로 넣어줘야함 : get()사용

	//pstr.reset(); //pstr = nullptr
	pstr.reset(new string("world")); //새로운 값 할당
	cout << *pstr << endl;

	string* str = pstr.release(); //자신의 포인터 반환, pstr = nullptr
	delete str; //str은 일반 포인터니까 delete필요
	str = nullptr;

	func(); //메모리 누수o
	func2(); //메모리 누수x
}