// #include <iostream>
#include "gdhong.h"
#include "gdgo.h"
using std::cout;

// namespace�� ������Ͽ� ����
/* namespace gdhongNS {
	void showName() {
		cout << "ȫ�浿\n";
	}
}
namespace gdgoNS {
	void showName() {
		cout << "��浿\n";
	}
} */

// using gdhongNS::showName;

int main(void) {
	// showName(); using������ ���� �ٷ� gdhongNS�� showName���� ����
	gdhongNS::showName();
	gdgoNS::showName();

	return 0;
}