#include "Concert.h"
#include <iostream>
using namespace std;


#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__ )
#define new DBG_NEW
#endif
#endif

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cout << "=======" << endl;
	Concert concert1("아이유 콘서트", 5);
	concert1.reservation();
	concert1.reservation();
	//concert1.show();
	
	cout << "==== 복사 생성자 ====" << endl;
	Concert concert2(concert1);
	concert2.show();

	cout << "==== 이동 생성자 ====" << endl;
	Concert concert3(move(concert1));
	//move()사용 이유 : concert1은 l-value객체 -> r-value객체
	concert3.show();

	//concert1.show(); 
	//이동 생성자로 인해 아직 stack에는 남아있지만 heap영역은 delete상태


	//더블 포인터, 스마트 포인터 연습하기 (manager)
	cout << "==== 더블 포인터 ====" << endl;

	Concert** manager1 = new Concert * [5]; //Concert* 값이 들어가는 빈 방 5개 생성
	//new Concert[5]; : 디폴트 객체가 들어가 있는 방 5개

	//빈 방에 객체 생성
	manager1[0] = new Concert("A콘서트", 3);
	manager1[1] = new Concert("B콘서트", 2);
	//manager1[0]방엔 Concert객체의 주소가 들어가있으므로, ->로 접근
	manager1[0]->reservation();
	manager1[0]->show();

	//new delete : 배열이 아니라 Concert객체 생성했으므로, 그냥 객체 delete
	delete manager1[0];
	delete manager1[1]; 
	//방을 지운 후에 객체 지우기
	delete[] manager1;
	manager1 = nullptr;

	cout << "==== unique_ptr 포인터 ====" << endl;
	//Concert객체의 unique_ptr을 저장할 unique_ptr배열생성 : 포인터 배열 생성
	unique_ptr<unique_ptr<Concert>[]> manager2 = make_unique< unique_ptr<Concert>[]>(5); //방 개수 정보 추가
	//콘서트 객체 생성
	//Concert타입의 unique_ptr(포인터)를 저장
	manager2[0] = make_unique<Concert>("C콘서트", 3);
	manager2[1] = make_unique<Concert>("D콘서트", 2);
	manager2[0]->reservation();
	manager2[0]->show();
	//스마트 포인터라 delete구문 필요x

	cout << "==== shared_ptr 포인터 ====" << endl;
	//Concert객체의 shared_ptr을 저장할 shared_ptr배열생성 : 포인터 배열 생성
	//shared_ptr의 배열생성은 make_shared를 사용하지 않고 직접 생성
	shared_ptr<shared_ptr<Concert>[]> manager3(new shared_ptr<Concert>[5]); //방 개수 정보 추가
	//콘서트 객체 생성
	//Concert타입의 shared_ptr(포인터)를 저장 : 배열이 아니니 make_shared이용 가능
	manager3[0] = make_shared<Concert>("C콘서트", 3);
	manager3[1] = make_shared<Concert>("D콘서트", 2);
	manager3[0]->reservation();
	manager3[0]->show();
	//스마트 포인터라 delete구문 필요x
}