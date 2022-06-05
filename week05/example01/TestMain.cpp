#include <iostream>
#include "Dice.h"
#include "Player.h"
#include <ctime>
using namespace std;

int main() {
	cout << "202110547 È²À±¼±" << endl;
	srand((unsigned)time(NULL)); //rand°ª ÃÊ±âÈ­

	Dice dice1, dice2;
	Player player1("ÀÏ·¹ÀÌ");
	Player player2("ÀÌ·¹ÀÌ");
	player1.setName("È«±æµ¿");
	//player2.setName("±è±æµ¿");
	
	player1.roll(dice1, dice2);
	player2.roll(dice1, dice2);
	if (player1.getTotal() > player2.getTotal()) {
		cout << player1.getName() << "´Ô ½Â¸® -> Á¡¼ö (" << player1.getTotal() << "," << player2.getTotal() << ")" << endl;
	}
	else if (player1.getTotal() < player2.getTotal()) {
		cout << player2.getName() << "´Ô ½Â¸® -> Á¡¼ö (" << player1.getTotal() << "," << player2.getTotal() << ")" << endl;
	}
	else {
		cout << "¹«½ÂºÎ -> Á¡¼ö (" << player1.getTotal() << "," << player2.getTotal() << ")" << endl;
	}

	return 0;
}