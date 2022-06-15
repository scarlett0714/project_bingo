#include <iostream>
#include <string>
#include "Product.h"
#include "TV.h"
#include "Clothing.h"
#include "Manager.h"
#include <algorithm>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif
	

bool Onepiece(Product* std) {
	Clothing* c = dynamic_cast<Clothing*>(std);
	if (c != nullptr) {
		if (c->name.find("원피스") != string::npos) {
			return true;
		}
		else {
			return false;
		}
	}

}

bool Compare(Product* pOne, Product* pTwo)
{
	return pOne->getPrice() > pTwo->getPrice();
};

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "202110547 황윤선" << endl;

	cout << "2) YShwangProduct 추상 클래스 만들기(생성자는 존재하되, 명시적으로 객체 생성 불가)" << endl;
	//Product p ("A0001", "가전제품", 3, 1000);

	cout << "3) YShwangTV 객체 생성" << endl;
	TV* tv = new TV("A0001", "가전제품", 3, 1000, "건국전자", "COM001", 62);
	

	cout << "4) YShwangClothing 객체 생성" << endl;
	Clothing* pants = new Clothing("A0001", "의류", 5, 120, "남여공용", "건국청바지", "XL");
	

	cout << "5) 구매 참여하기" << endl;
	tv->join("홍길동");
	pants->join("김길동");
	pants->join("이길동");
	pants->join("이길동");

	cout << "6) 객체 정보 출력하기" << endl;
	cout << *tv << endl;
	cout << *pants << endl;

	delete tv;
	delete pants;

	cout << "7) YShwangManager 객체 생성하기" << endl;
	Manager manager("건국나라");

	cout << "8) YShwangManager에 판매 물품 추가하기" << endl;
	manager.additem(new TV("E0001", "가전제품", 3, 2000, "건국전자", "COM001", 62));
	manager.additem(new Clothing("A0001", "의류", 5, 120, "남여공용", "건국청바지", "XL"));
	manager.additem(new TV("E0002", "가전제품", 2, 100, "대학전자", "SW001", 48));
	manager.additem(new Clothing("A0002", "의류", 2, 200, "여성용", "원피스", "XXL"));
	manager.additem(new Clothing("A0003", "의류", 3, 100, "남성용", "티셔츠", "L"));

	cout << "9) 판매되는 제품 전체 저장 정보 가져오기" << endl;
	auto items = manager.getItems();

	cout << "10) 원피스 제품 찾기" << endl;
	auto pos = find_if(items.begin(), items.end(), Onepiece);
	cout << *pos << endl;

	cout << "11) 판매제품 중 가전제품만 모두 출력하기" << endl;
	vector<Product*>::iterator it = items.begin();
	while (true) {
		it = find_if(it, items.end(), [](Product* p) {
			TV* t = dynamic_cast<TV*>(p);
			if (t != nullptr) return true;
			else return false;

			});

		if (it != items.end()) {
			cout << *it << endl;
			it++;
		}
		else {
			break;
		}
	};
		

	cout << "12) 높은 가격순으로 정렬해서 출력하기" << endl;
	sort(items.begin(), items.end(), Compare);
	for (auto it : items) {
		cout << it << endl;
	}

	return 0;
}