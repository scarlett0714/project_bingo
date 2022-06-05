#include "YShwangStudent.h"
#include <iostream>
using namespace std;

YShwangStudent::YShwangStudent()
	:YShwangStudent("NoInfo", 0.0)
{
}

YShwangStudent::YShwangStudent(const string& name)
	: YShwangStudent(name, 0.0)
{
}

YShwangStudent::YShwangStudent(const string& name, const double& score)
	: m_name(name), m_score(score)
{
}

YShwangStudent::~YShwangStudent() {

}
string YShwangStudent::getStudentInfo()
{
	return "이름 : " + m_name + ", 학점 : " + to_string(m_score);
}