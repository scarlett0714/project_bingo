#include <iostream>
#include <string>
using namespace std;


void func() {
	string* str = new string("Hello");
	str->append(" World");
	cout << *str << endl;
}

void func2() {
	auto str = make_unique<string>("Hello");
	str->append(" World");
	cout << *str << endl;
}

void delete_int(int* ptr) {
	cout << "������ ����" << endl;
	delete ptr;
}

void delete_arr(int* ptr) {
	cout << "�迭 ����" << endl;
	delete[] ptr;
}

void func3(string* str) {
	cout << *str << endl;
}

int main() {
	//�޸� ����üũ
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//int* pnum1 = new int; : �Ϲ� �����ͺ���
	//unique_ptr<int> pnum1(new int);
	//auto pnum1 = make_unique<int>();

	//���� ���� delete����� ����ϰ� ���� ���
	//unique_ptr<int, decltype(&delete_int)> pnum1(new int, &delete_int); //&delete_int�� �ּҰ��� �־��ֱ�, decltype���� ����
	//{}�� ��ó�����ָ� {~}������ ������ �������
		
	unique_ptr<int> pnum1 = make_unique<int>(); // �⺻ delete���
	* pnum1 = 100; //����� �Ϲ� �����Ϳ� same
	cout << *pnum1 << endl;

	//unique_ptr<int> pnum1_copy = pnum1; (x) unique_ptr�� ����Ű�� ��ü�� �ٸ� �����ͷ� ����ų �� ����
	//������ ����Ű�� ��� move() : pnum1��ü�� �ӽð�ü�� ����(����Ű�� �����͸� pnum1_copy�� �̵���Ű�� pnum1�� nullptr��)
	unique_ptr<int> pnum1_copy = move(pnum1);
	if (pnum1 == nullptr) {
		cout << "null ptr" << endl;
	}
	else {
		cout << *pnum1 << endl;
	}

	//�迭 ����
	//�����ڸ� ���ؼ� ���� ���� delete��� ��밡��
	//unique_ptr<int[], decltype(&delete_arr)> pnum1(new int[5], &delete_arr);
	unique_ptr<int[]> pnum2 = make_unique<int[]>(5);
	pnum2[0] = 100;
	cout << pnum2[0] << endl;

	//2���� �迭 ���� �Ҵ�
	//�� �����
	//int** pnum3 = new int*[5];
	//unique_ptr<unique_ptr<int[]>[]> pnum3 = make_unique<unique_ptr<int[]>[]>(5);
	auto pnum3 = make_unique<unique_ptr<int[]>[]>(5);

	//�� �����
	/*for (int i = 0; i < 5; i++) {
		pnum3[i] = new int[3];
	}*/

	for (int i = 0; i < 5; i++) {
		pnum3[i] = make_unique<int[]>(3);
	}
	pnum3[0][0] = 100;
	cout << pnum3[0][0] << endl;

	//���ڿ� �����Ҵ�
	//string* pstr = new string("Hello");
	auto pstr = make_unique<string>("Hello");
	cout << *pstr << endl;
	func3(pstr.get()); //pstr�� unique_ptrŸ���̶� func3�� ���� ���� string*�� �־������ : get()���

	//pstr.reset(); //pstr = nullptr
	pstr.reset(new string("world")); //���ο� �� �Ҵ�
	cout << *pstr << endl;

	string* str = pstr.release(); //�ڽ��� ������ ��ȯ, pstr = nullptr
	delete str; //str�� �Ϲ� �����ʹϱ� delete�ʿ�
	str = nullptr;

	func(); //�޸� ����o
	func2(); //�޸� ����x
}