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
	//�Ű������� �������� �ʰ�, ���۷����� �ޱ�
	//�Ű������� �������� �����ž� : cosnt
	
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

	cout << "202110547 Ȳ����" << endl;
	list<list<string>> std;
	std.push_back({ "greenjoa1", "bluejoa1", "greenjoa3" });
	std.push_back({ "greenjoa1", "greenjoa3" });
	std.push_back({ "redjoa1", "greenjoa2", "bluejoa2" });
	list<string> droplist({ "greenjoa2", "bluejoa1" });

	//��ü �л� �߿��� droplist�� �ִ� �л� ���ܽ�Ű��
	auto student = getStudent(std, droplist); //list<string>
	printArr(student);
}