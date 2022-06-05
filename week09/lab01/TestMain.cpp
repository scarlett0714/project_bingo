#include <iostream>
#include "Ticket.h"
#include "GeneralTicket.h"
#include "AdvancedTicket.h"
using namespace std;

int main() {
	cout << "202110547 Ȳ����" << endl;
	Ticket ticket(1000.0);
	ticket.show();
	cout << "------------------" << endl;

	AdvancedTicket aticket(1000.0, 40);
	aticket.show();
	cout << "------------------" << endl;

	GeneralTicket gticket(2000.0, true);
	gticket.show();
	cout << "------------------" << endl;
}