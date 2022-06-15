#pragma once
#include <string>
#include "Product.h"
using namespace std;

class Manager
{
public:
	string title;
	vector<Product*> product;

	Manager() = default;
	Manager(const string& title);
	~Manager();

	void additem(Product* p);
	vector<Product*> getItems() {
		return product;
	};

	
};

