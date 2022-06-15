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
    ss << "��Ϲ�ȣ : " << id << endl;
    ss << "��ǰ���� : " << type << endl;
    ss << "��ǰ���� : " << cnt << endl;
    ss << "���� : " << price << endl;
    ss << "-----------------------" << endl;
    ss << "�������� : " << gender << endl;
    ss << "��  �̸� : " << name << endl;
    ss << "�ʻ����� : " << size << endl;
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
