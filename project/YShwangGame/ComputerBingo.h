#pragma once

#include <memory>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class ComputerBingo
{
	int bingoSize;
	unique_ptr<unique_ptr<int[]>[]> cBingo; //���� �� ������
	//status (0:default / 1:check)
	unique_ptr<unique_ptr<int[]>[]> cStatus; //���� ���¸� ��Ÿ���� ������

	ComputerBingo(const int bingoSize); //������

	int find(); //computer�� �¸��� ���� ���ڸ� �θ��� �ش���ڸ� ��ȯ
	void find(int num); //user�� �θ� ���ڸ� ������ ã��
	bool check(); //���ڸ� �θ� ������ ������ Ȯ�� (true: bingo / false: bingoX)

	vector<int> cSave; //��ǻ�Ͱ� �θ� ���� ����

};

