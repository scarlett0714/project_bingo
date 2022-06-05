#include "Customer.h"
#include "TV.h"
#include "Vegetable.h"
#include <iostream>
using namespace std;

Customer::Customer(const string& name, const int& number)
    : m_name(name), m_number(number)
    //items(make_unique<unique_ptr<Product>[]>(m_number)) : ���2
    //���3. �̹� �����迭�� �����Ǿ��� ������ �迭�� ������� �ʿ�X
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
    //���3. ��밡��
    //if (m_count < m_number) {
    //    //items[m_count++] = item;
    //    items[m_count++] = move(item); //unique_ptr�� ���Կ���x
    //}

    //���3.
    items.push_back(move(item));
}

string Customer::getName() const
{
    return m_name;
}

int Customer::getCount() const
{
    //return m_count;
    return items.size();
}

void Customer::showlist() const
{
    cout << "���̸� : " << m_name << endl;
    cout << "���Ű��� : " << items.size() << endl;
    int price = 0;

    //���3.
    //for (size_t i = 0; i < items.size(); i++) {
    //   items[i]->show();
    //   price += items[i]->getPrice();
    //}

    //���3. iterator ���
    for (auto it = items.begin(); it != items.end(); it++) {
        (*it)->show();
        price += (*it)->getPrice();
    }

    cout << "�� ���� �ݾ� : " << price << endl;
    //getPrice()�� virtual�� �ƴϸ� TV���ΰ��� ��ä������ ����� ���X -> virtual Ű���� ���
}

void Customer::showTVlist() const
{

    for (size_t i = 0; i < items.size(); i++) {

        //items[]�� �ִ� �� Product* Ÿ�� -> TV*�� �ٿ�ĳ����
        TV* tv = dynamic_cast<TV*>(items[i].get()); //unique_ptr�� ����Ǿ������Ƿ� get()���
        if (tv != nullptr) { //Vegetable�̸� nullptr
            items[i]->show();
        }
        
    }
    
}

void Customer::showVegetablelist() const
{
    for (size_t i = 0; i < items.size(); i++) {

        //items[]�� �ִ� �� Product* Ÿ�� -> TV*�� �ٿ�ĳ����
        Vegetable* vegetable = dynamic_cast<Vegetable*>(items[i].get()); //unique_ptr�� ����Ǿ������Ƿ� get()���
        if (vegetable != nullptr) { //Vegetable�̸� nullptr
            items[i]->show();
        }

    }
}
