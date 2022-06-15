#include <iostream>
#include <string>
#include "Product.h"
#include "TV.h"
#include "Clothing.h"
#include "Manager.h"
#include <algorithm>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif
	

bool Onepiece(Product* std) {
	Clothing* c = dynamic_cast<Clothing*>(std);
	if (c != nullptr) {
		if (c->name.find("���ǽ�") != string::npos) {
			return true;
		}
		else {
			return false;
		}
	}

}

bool Compare(Product* pOne, Product* pTwo)
{
	return pOne->getPrice() > pTwo->getPrice();
};

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "202110547 Ȳ����" << endl;

	cout << "2) YShwangProduct �߻� Ŭ���� �����(�����ڴ� �����ϵ�, ��������� ��ü ���� �Ұ�)" << endl;
	//Product p ("A0001", "������ǰ", 3, 1000);

	cout << "3) YShwangTV ��ü ����" << endl;
	TV* tv = new TV("A0001", "������ǰ", 3, 1000, "�Ǳ�����", "COM001", 62);
	

	cout << "4) YShwangClothing ��ü ����" << endl;
	Clothing* pants = new Clothing("A0001", "�Ƿ�", 5, 120, "��������", "�Ǳ�û����", "XL");
	

	cout << "5) ���� �����ϱ�" << endl;
	tv->join("ȫ�浿");
	pants->join("��浿");
	pants->join("�̱浿");
	pants->join("�̱浿");

	cout << "6) ��ü ���� ����ϱ�" << endl;
	cout << *tv << endl;
	cout << *pants << endl;

	delete tv;
	delete pants;

	cout << "7) YShwangManager ��ü �����ϱ�" << endl;
	Manager manager("�Ǳ�����");

	cout << "8) YShwangManager�� �Ǹ� ��ǰ �߰��ϱ�" << endl;
	manager.additem(new TV("E0001", "������ǰ", 3, 2000, "�Ǳ�����", "COM001", 62));
	manager.additem(new Clothing("A0001", "�Ƿ�", 5, 120, "��������", "�Ǳ�û����", "XL"));
	manager.additem(new TV("E0002", "������ǰ", 2, 100, "��������", "SW001", 48));
	manager.additem(new Clothing("A0002", "�Ƿ�", 2, 200, "������", "���ǽ�", "XXL"));
	manager.additem(new Clothing("A0003", "�Ƿ�", 3, 100, "������", "Ƽ����", "L"));

	cout << "9) �ǸŵǴ� ��ǰ ��ü ���� ���� ��������" << endl;
	auto items = manager.getItems();

	cout << "10) ���ǽ� ��ǰ ã��" << endl;
	auto pos = find_if(items.begin(), items.end(), Onepiece);
	cout << *pos << endl;

	cout << "11) �Ǹ���ǰ �� ������ǰ�� ��� ����ϱ�" << endl;
	vector<Product*>::iterator it = items.begin();
	while (true) {
		it = find_if(it, items.end(), [](Product* p) {
			TV* t = dynamic_cast<TV*>(p);
			if (t != nullptr) return true;
			else return false;

			});

		if (it != items.end()) {
			cout << *it << endl;
			it++;
		}
		else {
			break;
		}
	};
		

	cout << "12) ���� ���ݼ����� �����ؼ� ����ϱ�" << endl;
	sort(items.begin(), items.end(), Compare);
	for (auto it : items) {
		cout << it << endl;
	}

	return 0;
}