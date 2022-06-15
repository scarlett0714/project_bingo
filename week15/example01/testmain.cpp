#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <map>
using namespace std;

int main() {
	ifstream dicfile("word.txt");
	map<string, string> dic;

	try {
		//방법1. if문으로 예외처리
		//if (!dicfile.fail()) { : 파일을 정상적으로 로드했다면,

		//방법2. exceptions로 예외처리
		dicfile.exceptions(ifstream::failbit);
			while (!dicfile.eof()) { //eof() : 파일끝까지 다 읽음
				string eng, kor;
				getline(dicfile, eng);
				getline(dicfile, kor);
				dic.insert({ eng, kor });
			}

			auto it = dic.find("consider");
			if (it != dic.end()) { //iterator로 파일 처음부터 끝날때까지 돌면서 find("consider")
				cout << it->first << " : " << it->second << endl;
			}
			else {
				cout << "단어 없음" << endl;
			}
		//}
		//else {
		//	//cerr << "파일이 존재하지 않음" << endl;
		//	throw exception("파일이 존재하지 않음");
		//}
	}
	catch (exception e) {
		cerr << e.what() << endl; //error메세지 출력
		
		//어떤 error인지 확인가능
		cerr << dicfile.fail() << endl; 
		cerr << dicfile.good() << endl;
		cerr << dicfile.bad() << endl;
		cerr << dicfile.eof() << endl;

	}

	//cin 예외처리
	int a;
	
	//방법2. exceptions로 예외처리
	cin.exceptions(ifstream::failbit);
	while (true) {
		try {
			cin >> a;
			//방법1. if문으로 예외처리
			/*if (cin.fail()) {
				throw exception("잘못된 값 입력");
			}*/
			cout << a << endl;
		}
		catch (exception e) {
			cerr << e.what() << endl;
			cin.clear(); //세팅된 fail비트 지우기
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //버퍼에 잘못입력된 값 지우기
			//ignore(streamsize, 구분자)
		}
	}
	
	
}