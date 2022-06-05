#pragma once
#include "Ticket.h"
class GeneralTicket : public Ticket
{
private:
    bool payByCredit;
public:
    GeneralTicket();
    GeneralTicket(double price, bool payByCredit);

    ~GeneralTicket();

    double getPrice() const;
    bool getPayByCredit() const;
    void show() const;
};

