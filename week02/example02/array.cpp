#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string name[5] = { "일레이", "이레이", "삼레이", "사레이", "오레이" };
	//using으로 std지정안했다면 -> std::string으로 사용

	for (int i = 0; i < 4; i++) { //int대신 size_t(=unsigned int)사용해도 무방
		for (int j = i + 1; j < 5; j++) {
			if (name[i].compare(name[j]) == 1) { //compare결과 <:-1/=:0/>:1
				name[i].swap(name[j]);

				/*swap하는 알고리즘
				string temp = name[i];
				name[i] = name[j];
				name[j] = temp;*/
			}
		}
	}

	//cout << name할 경우, 전체 배열 출력x
	//for-each구문 사용가능
	for (string str : name) {
		cout << str << "\n";
	}


	return 0;
}