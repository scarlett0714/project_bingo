#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
	string name;
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;
	// �Է� : Ȳ����
	// ��� : Ȳ����
	// �Է� : Ȳ �� ��
	// ��� : Ȳ : ���鹮�ڸ� �������� �о� �� ���� ����
	cout << "����� �̸��� " << name << "�Դϴ�.\n";

	// Q : �� �ڵ带 ������ �ʰ� �����Ű�� ���ڿ��� �Է¹��� �ʰ� "�̸��� ~ �Դϴ�."�� ��µ�

	string name1;
	cout << "�̸��� �Է��ϼ��� : ";
	getline(cin, name1);
	cout << "�̸��� " << name1 << "�Դϴ�.";

	return 0;
}