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
	cout << "등록번호 : " << product->id << endl;
	cout << "제품유형 : " << product->type << endl;
	cout << "제품개수 : " << product->cnt << endl;
	cout << "가격 : " << product->price << endl;
	cout << "---------------------------" << endl;

	if (dynamic_cast<TV*>(product) != nullptr) {
		TV* t = dynamic_cast<TV*>(product);
		cout << "제조회사 : " << t->company << endl;
		cout << "제품모델 : " << t->model << endl;
		cout << "화면크기 : " << t->size << endl;

	}
	else if (dynamic_cast<Clothing*>(product) != nullptr) {
		Clothing* c = dynamic_cast<Clothing*>(product);
		cout << "성별유형 : " << c->gender << endl;
		cout << "옷 이름 : " << c->name << endl;
		cout << "옷사이즈 : " << c->size << endl;
	}
	cout << "---------------------------" << endl;
	cout << "구매 참여자" << endl;
	cout << "---------------------------" << endl;
	for (auto it = product->customer.begin(); it != product->customer.end(); it++) {
		cout << *it << endl;
	}
	cout << "---------------------------" << endl;*/

	return out;
}


