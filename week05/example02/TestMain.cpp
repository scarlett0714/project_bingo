#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main() {
	Point pt1;
	pt1.drawPoint();
	//Point(0,0)�� �ִ� ���ӻ����ڷ� ���� ���ӻ����ڸ� ���� ����
	//�� ��, ����Ʈ �������� body�κ� ����

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

	//Rectangle���� Point��ü�� ��� ��������� Rentangle���� ����
	Rectangle rect1; //�Ҹ��� Rectangle->Point��
	//����Ʈ ��ü�� ������ ���� ������ ()����
	rect1.drawRectangle();

	cout << "===============" << endl;

	//()ǥ�� ��������
	Rectangle* rect2 = new Rectangle();
	Rectangle* rect3 = new Rectangle;
	delete rect2;

	cout << "===============" << endl;

	
}