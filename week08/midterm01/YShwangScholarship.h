#pragma once
#include <iostream>
#include <string>
#include "YShwangStudent.h"
using namespace std;

class YShwangScholarship
{
private:
	shared_ptr<YShwangStudent* []> team;
	string m_title;
	int m_number;

	double highestScore;

public:
	YShwangScholarship() = delete;
	YShwangScholarship(const string& title, const int& number);
	void apply(YShwangStudent &student);
	
};

