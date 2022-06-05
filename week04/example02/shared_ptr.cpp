#include <iostream>
#include <string>
using namespace std;

void addNum(shared_ptr<int> pnum) {
	(*pnum)++;
	cout << pnum.use_count() << endl; //3
}

int main() {
	//�޸� ����üũ
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	auto pnum1 = make_shared<int>(); 
	*pnum1 = 100; //����� �Ϲ� �����Ϳ� same
	cout << *pnum1 << endl;

	auto pnum1_copy = pnum1;
	*pnum1_copy = 200;
	cout << *pnum1_copy << endl;
	cout << pnum1.use_count() << endl; //2
	addNum(pnum1); //3
	cout << pnum1.use_count() << endl; //2
	pnum1_copy.reset();
	cout << pnum1.use_count() << endl; //1


	//�迭 ����
	shared_ptr<int[]> pnum2(new int[5]); //make_shared ���x
	pnum2[0] = 100;
	cout << pnum2[0] << endl;

	//2���� �迭 ����
	//�� �����
	//int** pnum3 = new int*[5];
	shared_ptr<shared_ptr<int[]>[]> pnum3(new shared_ptr<int[]>[5]);

	//�� �����
	/*for (int i = 0; i < 5; i++) {
		pnum3[i] = new int[3];
	}*/

	for (int i = 0; i < 5; i++) {
		pnum3[i] = shared_ptr<int[]>(new int[3]);
	}
	pnum3[0][0] = 100;
	cout << pnum3[0][0] << endl;

}