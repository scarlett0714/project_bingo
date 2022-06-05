#include "Customer.h"
#include "TV.h"
#include "Vegetable.h"
#include <iostream>
using namespace std;

Customer::Customer(const string& name, const int& number)
    : m_name(name), m_number(number)
    ,items(make_unique<unique_ptr<Product>[]>(m_number))
{
    /*if (m_number > 0) {
        //m_number�� ũ�⸸ŭ item�� ����
        items = new Product * [m_number];
    }
    else {
        items = nullptr;
    }*/
}

Customer::~Customer()
{
    /*if (items != nullptr) {
        for (size_t i = 0; i < m_count; i++) {
            delete items[i];
        }
        delete[] items;
    }*/
}

void Customer::buy(unique_ptr<Product> item)
{
    if (m_count < m_number) {
        //items[m_count++] = item;
        items[m_count++] = move(item); //unique_ptr�� ���Կ���x
    }
}

string Customer::getName() const
{
    return m_name;
}

int Customer::getCount() const
{
    return m_count;
}

void Customer::showlist() const
{
    cout << "���̸� : " << m_name << endl;
    cout << "���Ű��� : " << m_count << endl;
    int price = 0;
    for (size_t i = 0; i < m_count; i++) {
        items[i]->show();
        price += items[i]->getPrice();
    }
    cout << "�� ���� �ݾ� : " << price << endl;
    //getPrice()�� virtual�� �ƴϸ� TV���ΰ��� ��ä������ ����� ���X -> virtual Ű���� ���
}

void Customer::showTVlist() const
{

    for (size_t i = 0; i < m_count; i++) {

        //items[]�� �ִ� �� Product* Ÿ�� -> TV*�� �ٿ�ĳ����
        TV* tv = dynamic_cast<TV*>(items[i].get()); //unique_ptr�� ����Ǿ������Ƿ� get()���
        if (tv != nullptr) { //Vegetable�̸� nullptr
            items[i]->show();
        }
        
    }
    
}

void Customer::showVegetablelist() const
{
    for (size_t i = 0; i < m_count; i++) {

        //items[]�� �ִ� �� Product* Ÿ�� -> TV*�� �ٿ�ĳ����
        Vegetable* vegetable = dynamic_cast<Vegetable*>(items[i].get()); //unique_ptr�� ����Ǿ������Ƿ� get()���
        if (vegetable != nullptr) { //Vegetable�̸� nullptr
            items[i]->show();
        }

    }
}
