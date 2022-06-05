#include <iostream>
#include "TV.h"
#include "Vegetable.h"
#include "Customer.h"

using namespace std;

int main() {

	Customer greenjoa("ȫ�浿", 5);
	greenjoa.buy(make_unique<TV>("�Ǳ�TV", 100, 20));
	greenjoa.buy(make_unique<TV>("����TV", 200, 40));
	greenjoa.buy(make_unique<Vegetable>("�ñ�ġ", 50, "����", 5));
	greenjoa.buy(make_unique<TV>("����TV", 100, 15));

	greenjoa.showTVlist();
	cout << endl;
	greenjoa.showVegetablelist();
}