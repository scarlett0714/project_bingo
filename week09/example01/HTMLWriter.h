#pragma once
#include "DocWriter.h"
class HTMLWriter : public DocWriter
{
protected:
    string fontName = "����";
    int fontSize = 15;
    string fontColor = "blue";
public:
    HTMLWriter();
    ~HTMLWriter();

    //�θ������ ���
    //HTMLWriter(const string& fileName, const string& content);
    using DocWriter::DocWriter;

    void setFont(const string& fontName, const int& fontSize, const string& fontColor);
    void write(); //�θ��� �Լ� ������

    //������ ������
    HTMLWriter& operator<<(const string& str);
    HTMLWriter& operator<<(const int& num);
};

