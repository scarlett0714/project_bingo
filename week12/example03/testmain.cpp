#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "CMyPoint.h"
using namespace std;

template<typename T>
void printArr(list<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " "; //*it : iterator�� ���� ��
	}
	cout << endl;
}

int main() {
	//����Ʈ
	list<int> list1({ 1,2,3,3,3,4,5 });
	list1.unique();
	printArr(list1);

	//����� ���� Ÿ��
	//list������ ���� ���ٸ� ���� : �ε��� �̿��ؼ� �迭ó�� ���X
	list<CMyPoint> list2;
	list2.push_back(CMyPoint(10, 10));
	list2.emplace_back(20, 20);
	list2.emplace_back(20, 20);
	list2.emplace_back(20, 20);
	list2.push_front(CMyPoint(30, 30));
	list2.unique(); //�׳� ����� ��� error�߻� : operator ������
	printArr(list2);

	//list �̾���̱�
	list<CMyPoint> list3;
	list2.push_back(CMyPoint(40, 40));
	list2.push_back(CMyPoint(50, 50));
	list2.splice(list2.end(), list3); //list3�� �����
	cout << list3.size() << endl;
	printArr(list2);

	//�ǽ�
	list<string> std1({ "greenjoa1", "greenjoa2" , "greenjoa3" });
	list<string> std2({ "bluejoa1", "bluejoa2" });
	list<string> std3({ "redjoa1" });

	vector<list<string>> std;
	std.push_back(std1);
	std.push_back(std2);
	std.push_back(std3);

	vector<string> stdname;
	for (auto s : std) {
		for (auto t : s) {
			stdname.push_back(t);
		}
	}
	//printArr(stdname);
}