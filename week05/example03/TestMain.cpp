#include <iostream>
//#include "Salesman.h"
#include "SalesReport.h"
using namespace std;

int main() {

	/*//Salesman test
	Salesman greenjoa;
	greenjoa.readInput();
	cout << greenjoa.getSalesmanInfo() << endl;

	Salesman greenjoa2("greenjoa", 100.0);
	cout << greenjoa2.getSalesmanInfo() << endl;
	*/

	SalesReport team1(3);
	team1.computeStats();
	if(team1.getNumber()>0){ //팀원이 있다면
		cout << team1.getBestClerk().getSalesmanInfo() << endl;
	}
	

	return 0;
}