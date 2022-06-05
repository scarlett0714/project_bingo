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
    //원가에서 10%할인 : double->int
    return static_cast<int>(m_price * 0.9);
}

void TV::show() const
{
    Product::show(); //__super
    cout << "화면크기 : " << m_size << endl;
    cout << "판매가격 : " << getPrice() << endl;
    cout << "-------------------------------" << endl;
}
