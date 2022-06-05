#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main() {
	Point pt1;
	pt1.drawPoint();
	//Point(0,0)에 있는 위임생성자로 가서 위임생성자를 먼저 실행
	//그 후, 디폴트 생성자의 body부분 실행

	cout << "===============" << endl;

	Point pt2(100,100);
	pt2.drawPoint();

	cout << "===============" << endl;

	Point* pt = new Point();
	pt->drawPoint();
	delete pt;

	cout << "===============" << endl;

	Point pt0(100, 100);
	Point& rpt = pt0;
	rpt.setX(200);
	pt0.drawPoint();

	cout << "===============" << endl;

	//Point pt2[5];
	Point* pt3 = new Point[5];
	pt3[0].drawPoint();
	delete[] pt3;

	cout << "=======Rectangle=======" << endl;

	//Rectangle안의 Point객체가 모두 만들어져야 Rentangle생성 가능
	Rectangle rect1; //소멸은 Rectangle->Point순
	//디폴트 객체를 선언할 때는 무조건 ()생략
	rect1.drawRectangle();

	cout << "===============" << endl;

	//()표시 생략가능
	Rectangle* rect2 = new Rectangle();
	Rectangle* rect3 = new Rectangle;
	delete rect2;

	cout << "===============" << endl;

	
}