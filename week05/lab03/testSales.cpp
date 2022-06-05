#include <iostream>
#include "SalesReport.h"
using namespace std;
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "202110547 È²À±¼±" << endl;
	SalesReport team1(3);
	team1.addMember();
	team1.addMember();
	team1.addMember();
	team1.addMember();

	team1.computeStats();
	cout << team1.getBestClerk().getSalesmanInfo() << endl;


	return 0;
}