#include "TicketManager.h"
#include "AdvancedTicket.h"
#include "GeneralTicket.h"
#include <iostream>
using namespace std;

TicketManager::~TicketManager()
{
	if (ticket != nullptr) {
		for (size_t i = 0; i < count; i++) {
			delete ticket[i];
		}
		delete[] ticket;
		ticket = nullptr;
	}
	
}

TicketManager::TicketManager(const string& name, const int number)
	:m_name(name), totalNumber(number), 
	ticket(new Ticket*[totalNumber])
{

}

void TicketManager::buy(Ticket* t)
{
	if (count < totalNumber) {
		ticket[count++] = t;
		return;
	}
	//totalNumber만큼 판매되어서 더이상 판매를 할 수 없는데
	//동적할당해서 Ticket이 만들어진 경우, 메모리 누수 발생
	delete t;
}

void TicketManager::show() const
{
	double totalprice = 0;
	cout << "-------티켓 예약 현황-------" << endl << endl;
	cout << "총 예약 매수 : " << count << endl;
	cout << "----------------------------" << endl;
	for (int i = 0; i < count; i++) {
		ticket[i]->show();
		totalprice += ticket[i]->getPrice();
	}
	cout << "----------------------------" << endl;
	cout << "총 예약 금액 : " << totalprice << endl;
	cout << "----------------------------" << endl;
}


void TicketManager::showGeneralTicket(const bool& card)
{
	double totalprice = 0;
	cout << "-------일반 예약 현황-------" << endl << endl;
	cout << "카드결제 여부 : " << card << endl;
	cout << "----------------------------" << endl;
	for (size_t i = 0; i < count; i++) {
		GeneralTicket* t = dynamic_cast<GeneralTicket*>(ticket[i]); //ticket[i] : Ticket* -> GeneralTicket*로 다운캐스팅
		if (t != nullptr) {
			if (t->getPayByCredit() == card) {
				ticket[i]->show();
				totalprice += ticket[i]->getPrice();
			}
		}
	}
	
	cout << "----------------------------" << endl;
	cout << "총 예약 금액 : " << totalprice << endl;
	cout << "----------------------------" << endl;
}

void TicketManager::showAdvancedTicket()
{
	double totalprice = 0;
	cout << "-------사전 예약 현황-------" << endl << endl;
	
	for (size_t i = 0; i < count; i++) {
		AdvancedTicket* t = dynamic_cast<AdvancedTicket*>(ticket[i]); //ticket[i] : Ticket* -> AdvancedTicket*로 다운캐스팅
		if (t != nullptr) {
			
			ticket[i]->show(); //t[i]->show();도 가능
			totalprice += ticket[i]->getPrice();
			
		}
	}

	cout << "----------------------------" << endl;
	cout << "총 예약 금액 : " << totalprice << endl;
	cout << "----------------------------" << endl;
}

//방법1. 내가 만든 객체가 연산자 앞에 오지 않을 경우 전역으로 선언 (클래스 내부 멤버X)
ostream& operator<<(ostream& out, const TicketManager& manager) {
	//manager.show();

	//show()가 없을 경우
	//방법2. 객체를 통한 접근이 어려울 경우 : friend
	double totalprice = 0;
	cout << "-------티켓 예약 현황-------" << endl << endl;
	cout << "총 예약 매수 : " << manager.count << endl;
	cout << "----------------------------" << endl;
	for (int i = 0; i < manager.count; i++) {
		manager.ticket[i]->show();
		totalprice += manager.ticket[i]->getPrice();
	}
	cout << "----------------------------" << endl;
	cout << "총 예약 금액 : " << totalprice << endl;
	cout << "----------------------------" << endl;

	//방법3. friend사용하기 싫을 경우 : get함수 사용해서 값 하나씩 받아오기

	
	return out;
}
