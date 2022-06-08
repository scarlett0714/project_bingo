#pragma once
#include <string>
using std::string;

class DocWriter
{
protected:
	string fileName;
	string content;
public:
	DocWriter();
	~DocWriter();
	DocWriter(const string& fileNmae, const string& content);

	//파일 이름 지정
	void setFileName(const string& fileName);
	//저장할 텍스트 지정
	void setContent(const string& content);
	//파일에 텍스트 저장
	void write();

	//연산자 재정의
	DocWriter& operator<<(const string& str);
	DocWriter& operator<<(const int& num);

	void readFile(); //파일읽어서 출력
	void readFile() const; //파일읽어서 출력
};

