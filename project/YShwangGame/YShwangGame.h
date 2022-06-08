#pragma once
#include "Bingo.h"
#include "ComputerBingo.h"
#include "UserBingo.h"
class YShwangGame
{
public:
	int bingoSize;
	int cnt = 0; //무승부 횟수
	unique_ptr<unique_ptr<Bingo>[]> bingo = nullptr;

	YShwangGame(); //생성자
	~YShwangGame(); //소멸자

	void play(); //play
	void menu(); //menu

	void bingoLogo(); //빙고 로고 화면
	void VSLogo(); //VS 로고 화면

	void newGame(); //menu1 : 새 게임
	void makeBingo(); //menu2 : 이어하기를 위한 빙고판만들기
	void show(); //현재 빙고 진행상황 출력

	void input(); //빙고 숫자 입력받기
	void judge(); //승패 판정
	void replay(); //승패 결정 후 게임 진행 과정 자동으로 리플레이

	void save();
	void readfile(); //저장된 파일 읽어오기
	void writefile(); //파일에 출력

	
};

