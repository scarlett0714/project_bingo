// #include <iostream>
#include "gdhong.h"
#include "gdgo.h"
using std::cout;

// namespace를 헤더파일에 정의
/* namespace gdhongNS {
	void showName() {
		cout << "홍길동\n";
	}
}
namespace gdgoNS {
	void showName() {
		cout << "고길동\n";
	}
} */

// using gdhongNS::showName;

int main(void) {
	// showName(); using구문을 통해 바로 gdhongNS의 showName으로 접근
	gdhongNS::showName();
	gdgoNS::showName();

	return 0;
}