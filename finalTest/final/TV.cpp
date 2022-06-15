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
    ss << "��Ϲ�ȣ : " << id << endl;
    ss << "��ǰ���� : " << type << endl;
    ss << "��ǰ���� : " << cnt << endl;
    ss << "���� : " << price << endl;
    ss << "-----------------------" << endl;
    ss << "����ȸ�� : " << company << endl;
    ss << "��ǰ�� : " << model << endl;
    ss << "ȭ��ũ�� : " << size << endl;
    ss << "-----------------------" << endl;
    ss << "���� ������" << endl;
    ss << "-----------------------" << endl;
    //���� ���
    for (auto it = this->customer.begin(); it != this->customer.end(); ++it) {
        ss << *it << endl;
    }
    ss << "-----------------------" << endl;
    return ss.str();

}


