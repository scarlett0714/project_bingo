#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
	cout << "�й� : 202110547 �̸� : Ȳ����" << endl;

	string mystr;
	int sum = 0;
	cout << "Enter your data(name kor eng math) : ";
	getline(cin, mystr);

	stringstream ss;
	ss.str(mystr);

	string mydata;
	ss >> mydata;
	cout << mydata << " : ";
	while (ss >> mydata) {
		sum += stoi(mydata);
	}
	cout << sum << endl;

	return 0;
}
