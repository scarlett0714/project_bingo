#include "Concert.h"
#include <iostream>
using namespace std;


#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__ )
#define new DBG_NEW
#endif
#endif

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cout << "=======" << endl;
	Concert concert1("������ �ܼ�Ʈ", 5);
	concert1.reservation();
	concert1.reservation();
	//concert1.show();
	
	cout << "==== ���� ������ ====" << endl;
	Concert concert2(concert1);
	concert2.show();

	cout << "==== �̵� ������ ====" << endl;
	Concert concert3(move(concert1));
	//move()��� ���� : concert1�� l-value��ü -> r-value��ü
	concert3.show();

	//concert1.show(); 
	//�̵� �����ڷ� ���� ���� stack���� ���������� heap������ delete����


	//���� ������, ����Ʈ ������ �����ϱ� (manager)
	cout << "==== ���� ������ ====" << endl;

	Concert** manager1 = new Concert * [5]; //Concert* ���� ���� �� �� 5�� ����
	//new Concert[5]; : ����Ʈ ��ü�� �� �ִ� �� 5��

	//�� �濡 ��ü ����
	manager1[0] = new Concert("A�ܼ�Ʈ", 3);
	manager1[1] = new Concert("B�ܼ�Ʈ", 2);
	//manager1[0]�濣 Concert��ü�� �ּҰ� �������Ƿ�, ->�� ����
	manager1[0]->reservation();
	manager1[0]->show();

	//new delete : �迭�� �ƴ϶� Concert��ü ���������Ƿ�, �׳� ��ü delete
	delete manager1[0];
	delete manager1[1]; 
	//���� ���� �Ŀ� ��ü �����
	delete[] manager1;
	manager1 = nullptr;

	cout << "==== unique_ptr ������ ====" << endl;
	//Concert��ü�� unique_ptr�� ������ unique_ptr�迭���� : ������ �迭 ����
	unique_ptr<unique_ptr<Concert>[]> manager2 = make_unique< unique_ptr<Concert>[]>(5); //�� ���� ���� �߰�
	//�ܼ�Ʈ ��ü ����
	//ConcertŸ���� unique_ptr(������)�� ����
	manager2[0] = make_unique<Concert>("C�ܼ�Ʈ", 3);
	manager2[1] = make_unique<Concert>("D�ܼ�Ʈ", 2);
	manager2[0]->reservation();
	manager2[0]->show();
	//����Ʈ �����Ͷ� delete���� �ʿ�x

	cout << "==== shared_ptr ������ ====" << endl;
	//Concert��ü�� shared_ptr�� ������ shared_ptr�迭���� : ������ �迭 ����
	//shared_ptr�� �迭������ make_shared�� ������� �ʰ� ���� ����
	shared_ptr<shared_ptr<Concert>[]> manager3(new shared_ptr<Concert>[5]); //�� ���� ���� �߰�
	//�ܼ�Ʈ ��ü ����
	//ConcertŸ���� shared_ptr(������)�� ���� : �迭�� �ƴϴ� make_shared�̿� ����
	manager3[0] = make_shared<Concert>("C�ܼ�Ʈ", 3);
	manager3[1] = make_shared<Concert>("D�ܼ�Ʈ", 2);
	manager3[0]->reservation();
	manager3[0]->show();
	//����Ʈ �����Ͷ� delete���� �ʿ�x
}