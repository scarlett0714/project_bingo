#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle() : Rectangle(0,0,0,0){
	cout << "Rectangle ����Ʈ ������" << endl;
}
Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2) 
: m_upLeft(x1, y1), m_lowRight(x2, y2){
	cout << "Rectangle �����ִ� ������" << endl;
}
Rectangle::~Rectangle() {
	cout << "Rectangle �Ҹ���" << endl;
}
void Rectangle::drawRectangle() {
	m_upLeft.drawPoint();
	m_lowRight.drawPoint();
}