#pragma once
#include "Ticket.h"
class AdvancedTicket : public Ticket
{
private:
    int advanceDays;
public:
    AdvancedTicket();
    AdvancedTicket(double price, int days);
    ~AdvancedTicket();

    double getPrice() const;
    int getAdvanceDays() const;
    void show() const;
};

