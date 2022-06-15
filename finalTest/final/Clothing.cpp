#include "Clothing.h"

Clothing::Clothing(const string& id, const string& type, const int& cnt, const int& price, const string& gender, const string& name, const string& size)
	: Product(id, type, cnt, price), gender(gender), name(name), size(size)
{
}

void Clothing::join(const string& customer)
{
	this->customer.push_back(customer);
}

string Clothing::show() const
{
    stringstream ss;
    ss << "-----------------------" << endl;
    ss << "등록번호 : " << id << endl;
    ss << "제품유형 : " << type << endl;
    ss << "제품개수 : " << cnt << endl;
    ss << "가격 : " << price << endl;
    ss << "-----------------------" << endl;
    ss << "성별유형 : " << gender << endl;
    ss << "옷  이름 : " << name << endl;
    ss << "옷사이즈 : " << size << endl;
    ss << "-----------------------" << endl;
    ss << "구매 참여자" << endl;
    ss << "-----------------------" << endl;
    //벡터 출력
    for (auto it = this->customer.begin(); it != this->customer.end(); ++it) {
        ss << *it << endl;
    }
    ss << "-----------------------" << endl;
    return ss.str();
}
