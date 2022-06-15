#include "Manager.h"

Manager::Manager(const string& title)
	: title(title)
{
}

void Manager::additem(Product* p) {
	product.push_back(p);
	//delete p;
}

Manager::~Manager() 
{
	for (int i = 0; i < product.size(); i++)
	{
		Product* temp = product[i];
		delete temp;
	}
}


