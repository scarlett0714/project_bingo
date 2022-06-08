#pragma once
#include "DocWriter.h"
class HTMLWriter : public DocWriter
{
protected:
    string fontName = "돋움";
    int fontSize = 15;
    string fontColor = "blue";
public:
    HTMLWriter();
    ~HTMLWriter();

    //부모생성자 상속
    //HTMLWriter(const string& fileName, const string& content);
    using DocWriter::DocWriter;

    void setFont(const string& fontName, const int& fontSize, const string& fontColor);
    void write(); //부모의 함수 재정의

    //연산자 재정의
    HTMLWriter& operator<<(const string& str);
    HTMLWriter& operator<<(const int& num);
};

