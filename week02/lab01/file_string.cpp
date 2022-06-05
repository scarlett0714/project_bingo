#include <iostream>
#include <string>
#include <fstream> //파일
//txt파일 생성방법
//소스파일 추가->유틸리티->txt파일

using namespace std;

int main(void) {
	cout << "202110547 황윤선" << endl;
	ifstream fin("testdata.txt"); //파일로부터 입력을 받는 객체
	if (!fin.is_open()) { //파일이 정상적으로 열리지 않는 경우
		cerr << "파일 읽기 실패\n";
		return 1;
	}

	//파일이 정상적으로 열린 경우
	string data;
	while (!fin.eof()) { //파일이 끝나지 않았다면
		string str;
		getline(fin, str); //fin에서 1줄씩 읽어와서 str에 저장
		data += str + '\n';
	}
	cout << data << '\n';

	cout << "찾을 문자열을 입력하세요 : ";
	string findstr; //사용자가 입력할 찾을 문자열
	/*공백이 없는 문자열을 입력받는 경우
	cin >> findstr; -> int /int를 구별x*/
	//공백이 있는 문자열을 입력받는 경우
	getline(cin, findstr);

	cout << "바꿀 문자열을 입력하세요 : ";
	string replacestr; //사용자가 입력할 바꿀 문자열
	getline(cin, replacestr);

	int startpos = 0; //처음부터 찾아나갈 것

	size_t pos = data.find(findstr, startpos);
	while (pos <= data.length()) {
		if (pos == string::npos) { //찾는 문자열이 없다면
			cerr << "찾는 문자열이 없음" << '\n';
		}
		else {
			//data.replace()만 할 경우 교체되지 않음 : replace만으로는 직접 교체x 반환o
			data = data.replace(pos, findstr.length(), replacestr); //찾은 위치에 찾은 문자열을 바꿀 문자열로 교체
			pos = data.find(findstr, pos + 1);
		}
	}
	cout << data << endl;
	return 0;
}