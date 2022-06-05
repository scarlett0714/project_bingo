#include <iostream>
#include <string>
using namespace std;

int main() {
	//메모리 누수체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	auto pnum1 = make_shared<int>();
	*pnum1 = 100;

	shared_ptr<int> pnum1_c = pnum1;
	cout << pnum1.use_count() << endl; //2

	pnum1.reset();
	cout << *pnum1_c << endl; //100

	//
	auto pnum2 = make_shared<int>();
	*pnum2 = 100;

	//weak_ptr<int> pnum2_w = pnum2;
	weak_ptr<int> pnum2_w(pnum2);
	cout << pnum2.use_count() << endl; //1 : weak_ptr은 카운트x
	{
	//cout << *pnum2_w << endl; (x)
	auto pnum2_s = pnum2_w.lock();
	if (pnum2_s) {
		cout << *pnum2_s << endl;
	}
	else {
		cout << "리소스 없음" << endl;
	}
	cout << pnum2.use_count() << endl; //2
}

	//1
	pnum2.reset();

	auto pnum3_s = pnum2_w.lock();
	if (pnum3_s) {
		cout << *pnum3_s << endl;
	}
	else {
		cout << "리소스 없음" << endl;
	}

}