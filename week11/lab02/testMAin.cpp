#include <iostream>
#include <string>
#include "CMyPoint.h"
#include "ArrayData.h"
using namespace std;

int main() {

	cout << "202110547 È²À±¼±" << endl;
	/*ArrayData<int> arr1;
	arr1.addElement(10);
	arr1.addElement(20);
	arr1.addElement(30);
	cout << arr1 << endl;

	ArrayData<int> arr2 = arr1;
	cout << arr2 << endl;

	ArrayData<int> arr3 = move(arr2);
	cout << arr3 << endl;

	ArrayData<string> arr4;
	arr4.addElement("greenjoa1");
	arr4.addElement("greenjoa2");
	arr4.addElement("greenjoa3");
	cout << arr4 << endl;

	ArrayData<string> arr5 = arr4;
	cout << arr5 << endl;

	ArrayData<string> arr6 = move(arr5);
	cout << arr6 << endl;*/

	ArrayData<CMyPoint> arr;
	arr.addElement(CMyPoint(10, 50));
	arr.addElement(CMyPoint(20, 60));
	cout << arr << endl;
}