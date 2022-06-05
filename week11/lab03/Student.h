#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string name;
	int score;
public:
	Student();
	~Student();
	Student(const string& name, const int& score);
	string getName() const;
	int getScore() const;

	friend ostream& operator<<(ostream& out, Student& ptr);
	bool operator==(const Student& pt);
	bool operator==(const string& pt);

};

