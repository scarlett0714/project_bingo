#include <iostream>
#include "YShwangScholarship.h"
#include <string>
#include <vector> //���� �迭
using namespace std;

int main() {
	cout << "202110547 Ȳ����" << endl;
	//YShwangStudent bluejoa;
	YShwangStudent greenjoa("Ȳ����", 5.5);
	cout << greenjoa.getStudentInfo() << endl;

	YShwangScholarship scholarship1("�Ǳ����б�", 3);
	scholarship1.apply(new YShwangStudent("Ȳ����", 4.5));
}