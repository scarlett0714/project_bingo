#pragma once
class Ticket
{
protected:
	static inline int count = 0;
	int number; //Ƽ�Ϲ�ȣ
	double price; //Ƽ�ϰ���

public:
	Ticket() = default;
	Ticket(const double& price);
	//�θ�Ҹ��ڸ� �ڵ����� ȣ���ϹǷ�, �ڽļҸ��ڸ� ����ϱ� ���� ���������� �Ҹ��ڿ� virtual���
	virtual ~Ticket() = default;

	int getNumber() const;

	//���������Լ� : Ticket�̶�� ��ü�� ����� ����
	//Ticket t; ó�� main���� ��ü����X
	virtual double getPrice() const = 0;

	void setPrice(const double& price);
	virtual void show() const;

};

