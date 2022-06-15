#pragma once
#include <string>
#include <iostream>
using std::string;
using std::ostream;

class Student
{
private:
	string sid;
	string name;
	int score;
public:
	Student() = default;
	~Student() = default;
	Student(const string& sid, const string& name, const int& score);
	friend ostream& operator<<(ostream& out, const Student& std);
	bool operator<(const Student& std) const {
		return score < std.score;
	};
	bool operator>(const Student& std) const {
		return score > std.score;
	};
	bool operator==(const Student& std) const {
		return sid == std.sid;
	};
	
};

