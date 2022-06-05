//�Ǹŵ� Ƽ���� �ѹٱ��Ͽ� ���

#pragma once
#include <string>
#include <iostream>
#include "Ticket.h"
using std::ostream;
using std::string;

class TicketManager
{
private:
	string m_name; //�����̸�
	int totalNumber; //�¼���
	//����
	Ticket** ticket = nullptr;
	int count = 0; //���� �Ǹŵ� �¼���
public:
	TicketManager() = delete;
	~TicketManager();
	TicketManager(const string& name, const int number);
	
	//testMain���� �پ��� Ƽ���� ������ ����
	//->Ƽ���������� but�� ��� ������ �ϳ�? NO!
	void buy(Ticket* t); //�޼ҵ� �����ε��ʿ���� �θ��̸� �ϳ��� ��� ó������
	void show() const;
	void showGeneralTicket(const bool& card);
	void showAdvancedTicket();

	friend ostream& operator<<(ostream& out, const TicketManager& manager);
};




