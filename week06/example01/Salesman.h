#pragma once
#include <string>
using std::string;
class Salesman
{
private:
	string m_name;
	double m_sales;

	//������ Salesman�� ������� �˰���� �� : count
	//int count = 0;���� �����ϸ� ��ü�� ������ ������ count�� 0���� ������
	//static���� ���� (static inline�� ��� : Ŭ�������ο��� �ʱ�ȭ ����)
	//������Ʈ�� �Ӽ�->���� �Ӽ�->�Ϲ�->C++���ǥ��->C++17�� ���� : static inline���
	static inline int count = 0;

	//static inline�� ������� �ʴ� ��� : .cpp�� �������� �ʱ�ȭ
	//static int count;

public:
	Salesman();

	//���� ������ ����
	Salesman(const Salesman& man);
	//������ ���� ���� ������ ���� ���� ���
	//explicit Salesman(const Salesman& man);

	Salesman(const char* name);
	explicit Salesman(const string& name);
	Salesman(const string& name, const double& sales);
	~Salesman();
	void setName(const string& name);

	//inlineŰ���� ���̵� Ŭ���� ���ο� �����ϸ� �ڵ�inline
	string getName() {
		return this->m_name;
	}
	string getName() const{ //const�� �����ε��� ���
		return this->m_name;
	}

	void readInput();
	string getSalesmanInfo();
	void setSales(const int& sales);
	double getSales();

	//friend
	friend void show(const Salesman& s);

	//static�Լ� : private�� static����� count�� �����ϱ� ����
	static int getCount() {
		//this���x : ��ü�� �����ؾ��ؼ�
		return count;
	}

	//���۷������� callByValue : ���� ������ ȣ��
	void showFriend(Salesman s); //Salesman s = s4;�� ����
};



