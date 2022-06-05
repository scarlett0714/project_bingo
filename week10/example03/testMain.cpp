#include "GeneralTicket.h"
#include "AdvancedTicket.h"
#include "TicketManager.h"
#include "TicketManager2.h"
#include <iostream>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int main() {

	cout << "202110547 Ȳ����" << endl;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	TicketManager manager("�������ܼ�Ʈ", 10);

	//TicketManager2 manager("�������ܼ�Ʈ", 10);
	//manager.buy(make_unique<AdvancedTicket>(2000, 10));

	manager.buy(new AdvancedTicket(1000, 40));
	manager.buy(new AdvancedTicket(1500, 30));
	manager.buy(new AdvancedTicket(2000, 25));
	manager.buy(new AdvancedTicket(1000, 5));
	manager.buy(new GeneralTicket(2000, true));
	manager.buy(new GeneralTicket(1500, false));

	//�������� �������� ���� ä, �׳� show()�ϸ� Ticket�� ���������� ��µ��� ����
	//P : �ٱ��Ͽ� ��⸸ �ϰ� �������� ������� ����
	//S : virtual
	//manager.show();

	cout << manager << endl;

	manager.showGeneralTicket(true);
	manager.showGeneralTicket(false);
	manager.showAdvancedTicket();

}
