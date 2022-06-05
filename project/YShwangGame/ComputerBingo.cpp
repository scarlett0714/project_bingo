#include "ComputerBingo.h"
#include <iostream>
#include <algorithm>
using namespace std;

ComputerBingo::ComputerBingo(const int bingoSize) //������
: bingoSize(bingoSize) 
{
	//2���� �迭 ���� �Ҵ�
	//�� �����
	cBingo = make_unique<unique_ptr<int[]>[]>(bingoSize);

	//�� �����
	for (int i = 0; i < bingoSize; i++) {
		cBingo[i] = make_unique<int[]>(bingoSize);
	}

	//�迭 �ʱ�ȭ
	int count = 1;
	for (int i = 0; i < bingoSize; i++) {
		for (int j = 0; j < bingoSize; j++) {
			cBingo[i][j] = count++;
		}
	}
    
	//data ����
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) {
		int x1, x2, y1, y2, temp;
		x1 = rand() % bingoSize;
		x2 = rand() % bingoSize;
		y1 = rand() % bingoSize;
		y2 = rand() % bingoSize;

		if (x1 != y1 && x2 != y2) {
			temp = cBingo[x1][x2];
			cBingo[x1][x2] = cBingo[y1][y2];
			cBingo[y1][y2] = temp;
		}
	}

	//status �迭
	//2���� �迭 ���� �Ҵ�
	//�� �����
	cStatus = make_unique<unique_ptr<int[]>[]>(bingoSize);

	//�� �����
	for (int i = 0; i < bingoSize; i++) {
		cStatus[i] = make_unique<int[]>(bingoSize);
	}

	//�迭 �ʱ�ȭ
	for (int i = 0; i < bingoSize; i++) {
		for (int j = 0; j < bingoSize; j++) {
			cStatus[i][j] = 0;
		}
	}
	
}

//user.find()��
//void UserBingo::find(int num)
//{
//	for (int i = 0; i < bingoSize; i++) {
//		for (int j = 0; j < bingoSize; j++) {
//			if (uBingo[i][j] == num) {
//				if (uStatus[i][j] == 0) {
//					uStatus[i][j] = 1;
//					uSave.push_back(uBingo[i][j])
//					return;
//				}
//				else {
//					cout << "�̹� ���õ� ��ȣ�Դϴ�." << endl;
//				}
//			}
//		}
//	}
//}

int ComputerBingo::find()
{	
	vector<int> v; //sum����

	//���� ����
	for (int i = 0; i < bingoSize; i++) {
		int sum = 0;
		for (int j = 0; j < bingoSize; j++) {
			sum += cStatus[i][j];
		}

		v.push_back(sum);
	}

	//���� ����
	for (int j = 0; j < bingoSize; j++) {
		int sum = 0;
		for (int i = 0; i < bingoSize; i++) {
			sum += cStatus[i][j];
		}

		v.push_back(sum);
	}

	//�밢�� ����(�������->�����ϴ�)
	int sum = 0;
	for (int i = 0, int j = 0; i < bingoSize; i++, j++) {
		sum += cStatus[i][j];
	}
	v.push_back(sum);

	//�밢�� ����(�������->�����ϴ�)
	sum = 0;
	for (int i = 0, int j = (bingoSize - 1); i < bingoSize; i++, j--) {
		sum += cStatus[i][j];
	}
	v.push_back(sum);

	int maxIndex = max_element(v.begin(), v.end()) - v.begin();

	if (maxIndex < (v.size() - 2) / 2) { //������ ���� Ȯ�� ��
		for (int j = 0; j < bingoSize; j++) {
			if (cStatus[maxIndex][j] == 0) {
				cStatus[maxIndex][j] = 1;
				cSave.push_back(cBingo[maxIndex][j]);
				return cBingo[maxIndex][j];
			}
		}
	}
	else if (maxIndex >= (v.size() - 2) / 2 && maxIndex < v.size() - 2) { //������ ���� Ȯ�� ��
		for (int i = 0; i < bingoSize; i++) {
			if (cStatus[i][maxIndex - bingoSize] == 0) {
				cStatus[i][maxIndex - bingoSize] = 1;
				cSave.push_back(cBingo[i][maxIndex - bingoSize]);
				return cBingo[i][maxIndex - bingoSize];
			}
		}
	}
	else if (maxIndex == v.size() - 2) { //�밢�� ����(�������->�����ϴ�)
		for (int i = 0, int j = 0; i < bingoSize; i++, j++) {
			if (cStatus[i][j] == 0) {
				cStatus[i][j] = 1;
				cSave.push_back(cBingo[i][j]);
				return cBingo[i][j];
			}
		}
		
	}
	else { //�밢�� ����(�������->�����ϴ�)
		for (int i = 0, int j = (bingoSize - 1); i < bingoSize; i++, j--) {
			if (cStatus[i][j] == 0) {
				cStatus[i][j] = 1;
				cSave.push_back(cBingo[i][j]);
				return cBingo[i][j];
			}
		}
	}

}

void ComputerBingo::find(int num)
{
	for (int i = 0; i < bingoSize; i++) {
		for (int j = 0; j < bingoSize; j++) {
			if (cBingo[i][j] == num) {
				if (cStatus[i][j] == 0) {
					cStatus[i][j] = 1;
				}
				else {
					cout << "�̹� ���õ� ��ȣ�Դϴ�." << endl;
				}
			}
		}
	}
}

bool ComputerBingo::check()
{
	//���� ����
	for (int i = 0; i < bingoSize; i++) {
		int sum = 0;
		for (int j = 0; j < bingoSize; j++) {
			sum += cStatus[i][j];
		}

		if (sum == bingoSize) {
			return true;
		}
	}

	//���� ����
	for (int j = 0; j < bingoSize; j++) {
		int sum = 0;
		for (int i = 0; i < bingoSize; i++) {
			sum += cStatus[i][j];
		}

		if (sum == bingoSize) {
			return true;
		}
	}

	//�밢�� ����(�������->�����ϴ�)
	int sum = 0;
	for (int i = 0, int j = 0; i < bingoSize; i++, j++) {
		sum += cStatus[i][j];
	}
	if (sum == bingoSize) {
		return true;
	}

	//�밢�� ����(�������->�����ϴ�)
	sum = 0;
	for (int i = 0, int j = (bingoSize-1); i < bingoSize; i++, j--) {
		sum += cStatus[i][j];
	}
	if (sum == bingoSize) {
		return true;
	}

}

