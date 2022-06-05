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

	cout << "202110547 황윤선" << endl;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	TicketManager manager("아이유콘서트", 10);

	//TicketManager2 manager("아이유콘서트", 10);
	//manager.buy(make_unique<AdvancedTicket>(2000, 10));

	manager.buy(new AdvancedTicket(1000, 40));
	manager.buy(new AdvancedTicket(1500, 30));
	manager.buy(new AdvancedTicket(2000, 25));
	manager.buy(new AdvancedTicket(1000, 5));
	manager.buy(new GeneralTicket(2000, true));
	manager.buy(new GeneralTicket(1500, false));

	//다형성을 적용하지 않은 채, 그냥 show()하면 Ticket의 고유정보가 출력되지 않음
	//P : 바구니에 담기만 하고 다형성이 적용되지 않음
	//S : virtual
	//manager.show();

	cout << manager << endl;

	manager.showGeneralTicket(true);
	manager.showGeneralTicket(false);
	manager.showAdvancedTicket();

}
