#include <iostream>
#include "DocWriter.h"
#include "HTMLWriter.h"
using namespace std;
//void showFileContent(DocWriter& doc) {
//	doc.readFile();
//}

//const
void showFileContent(const DocWriter& doc) {
	doc.readFile();
}

int main() {
	DocWriter doc1;
	doc1.setFileName("test1.txt");
	doc1.setContent("greenjoa");
	doc1.write();

	DocWriter doc2("test2.txt", "bluejoa");
	doc2.write();

	HTMLWriter html1("index.html", "greenjoa");
	html1.setFont("����ü", 20, "blue");
	html1.write();

	DocWriter doc3("test.txt", "greenjoa");
	doc3 << "��" << 2 << "Ŀ��" << 1;
	doc3.write();

	//�θ��� write �������̵� �� ���
	HTMLWriter html2("test.html", "greenjoa");
	html2 << "��" << 2 << "Ŀ��" << 1;
	html2.write();


	
	DocWriter doc4("doctest.txt", "greenjoa");
	HTMLWriter html3("htmltest.html", "konkuk");

	doc4.write();
	html3.write();

	//doc4.readFile();
	//html3.readFile();

	showFileContent(doc1); //���� DocWriter��ü�ϱ� &�� ���� �� ����
	showFileContent(html3); //DocWriter�� �θ�Ŭ�����ϱ� �ڽ��� HTMLWriter ���۷����� ���� �� ����
	//DocWriter& doc = html;
	
	//����
	//html3 = doc4; : �ڽ� = �θ� (x)
	//doc4 = html3; //�θ� = �ڽ� (o)
	//doc4.write(); //DocWriter�� write()ȣ��

	//������
	//DocWriter* doc5 = &html3;
	//doc5->write(); //DocWriter�� write()ȣ��

	//���۷���
	//DocWriter& doc6 = html3;
	//doc6.write(); //DocWriter�� write()ȣ��

	


}