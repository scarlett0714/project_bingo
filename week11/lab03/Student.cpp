#pragma once
#include "Student.h"
using namespace std;

Student::Student() : Student("Noinfo", 0) {

}
Student::~Student() {

}
Student::Student(const string& name, const int& score)
	: name(name), score(score)
{

}
string Student::getName() const {
	return name;
}
int Student::getScore() const {
	return score;
}

bool Student::operator==(const Student& pt)
{
	return pt.name == name && pt.score == score;
}

bool Student::operator==(const string& pt)
{
	return name == pt;
}

ostream& operator<<(ostream& out, Student& ptr)
{
	out << ptr.name << " " << ptr.score;
	return out;
}
