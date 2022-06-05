#pragma once
class Ticket
{
protected:
	static inline int count = 0;
	int number; //티켓번호
	double price; //티켓가격

public:
	Ticket() = default;
	Ticket(const double& price);
	//부모소멸자를 자동으로 호출하므로, 자식소멸자를 사용하기 위해 습관적으로 소멸자에 virtual사용
	virtual ~Ticket() = default;

	int getNumber() const;

	//순수가상함수 : Ticket이라는 객체는 만들수 없음
	//Ticket t; 처럼 main에서 객체생성X
	virtual double getPrice() const = 0;

	void setPrice(const double& price);
	virtual void show() const;

};

