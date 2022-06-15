#pragma once
#include "Product.h"
class Clothing : public Product
{
public:
	string gender;
	string name;
	string size;

	Clothing() = default;
	Clothing(const string & id, const string & type, const int& cnt, const int& price, const string & gender, const string & name, const string& size);

	~Clothing() = default;

	void join(const string& customer);

	string show() const;


};

