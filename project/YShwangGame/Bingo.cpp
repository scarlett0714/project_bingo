#include "Bingo.h"
#include <iostream>
#include <algorithm>

using namespace std;

Bingo::Bingo(int bingoSize, int menu) 
	: bingoSize(bingoSize)
{
	//2���� �迭 ���� �Ҵ�
	//�� �����
	map = make_unique<unique_ptr<int[]>[]>(bingoSize);

	//�� �����
	for (int i = 0; i < bingoSize; i++) {
		map[i] = make_unique<int[]>(bingoSize);
	}

	if (menu == 1) {
		//�迭 �ʱ�ȭ
		int count = 1;
		for (int i = 0; i < bingoSize; i++) {
			for (int j = 0; j < bingoSize; j++) {
				map[i][j] = count++;
			}
		}

		//data ���� : �����ʿ�
		
		for (int i = 0; i < 100; i++) {
			int x1, x2, y1, y2, temp;
			x1 = rand() % bingoSize;
			x2 = rand() % bingoSize;
			y1 = rand() % bingoSize;
			y2 = rand() % bingoSize;

			if (x1 != y1 && x2 != y2) {
				temp = map[x1][x2];
				map[x1][x2] = map[y1][y2];
				map[y1][y2] = temp;
			}
		}
	}
	

	//status �迭
	//2���� �迭 ���� �Ҵ�
	//�� �����
	status = make_unique<unique_ptr<int[]>[]>(bingoSize);

	//�� �����
	for (int i = 0; i < bingoSize; i++) {
		status[i] = make_unique<int[]>(bingoSize);
	}

	if (menu == 1) {
		//�迭 �ʱ�ȭ
		for (int i = 0; i < bingoSize; i++) {
			for (int j = 0; j < bingoSize; j++) {
				status[i][j] = 0;
			}
		}
	}
	
}

void Bingo::find(int num, int bingo) //user
{
	for (int i = 0; i < bingoSize; i++) {
		for (int j = 0; j < bingoSize; j++) {
			if (map[i][j] == num) {
				if (status[i][j] == 0 && bingo == 0) { //computer
					status[i][j] = 1;
				}
				else if (status[i][j] == 0 && bingo == 1) { //user
					status[i][j] = 2;
				}
			}
		}
	}
}

int Bingo::find2(int i, int j) //user
{
	if (status[i][j] == 0) {
		status[i][j] = 2;
	}

	return map[i][j];
}

int Bingo::find() //computer
{
	vector<int> v; //sum����

	//���� ����
	for (int i = 0; i < bingoSize; i++) {
		int sum = 0;
		for (int j = 0; j < bingoSize; j++) {
			sum += status[i][j];
		}

		v.push_back(sum);
	}

	//���� ����
	for (int j = 0; j < bingoSize; j++) {
		int sum = 0;
		for (int i = 0; i < bingoSize; i++) {
			sum += status[i][j];
		}

		v.push_back(sum);
	}

	//�밢�� ����(�������->�����ϴ�)
	int sum = 0;
	int i = 0; int j = 0;
	for (; i < bingoSize; i++, j++) {
		sum += status[i][j];
	}
	v.push_back(sum);

	//�밢�� ����(�������->�����ϴ�)
	sum = 0;
	i = 0; j = (bingoSize - 1);
	for (; i < bingoSize; i++, j--) {
		sum += status[i][j];
	}
	v.push_back(sum);

	
	vector<pair<int, int>> vv;
	for (int i = 0; i < v.size(); i++) {
		vv.push_back(make_pair(v[i], i));
	}

	sort(vv.begin(), vv.end(), greater<>());

	for (int i = 0; i < v.size(); i++) {
		int maxIndex = vv[i].second;

		if (maxIndex < (v.size() - 2) / 2) { //������ ���� Ȯ�� ��
			for (int j = 0; j < bingoSize; j++) {
				if (status[maxIndex][j] == 0) {
					status[maxIndex][j] = 1;
					vector<int>().swap(v);
					vector<pair<int, int>>().swap(vv);
					return map[maxIndex][j];
				}
			}
		}
		else if (maxIndex >= (v.size() - 2) / 2 && maxIndex < v.size() - 2) { //������ ���� Ȯ�� ��
			for (int i = 0; i < bingoSize; i++) {
				if (status[i][maxIndex - bingoSize] == 0) {
					status[i][maxIndex - bingoSize] = 1;
					vector<int>().swap(v);
					vector<pair<int, int>>().swap(vv);
					return map[i][maxIndex - bingoSize];
				}
			}
		}
		else if (maxIndex == v.size() - 2) { //�밢�� ����(�������->�����ϴ�)
			i = 0; j = 0;
			for (; i < bingoSize; i++, j++) {
				if (status[i][j] == 0) {
					status[i][j] = 1;
					vector<int>().swap(v);
					vector<pair<int, int>>().swap(vv);
					return map[i][j];
				}
			}

		}
		else { //�밢�� ����(�������->�����ϴ�)
			i = 0; j = (bingoSize - 1);
			for (; i < bingoSize; i++, j--) {
				if (status[i][j] == 0) {
					status[i][j] = 1;
					vector<int>().swap(v);
					vector<pair<int, int>>().swap(vv);
					return map[i][j];
				}
			}
		}
	}
}

bool Bingo::check(int cnt)
{
	
	vector<bool> v1;
	for (int i = 0; i < bingoSize * 2 + 2; i++) {
		v1.push_back(true);
	}
	
	int i = 0; int j = 0;
	//���� ����
	for (int i = 0; i < bingoSize; i++) {
		
		for (int j = 0; j < bingoSize; j++) {
			
			if (status[i][j] == 0) {
				v1[i] = false;
			}
		}
		
	}

	//���� ����
	for (int j = 0; j < bingoSize; j++) {
		
		for (int i = 0; i < bingoSize; i++) {
		
			if (status[i][j] == 0) {
				v1[j + bingoSize] = false;
			}

		}
		
	}

	//�밢�� ����(�������->�����ϴ�)
	
	i = 0; j = 0;
	for (; i < bingoSize; i++, j++) {
	
		if (status[i][j] == 0) {
			v1[bingoSize * 2] = false;
		}
	}
	

	//�밢�� ����(�������->�����ϴ�)
	
	i = 0; j = (bingoSize - 1);
	for (; i < bingoSize; i++, j--) {
		
		if (status[i][j] == 0) {
			v1[bingoSize * 2 + 1] = false;
		}
	}
	

	vector<int> ve;
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i]==true) {
			ve.push_back(v1[i]);
		}
	}

	if (ve.size() > cnt) {
		vector<int>().swap(ve);
		return true;
	}

	vector<int>().swap(ve);
	return false;
}

