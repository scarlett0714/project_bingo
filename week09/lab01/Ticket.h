#pragma once
class Ticket
{
protected:
	int number; //Ƽ�Ϲ�ȣ
	double price; //Ƽ�ϰ���

public:
	Ticket();
	Ticket(double price);
	~Ticket();

	int getNumber() const;
	double getPrice() const;
	void setPrice(const double& price);
	void show() const;

};

