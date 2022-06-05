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
	void setFileName(const string& fileName);
	void setContent(const string& content);
	void write();

	//연산자 재정의
	DocWriter& operator<<(const string& str);
	DocWriter& operator<<(const int& num);

	void readFile(); //파일읽어서 출력
	void readFile() const; //파일읽어서 출력
};

