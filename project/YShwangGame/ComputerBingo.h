#pragma once

#include <memory>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class ComputerBingo
{
	int bingoSize;
	unique_ptr<unique_ptr<int[]>[]> cBingo; //숫자 들어간 빙고판
	//status (0:default / 1:check)
	unique_ptr<unique_ptr<int[]>[]> cStatus; //게임 상태를 나타내는 빙고판

	ComputerBingo(const int bingoSize); //생성자

	int find(); //computer가 승리를 위한 숫자를 부르고 해당숫자를 반환
	void find(int num); //user가 부른 숫자를 빙고에서 찾기
	bool check(); //숫자를 부를 때마다 빙고여부 확인 (true: bingo / false: bingoX)

	vector<int> cSave; //컴퓨터가 부른 숫자 저장

};

