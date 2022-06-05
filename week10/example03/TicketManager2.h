//�Ǹŵ� Ƽ���� �ѹٱ��Ͽ� ���

#pragma once
#include <string>
#include <iostream>
#include "Ticket.h"
#include <memory>
using std::ostream;
using std::string;
using std::unique_ptr;
using namespace std;

class TicketManager2
{
private:
	string m_name; //�����̸�
	int totalNumber; //�¼���
	//����
	//Ticket** ticket = nullptr;
	unique_ptr<unique_ptr<Ticket>[]> ticket = nullptr;
	int count = 0; //���� �Ǹŵ� �¼���
public:
	TicketManager2() = delete;
	~TicketManager2();
	TicketManager2(const string& name, const int number);

	//testMain���� �پ��� Ƽ���� ������ ����
	//->Ƽ���������� but�� ��� ������ �ϳ�? NO!
	
	//main���� new�� �Ҵ��� ���
	void buy(Ticket* t); //�޼ҵ� �����ε��ʿ���� �θ��̸� �ϳ��� ��� ó������
	//main���� make_unique�� ���� ���
	void buy(unique_ptr<Ticket> t);

	void show() const;
	void showGeneralTicket(const bool& card);
	void showAdvancedTicket();

	friend ostream& operator<<(ostream& out, const TicketManager2& manager);
};

