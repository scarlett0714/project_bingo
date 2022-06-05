#include "Customer.h"
#include "TV.h"
#include "Vegetable.h"
#include <iostream>
using namespace std;

Customer::Customer(const string& name, const int& number)
    : m_name(name), m_number(number)
    //items(make_unique<unique_ptr<Product>[]>(m_number)) : 방법2
    //방법3. 이미 가변배열이 생성되었기 때문에 배열을 만들어줄 필요X
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
    //방법3. 사용가능
    //if (m_count < m_number) {
    //    //items[m_count++] = item;
    //    items[m_count++] = move(item); //unique_ptr은 대입연산x
    //}

    //방법3.
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
    cout << "고객이름 : " << m_name << endl;
    cout << "구매개수 : " << items.size() << endl;
    int price = 0;

    //방법3.
    //for (size_t i = 0; i < items.size(); i++) {
    //   items[i]->show();
    //   price += items[i]->getPrice();
    //}

    //방법3. iterator 사용
    for (auto it = items.begin(); it != items.end(); it++) {
        (*it)->show();
        price += (*it)->getPrice();
    }

    cout << "총 구매 금액 : " << price << endl;
    //getPrice()가 virtual이 아니면 TV할인가와 야채가격이 제대로 계산X -> virtual 키워드 사용
}

void Customer::showTVlist() const
{

    for (size_t i = 0; i < items.size(); i++) {

        //items[]에 있던 건 Product* 타입 -> TV*로 다운캐스팅
        TV* tv = dynamic_cast<TV*>(items[i].get()); //unique_ptr로 선언되어있으므로 get()사용
        if (tv != nullptr) { //Vegetable이면 nullptr
            items[i]->show();
        }
        
    }
    
}

void Customer::showVegetablelist() const
{
    for (size_t i = 0; i < items.size(); i++) {

        //items[]에 있던 건 Product* 타입 -> TV*로 다운캐스팅
        Vegetable* vegetable = dynamic_cast<Vegetable*>(items[i].get()); //unique_ptr로 선언되어있으므로 get()사용
        if (vegetable != nullptr) { //Vegetable이면 nullptr
            items[i]->show();
        }

    }
}
