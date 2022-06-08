#pragma once
#include <memory>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;
class Bingo
{	
public:
	int bingoSize;
	unique_ptr<unique_ptr<int[]>[]> map; //숫자 들어간 빙고판
	//status (0:default / 1:check)
	unique_ptr<unique_ptr<int[]>[]> status; //게임 상태를 나타내는 빙고판

	Bingo() = default;
	Bingo(int bingoSize, int menu);

	int find(); //computer가 승리를 위한 숫자를 부르고 해당숫자를 반환
	void find(int num, int bingo); //user가 부른 숫자를 빙고에서 찾기
	int find2(int num, int bingo); //user가 부른 숫자를 빙고에서 찾기
	bool check(int cnt); //숫자를 부를 때마다 빙고여부 확인 (true: bingo / false: bingoX)
	

	vector<int> save; //컴퓨터가 부른 숫자 저장
};

