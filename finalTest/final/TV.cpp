#include "TV.h"
using namespace std;

TV::TV(const string& id, const string& type, const int& cnt, const int& price, const string& company, const string& model, const int& size)
	: Product(id, type, cnt, price), company(company), model(model), size(size)
{
}

void TV::join(const string& customer)
{
	this->customer.push_back(customer);
}


string TV::show() const
{
    stringstream ss;
    ss << "-----------------------" << endl;
    ss << "등록번호 : " << id << endl;
    ss << "제품유형 : " << type << endl;
    ss << "제품개수 : " << cnt << endl;
    ss << "가격 : " << price << endl;
    ss << "-----------------------" << endl;
    ss << "제조회사 : " << company << endl;
    ss << "제품모델 : " << model << endl;
    ss << "화면크기 : " << size << endl;
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


