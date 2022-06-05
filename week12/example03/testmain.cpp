#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "CMyPoint.h"
using namespace std;

template<typename T>
void printArr(list<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " "; //*it : iterator가 가진 값
	}
	cout << endl;
}

int main() {
	//리스트
	list<int> list1({ 1,2,3,3,3,4,5 });
	list1.unique();
	printArr(list1);

	//사용자 정의 타입
	//list구조는 순차 접근만 가능 : 인덱스 이용해서 배열처럼 사용X
	list<CMyPoint> list2;
	list2.push_back(CMyPoint(10, 10));
	list2.emplace_back(20, 20);
	list2.emplace_back(20, 20);
	list2.emplace_back(20, 20);
	list2.push_front(CMyPoint(30, 30));
	list2.unique(); //그냥 사용할 경우 error발생 : operator 재정의
	printArr(list2);

	//list 이어붙이기
	list<CMyPoint> list3;
	list2.push_back(CMyPoint(40, 40));
	list2.push_back(CMyPoint(50, 50));
	list2.splice(list2.end(), list3); //list3는 비워짐
	cout << list3.size() << endl;
	printArr(list2);

	//실습
	list<string> std1({ "greenjoa1", "greenjoa2" , "greenjoa3" });
	list<string> std2({ "bluejoa1", "bluejoa2" });
	list<string> std3({ "redjoa1" });

	vector<list<string>> std;
	std.push_back(std1);
	std.push_back(std2);
	std.push_back(std3);

	vector<string> stdname;
	for (auto s : std) {
		for (auto t : s) {
			stdname.push_back(t);
		}
	}
	//printArr(stdname);
}