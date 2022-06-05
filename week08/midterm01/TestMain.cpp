#include <iostream>
#include "YShwangScholarship.h"
#include <string>
#include <vector> //가변 배열
using namespace std;

int main() {
	cout << "202110547 황윤선" << endl;
	//YShwangStudent bluejoa;
	YShwangStudent greenjoa("황윤선", 5.5);
	cout << greenjoa.getStudentInfo() << endl;

	YShwangScholarship scholarship1("건국장학금", 3);
	scholarship1.apply(new YShwangStudent("황윤선", 4.5));
}