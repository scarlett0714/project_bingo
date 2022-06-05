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
        //m_number의 크기만큼 item방 생성
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
        items[m_count++] = move(item); //unique_ptr은 대입연산x
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
    cout << "고객이름 : " << m_name << endl;
    cout << "구매개수 : " << m_count << endl;
    int price = 0;
    for (size_t i = 0; i < m_count; i++) {
        items[i]->show();
        price += items[i]->getPrice();
    }
    cout << "총 구매 금액 : " << price << endl;
    //getPrice()가 virtual이 아니면 TV할인가와 야채가격이 제대로 계산X -> virtual 키워드 사용
}

void Customer::showTVlist() const
{

    for (size_t i = 0; i < m_count; i++) {

        //items[]에 있던 건 Product* 타입 -> TV*로 다운캐스팅
        TV* tv = dynamic_cast<TV*>(items[i].get()); //unique_ptr로 선언되어있으므로 get()사용
        if (tv != nullptr) { //Vegetable이면 nullptr
            items[i]->show();
        }
        
    }
    
}

void Customer::showVegetablelist() const
{
    for (size_t i = 0; i < m_count; i++) {

        //items[]에 있던 건 Product* 타입 -> TV*로 다운캐스팅
        Vegetable* vegetable = dynamic_cast<Vegetable*>(items[i].get()); //unique_ptr로 선언되어있으므로 get()사용
        if (vegetable != nullptr) { //Vegetable이면 nullptr
            items[i]->show();
        }

    }
}
