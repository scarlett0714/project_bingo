#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string name[5] = { "�Ϸ���", "�̷���", "�ﷹ��", "�緹��", "������" };
	//using���� std�������ߴٸ� -> std::string���� ���

	for (int i = 0; i < 4; i++) { //int��� size_t(=unsigned int)����ص� ����
		for (int j = i + 1; j < 5; j++) {
			if (name[i].compare(name[j]) == 1) { //compare��� <:-1/=:0/>:1
				name[i].swap(name[j]);

				/*swap�ϴ� �˰���
				string temp = name[i];
				name[i] = name[j];
				name[j] = temp;*/
			}
		}
	}

	//cout << name�� ���, ��ü �迭 ���x
	//for-each���� ��밡��
	for (string str : name) {
		cout << str << "\n";
	}


	return 0;
}