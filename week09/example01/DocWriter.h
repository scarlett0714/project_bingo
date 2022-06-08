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

	//���� �̸� ����
	void setFileName(const string& fileName);
	//������ �ؽ�Ʈ ����
	void setContent(const string& content);
	//���Ͽ� �ؽ�Ʈ ����
	void write();

	//������ ������
	DocWriter& operator<<(const string& str);
	DocWriter& operator<<(const int& num);

	void readFile(); //�����о ���
	void readFile() const; //�����о ���
};

