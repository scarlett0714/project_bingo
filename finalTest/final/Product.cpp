#include "Product.h"
#include "TV.h"
#include "Clothing.h"

Product::Product(const string& id, const string& type, const int& cnt, const int& price)
	:id(id), type(type), cnt(cnt), price(price)
{

}


ostream& operator<<(ostream& out, Product& product)
{
	out << product.show();
	return out;
}

ostream& operator<<(ostream& out, Product* product) {

	out << product->show();
	/*cout << "---------------------------" << endl;
	cout << "��Ϲ�ȣ : " << product->id << endl;
	cout << "��ǰ���� : " << product->type << endl;
	cout << "��ǰ���� : " << product->cnt << endl;
	cout << "���� : " << product->price << endl;
	cout << "---------------------------" << endl;

	if (dynamic_cast<TV*>(product) != nullptr) {
		TV* t = dynamic_cast<TV*>(product);
		cout << "����ȸ�� : " << t->company << endl;
		cout << "��ǰ�� : " << t->model << endl;
		cout << "ȭ��ũ�� : " << t->size << endl;

	}
	else if (dynamic_cast<Clothing*>(product) != nullptr) {
		Clothing* c = dynamic_cast<Clothing*>(product);
		cout << "�������� : " << c->gender << endl;
		cout << "�� �̸� : " << c->name << endl;
		cout << "�ʻ����� : " << c->size << endl;
	}
	cout << "---------------------------" << endl;
	cout << "���� ������" << endl;
	cout << "---------------------------" << endl;
	for (auto it = product->customer.begin(); it != product->customer.end(); it++) {
		cout << *it << endl;
	}
	cout << "---------------------------" << endl;*/

	return out;
}


