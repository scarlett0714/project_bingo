#include <iostream>
#include <string>
#include <fstream> //����
//txt���� �������
//�ҽ����� �߰�->��ƿ��Ƽ->txt����

using namespace std;

int main(void) {
	cout << "202110547 Ȳ����" << endl;
	ifstream fin("testdata.txt"); //���Ϸκ��� �Է��� �޴� ��ü
	if (!fin.is_open()) { //������ ���������� ������ �ʴ� ���
		cerr << "���� �б� ����\n";
		return 1;
	}

	//������ ���������� ���� ���
	string data;
	while (!fin.eof()) { //������ ������ �ʾҴٸ�
		string str;
		getline(fin, str); //fin���� 1�پ� �о�ͼ� str�� ����
		data += str + '\n';
	}
	cout << data << '\n';

	cout << "ã�� ���ڿ��� �Է��ϼ��� : ";
	string findstr; //����ڰ� �Է��� ã�� ���ڿ�
	/*������ ���� ���ڿ��� �Է¹޴� ���
	cin >> findstr; -> int /int�� ����x*/
	//������ �ִ� ���ڿ��� �Է¹޴� ���
	getline(cin, findstr);

	cout << "�ٲ� ���ڿ��� �Է��ϼ��� : ";
	string replacestr; //����ڰ� �Է��� �ٲ� ���ڿ�
	getline(cin, replacestr);

	int startpos = 0; //ó������ ã�Ƴ��� ��

	size_t pos = data.find(findstr, startpos);
	while (pos <= data.length()) {
		if (pos == string::npos) { //ã�� ���ڿ��� ���ٸ�
			cerr << "ã�� ���ڿ��� ����" << '\n';
		}
		else {
			//data.replace()�� �� ��� ��ü���� ���� : replace�����δ� ���� ��üx ��ȯo
			data = data.replace(pos, findstr.length(), replacestr); //ã�� ��ġ�� ã�� ���ڿ��� �ٲ� ���ڿ��� ��ü
			pos = data.find(findstr, pos + 1);
		}
	}
	cout << data << endl;
	return 0;
}