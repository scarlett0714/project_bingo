#include "ComputerBingo.h"
#include <iostream>
#include <algorithm>
using namespace std;

ComputerBingo::ComputerBingo(const int bingoSize) //생성자
: bingoSize(bingoSize) 
{
	//2차원 배열 동적 할당
	//층 만들기
	cBingo = make_unique<unique_ptr<int[]>[]>(bingoSize);

	//방 만들기
	for (int i = 0; i < bingoSize; i++) {
		cBingo[i] = make_unique<int[]>(bingoSize);
	}

	//배열 초기화
	int count = 1;
	for (int i = 0; i < bingoSize; i++) {
		for (int j = 0; j < bingoSize; j++) {
			cBingo[i][j] = count++;
		}
	}
    
	//data 섞기
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

	//status 배열
	//2차원 배열 동적 할당
	//층 만들기
	cStatus = make_unique<unique_ptr<int[]>[]>(bingoSize);

	//방 만들기
	for (int i = 0; i < bingoSize; i++) {
		cStatus[i] = make_unique<int[]>(bingoSize);
	}

	//배열 초기화
	for (int i = 0; i < bingoSize; i++) {
		for (int j = 0; j < bingoSize; j++) {
			cStatus[i][j] = 0;
		}
	}
	
}

//user.find()용
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
//					cout << "이미 선택된 번호입니다." << endl;
//				}
//			}
//		}
//	}
//}

int ComputerBingo::find()
{	
	vector<int> v; //sum저장

	//가로 빙고
	for (int i = 0; i < bingoSize; i++) {
		int sum = 0;
		for (int j = 0; j < bingoSize; j++) {
			sum += cStatus[i][j];
		}

		v.push_back(sum);
	}

	//세로 빙고
	for (int j = 0; j < bingoSize; j++) {
		int sum = 0;
		for (int i = 0; i < bingoSize; i++) {
			sum += cStatus[i][j];
		}

		v.push_back(sum);
	}

	//대각선 빙고(좌측상단->우측하단)
	int sum = 0;
	for (int i = 0, int j = 0; i < bingoSize; i++, j++) {
		sum += cStatus[i][j];
	}
	v.push_back(sum);

	//대각선 빙고(우측상단->좌측하단)
	sum = 0;
	for (int i = 0, int j = (bingoSize - 1); i < bingoSize; i++, j--) {
		sum += cStatus[i][j];
	}
	v.push_back(sum);

	int maxIndex = max_element(v.begin(), v.end()) - v.begin();

	if (maxIndex < (v.size() - 2) / 2) { //가로줄 빙고 확률 업
		for (int j = 0; j < bingoSize; j++) {
			if (cStatus[maxIndex][j] == 0) {
				cStatus[maxIndex][j] = 1;
				cSave.push_back(cBingo[maxIndex][j]);
				return cBingo[maxIndex][j];
			}
		}
	}
	else if (maxIndex >= (v.size() - 2) / 2 && maxIndex < v.size() - 2) { //세로줄 빙고 확률 업
		for (int i = 0; i < bingoSize; i++) {
			if (cStatus[i][maxIndex - bingoSize] == 0) {
				cStatus[i][maxIndex - bingoSize] = 1;
				cSave.push_back(cBingo[i][maxIndex - bingoSize]);
				return cBingo[i][maxIndex - bingoSize];
			}
		}
	}
	else if (maxIndex == v.size() - 2) { //대각선 빙고(좌측상단->우측하단)
		for (int i = 0, int j = 0; i < bingoSize; i++, j++) {
			if (cStatus[i][j] == 0) {
				cStatus[i][j] = 1;
				cSave.push_back(cBingo[i][j]);
				return cBingo[i][j];
			}
		}
		
	}
	else { //대각선 빙고(우측상단->좌측하단)
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
					cout << "이미 선택된 번호입니다." << endl;
				}
			}
		}
	}
}

bool ComputerBingo::check()
{
	//가로 빙고
	for (int i = 0; i < bingoSize; i++) {
		int sum = 0;
		for (int j = 0; j < bingoSize; j++) {
			sum += cStatus[i][j];
		}

		if (sum == bingoSize) {
			return true;
		}
	}

	//세로 빙고
	for (int j = 0; j < bingoSize; j++) {
		int sum = 0;
		for (int i = 0; i < bingoSize; i++) {
			sum += cStatus[i][j];
		}

		if (sum == bingoSize) {
			return true;
		}
	}

	//대각선 빙고(좌측상단->우측하단)
	int sum = 0;
	for (int i = 0, int j = 0; i < bingoSize; i++, j++) {
		sum += cStatus[i][j];
	}
	if (sum == bingoSize) {
		return true;
	}

	//대각선 빙고(우측상단->좌측하단)
	sum = 0;
	for (int i = 0, int j = (bingoSize-1); i < bingoSize; i++, j--) {
		sum += cStatus[i][j];
	}
	if (sum == bingoSize) {
		return true;
	}

}

