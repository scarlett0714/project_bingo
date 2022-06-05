#pragma once
class Ticket
{
protected:
	int number; //티켓번호
	double price; //티켓가격

public:
	Ticket();
	Ticket(double price);
	~Ticket();

	int getNumber() const;
	double getPrice() const;
	void setPrice(const double& price);
	void show() const;

};

