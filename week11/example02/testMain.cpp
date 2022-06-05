#include <iostream>
#include "Stack.h"
#include "CMyPoint.h"
using namespace std;

int main() {
	//default type이 있을 경우
	Stack<> stack;
	stack.push(10);
	stack.push(10);

	//타입 반드시 명시
	Stack<int> istack; //STack<int, 40> istack; : MAX값 40으로 변경
	istack.push(10);
	istack.push(20);
	istack.push(30);
	istack.push(40);
	istack.push(50);

	int item;
	while (istack.pop(item)) {
		cout << item << endl;
	}


	Stack<double> dstack;
	dstack.push(10.0);
	dstack.push(20.0);
	dstack.push(30.0);
	dstack.push(40.0);
	dstack.push(50.0);
	double ditem;
	while (dstack.pop(ditem)) {
		cout << ditem << endl;
	}

	Stack<string> sstack;
	sstack.push("greenjoa1");
	sstack.push("greenjoa2");
	sstack.push("greenjoa3");
	sstack.push("greenjoa4");
	sstack.push("greenjoa5");
	string sitem;
	while (sstack.pop(sitem)) {
		cout << sitem << endl;
	}

	Stack<long>* pStack;
	pStack = new Stack<long>;

	//사용자 정의 타입
	Stack<CMyPoint> ptstack;
	ptstack.push(CMyPoint(10, 20));
	ptstack.push(CMyPoint(10, 20));
	ptstack.push(CMyPoint(10, 20));
	CMyPoint ptitem;
	while (ptstack.pop(ptitem)) {
		cout << ptitem << endl;
	}

	//타입 앨리어스 가능
	//using Istack = Stack<int>;
	//Istack istack;
}