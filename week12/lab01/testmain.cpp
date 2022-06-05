#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

void printArr(const list<string>& student) {
	for (auto std : student) {
		cout << std << " ";
	}
}

list<string> getStudent(const list<list<string>>& std, const list<string>& droplist) {
	//매개변수를 복사하지 않고, 레퍼런스로 받기
	//매개변수를 수정하지 않을거야 : cosnt
	
	list<string> list;
	for (auto s : std) { //auto : list<string>
		s.sort();
		list.merge(s);
		list.unique();
	}

	for (auto name : droplist) { //auto : string
		list.remove(name);
	}

	return list;
	
}

int main() {

	cout << "202110547 황윤선" << endl;
	list<list<string>> std;
	std.push_back({ "greenjoa1", "bluejoa1", "greenjoa3" });
	std.push_back({ "greenjoa1", "greenjoa3" });
	std.push_back({ "redjoa1", "greenjoa2", "bluejoa2" });
	list<string> droplist({ "greenjoa2", "bluejoa1" });

	//전체 학생 중에서 droplist에 있는 학생 제외시키기
	auto student = getStudent(std, droplist); //list<string>
	printArr(student);
}