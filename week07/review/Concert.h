#pragma once
#include <string>
#include <memory>
using std::string;
using std::shared_ptr;
using std::unique_ptr;

class Concert
{
private:
	string name;//������
	int capacity;//���밡���� �¼�
	int num = 0;//������ ��
	//string* rList = nullptr;//������ ������� �̸�
	//�迭�� ����
	//������ ������� ���Ŀ� ���밡���� �¼� ���� ���缭 ������ �Ǿ���ϹǷ�, �����Ҵ�
	
	//�����Ҵ��ߴ� rList�� ����Ʈ�����ͷ� �����ϱ�
	//shared_ptr<string[]> rList = nullptr;
	unique_ptr<string[]> rList = nullptr;
	//unique_ptr�� ���Կ��� �Ұ�

public:
	Concert() = delete; //����Ʈ ������ ����
	Concert(const string& name, const int& capacity = 10);//������
	//capacity�� �־����� ������ �ڵ����� 10�ڸ� Ȯ��
	Concert(const Concert& concert);//���� ������
	//�����Ű�� ���� ��� const���̱�
	Concert(Concert&& concert) noexcept;//�̵� ������
	//r-value : �ӽð�ü�� ���� �̵� ������ ȣ��, noexcept������
	~Concert();//�Ҹ���
	void reservation();//������ �̸� �Է¹޴� �����Լ�

	//const�Լ� : ���� name, capacity, num, rList�� ���� ����x
	bool full() const;//���� ����
	int getCapacity() const;//�¼��� ��ȯ
	int getNum();//���� �����ڼ� ��ȯ
	void show() const;//�������� ���
};

