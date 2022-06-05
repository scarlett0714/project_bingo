#include "TV.h"
#include <iostream>
using namespace std;

TV::TV(const string& name, const int& price, const int& size)
    :Product(name, price), m_size(size)
{
}


TV::~TV()
{
}

int TV::getPrice() const
{
    //�������� 10%���� : double->int
    return static_cast<int>(m_price * 0.9);
}

void TV::show() const
{
    Product::show(); //__super
    cout << "ȭ��ũ�� : " << m_size << endl;
    cout << "�ǸŰ��� : " << getPrice() << endl;
    cout << "-------------------------------" << endl;
}
