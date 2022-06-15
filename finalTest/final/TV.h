#pragma once
#include "Product.h"
class TV : public Product
{
public:
	string company;
	string model;
	int size;

	TV() = default;
	TV(const string& id, const string& type, const int& cnt, const int& price, const string& company, const string& model, const int& size);

	~TV() = default;

	void join(const string& customer);

	string show() const;

};

