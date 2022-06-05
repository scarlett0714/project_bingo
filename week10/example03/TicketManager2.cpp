#include "AdvancedTicket.h"
#include "GeneralTicket.h"
#include "TicketManager2.h"
#include <iostream>
using namespace std;

TicketManager2::~TicketManager2()
{
	/*if (ticket != nullptr) {
		for (size_t i = 0; i < count; i++) {
			delete ticket[i];
		}
		delete[] ticket;
		ticket = nullptr;
	}*/

}

TicketManager2::TicketManager2(const string& name, const int number)
	:m_name(name), totalNumber(number),
	//ticket(new Ticket* [totalNumber])
	ticket(make_unique<unique_ptr<Ticket>[]>(totalNumber))
{

}

void TicketManager2::buy(Ticket* t)
{
	if (count < totalNumber) {
		ticket[count++] = unique_ptr<Ticket>(t);
		return;
	}
	//totalNumber��ŭ �ǸŵǾ ���̻� �ǸŸ� �� �� ���µ�
	//�����Ҵ��ؼ� Ticket�� ������� ���, �޸� ���� �߻�
	delete t;
}

void TicketManager2::buy(unique_ptr<Ticket> t)
{
	if (count < totalNumber) {
		ticket[count++] = move(t);
	}
}

void TicketManager2::show() const
{
	double totalprice = 0;
	cout << "-------Ƽ�� ���� ��Ȳ-------" << endl << endl;
	cout << "�� ���� �ż� : " << count << endl;
	cout << "----------------------------" << endl;
	for (int i = 0; i < count; i++) {
		ticket[i]->show();
		totalprice += ticket[i]->getPrice();
	}
	cout << "----------------------------" << endl;
	cout << "�� ���� �ݾ� : " << totalprice << endl;
	cout << "----------------------------" << endl;
}


void TicketManager2::showGeneralTicket(const bool& card)
{
	double totalprice = 0;
	cout << "-------�Ϲ� ���� ��Ȳ-------" << endl << endl;
	cout << "ī����� ���� : " << card << endl;
	cout << "----------------------------" << endl;
	for (size_t i = 0; i < count; i++) {
		GeneralTicket* t = dynamic_cast<GeneralTicket*>(ticket[i].get()); //ticket[i] : Ticket* -> GeneralTicket*�� �ٿ�ĳ����
		if (t != nullptr) {
			if (t->getPayByCredit() == card) {
				ticket[i]->show();
				totalprice += ticket[i]->getPrice();
			}
		}
	}

	cout << "----------------------------" << endl;
	cout << "�� ���� �ݾ� : " << totalprice << endl;
	cout << "----------------------------" << endl;
}

void TicketManager2::showAdvancedTicket()
{
	double totalprice = 0;
	cout << "-------���� ���� ��Ȳ-------" << endl << endl;

	for (size_t i = 0; i < count; i++) {
		AdvancedTicket* t = dynamic_cast<AdvancedTicket*>(ticket[i].get()); //ticket[i] : Ticket* -> AdvancedTicket*�� �ٿ�ĳ����
		if (t != nullptr) {

			ticket[i]->show(); //t[i]->show();�� ����
			totalprice += ticket[i]->getPrice();

		}
	}

	cout << "----------------------------" << endl;
	cout << "�� ���� �ݾ� : " << totalprice << endl;
	cout << "----------------------------" << endl;
}

//���1. ���� ���� ��ü�� ������ �տ� ���� ���� ��� �������� ���� (Ŭ���� ���� ���X)
ostream& operator<<(ostream& out, const TicketManager2& manager) {
	//manager.show();

	//show()�� ���� ���
	//���2. ��ü�� ���� ������ ����� ��� : friend
	double totalprice = 0;
	cout << "-------Ƽ�� ���� ��Ȳ-------" << endl << endl;
	cout << "�� ���� �ż� : " << manager.count << endl;
	cout << "----------------------------" << endl;
	for (int i = 0; i < manager.count; i++) {
		manager.ticket[i]->show();
		totalprice += manager.ticket[i]->getPrice();
	}
	cout << "----------------------------" << endl;
	cout << "�� ���� �ݾ� : " << totalprice << endl;
	cout << "----------------------------" << endl;

	//���3. friend����ϱ� ���� ��� : get�Լ� ����ؼ� �� �ϳ��� �޾ƿ���


	return out;
}

