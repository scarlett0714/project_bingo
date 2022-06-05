#pragma once
#include <iostream>
#include <string>
using namespace std;

class YShwangStudent
{
private:
	string m_name;
	double m_score;

public:
	YShwangStudent();
	YShwangStudent(const string& name);
	YShwangStudent(const string& name, const double& score);
	~YShwangStudent();

	string getStudentInfo();

	int getScore() {
		return m_score;
	};

};

