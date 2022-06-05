#pragma once
#include "ComputerBingo.h"
#include "UserBingo.h"
class YShwangGame
{
public:
	int bingoSize;
	ComputerBingo computer;
	UserBingo user;


	YShwangGame() = default; //생성자
	~YShwangGame(); //소멸자

	void play(); //play
	void menu(); //menu

	void newGame(); //menu1 : 새 게임
	void show(); //현재 빙고 진행상황 출력

	void input(); //빙고 숫자 입력받기
	void replay(); //승패 결정 후 게임 진행 과정 자동으로 리플레이
	
};

