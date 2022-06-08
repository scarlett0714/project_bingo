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
	unique_ptr<unique_ptr<int[]>[]> map; //���� �� ������
	//status (0:default / 1:check)
	unique_ptr<unique_ptr<int[]>[]> status; //���� ���¸� ��Ÿ���� ������

	Bingo() = default;
	Bingo(int bingoSize, int menu);

	int find(); //computer�� �¸��� ���� ���ڸ� �θ��� �ش���ڸ� ��ȯ
	void find(int num, int bingo); //user�� �θ� ���ڸ� ������ ã��
	int find2(int num, int bingo); //user�� �θ� ���ڸ� ������ ã��
	bool check(int cnt); //���ڸ� �θ� ������ ������ Ȯ�� (true: bingo / false: bingoX)
	

	vector<int> save; //��ǻ�Ͱ� �θ� ���� ����
};

