#include "HTMLWriter.h"
#include <iostream>
#include <fstream>
using namespace std;

HTMLWriter::HTMLWriter()
	:HTMLWriter("noFileName.html", "noContent")
{
}

HTMLWriter::~HTMLWriter()
{
	cout << "HTMLWriter 소멸자" << endl;
}

//HTMLWriter::HTMLWriter(const string& fileName, const string& content)
//	:DocWriter(fileName, content) //부모생성자 지정
//{
//	cout << "HTMLWriter 생성자" << endl;
//}

void HTMLWriter::setFont(const string& fontName, const int& fontSize, const string& fontColor)
{
	this->fontName = fontName;
	this->fontSize = fontSize;
	this->fontColor = fontColor;
}

void HTMLWriter::write()
{
	ofstream fout(fileName);
	fout << "<html><head><title>Greenjoa's Homepage</title></head>" << endl;
	fout << "<body>" << endl;
	fout << "<H1>###### 202110547 황윤선 ######</H1>" << endl;
	fout << "<font face='" << fontName << "' size='" << fontSize;
	fout << "' color='" << fontColor << "'>" << content << "</font>" << endl;
	//DocWriter를 상속받았으니 content사용가능(protected)
	fout << "</body></html>" << endl;
}

HTMLWriter& HTMLWriter::operator<<(const string& str)
{
	content += "<br>" + str + "<br>";
	return *this;
}

HTMLWriter& HTMLWriter::operator<<(const int& num)
{
	content += to_string(num) + "<br>";
	return *this;
}
