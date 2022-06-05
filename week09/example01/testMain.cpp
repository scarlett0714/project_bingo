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
	html1.setFont("돋움체", 20, "blue");
	html1.write();

	DocWriter doc3("test.txt", "greenjoa");
	doc3 << "빵" << 2 << "커피" << 1;
	doc3.write();

	//부모의 write 오버라이딩 후 사용
	HTMLWriter html2("test.html", "greenjoa");
	html2 << "빵" << 2 << "커피" << 1;
	html2.write();


	
	DocWriter doc4("doctest.txt", "greenjoa");
	HTMLWriter html3("htmltest.html", "konkuk");

	doc4.write();
	html3.write();

	//doc4.readFile();
	//html3.readFile();

	showFileContent(doc1); //같은 DocWriter객체니까 &로 받을 수 있음
	showFileContent(html3); //DocWriter는 부모클래스니까 자식인 HTMLWriter 레퍼런스를 받을 수 있음
	//DocWriter& doc = html;
	
	//대입
	//html3 = doc4; : 자식 = 부모 (x)
	//doc4 = html3; //부모 = 자식 (o)
	//doc4.write(); //DocWriter의 write()호출

	//포인터
	//DocWriter* doc5 = &html3;
	//doc5->write(); //DocWriter의 write()호출

	//레퍼런스
	//DocWriter& doc6 = html3;
	//doc6.write(); //DocWriter의 write()호출

	


}