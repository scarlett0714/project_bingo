#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <map>
using namespace std;

int main() {
	ifstream dicfile("word.txt");
	map<string, string> dic;

	try {
		//���1. if������ ����ó��
		//if (!dicfile.fail()) { : ������ ���������� �ε��ߴٸ�,

		//���2. exceptions�� ����ó��
		dicfile.exceptions(ifstream::failbit);
			while (!dicfile.eof()) { //eof() : ���ϳ����� �� ����
				string eng, kor;
				getline(dicfile, eng);
				getline(dicfile, kor);
				dic.insert({ eng, kor });
			}

			auto it = dic.find("consider");
			if (it != dic.end()) { //iterator�� ���� ó������ ���������� ���鼭 find("consider")
				cout << it->first << " : " << it->second << endl;
			}
			else {
				cout << "�ܾ� ����" << endl;
			}
		//}
		//else {
		//	//cerr << "������ �������� ����" << endl;
		//	throw exception("������ �������� ����");
		//}
	}
	catch (exception e) {
		cerr << e.what() << endl; //error�޼��� ���
		
		//� error���� Ȯ�ΰ���
		cerr << dicfile.fail() << endl; 
		cerr << dicfile.good() << endl;
		cerr << dicfile.bad() << endl;
		cerr << dicfile.eof() << endl;

	}

	//cin ����ó��
	int a;
	
	//���2. exceptions�� ����ó��
	cin.exceptions(ifstream::failbit);
	while (true) {
		try {
			cin >> a;
			//���1. if������ ����ó��
			/*if (cin.fail()) {
				throw exception("�߸��� �� �Է�");
			}*/
			cout << a << endl;
		}
		catch (exception e) {
			cerr << e.what() << endl;
			cin.clear(); //���õ� fail��Ʈ �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //���ۿ� �߸��Էµ� �� �����
			//ignore(streamsize, ������)
		}
	}
	
	
}