//판매된 티켓을 한바구니에 담기

#pragma once
#include <string>
#include <iostream>
#include "Ticket.h"
using std::ostream;
using std::string;

class TicketManager
{
private:
	string m_name; //공연이름
	int totalNumber; //좌석수
	//공연
	Ticket** ticket = nullptr;
	int count = 0; //실제 판매된 좌석수
public:
	TicketManager() = delete;
	~TicketManager();
	TicketManager(const string& name, const int number);
	
	//testMain에서 다양한 티켓의 종류가 들어옴
	//->티켓종류별로 but를 모두 만들어야 하나? NO!
	void buy(Ticket* t); //메소드 오버로딩필요없이 부모이름 하나로 모두 처리가능
	void show() const;
	void showGeneralTicket(const bool& card);
	void showAdvancedTicket();

	friend ostream& operator<<(ostream& out, const TicketManager& manager);
};




