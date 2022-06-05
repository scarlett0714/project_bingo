#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
	string name;
	cout << "이름을 입력하세요 : ";
	cin >> name;
	// 입력 : 황윤선
	// 출력 : 황윤선
	// 입력 : 황 윤 선
	// 출력 : 황 : 공백문자를 기준으로 읽어 뒷 문자 삭제
	cout << "당신의 이름은 " << name << "입니다.\n";

	// Q : 윗 코드를 지우지 않고 실행시키면 문자열을 입력받지 않고 "이름은 ~ 입니다."가 출력됨

	string name1;
	cout << "이름을 입력하세요 : ";
	getline(cin, name1);
	cout << "이름은 " << name1 << "입니다.";

	return 0;
}