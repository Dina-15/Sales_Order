#include "Payment.h"
#ifndef CASH_H
#define CASH_H


class Cash : public Payment
{
public:
    Cash();
    virtual ~Cash();
    void read();
    string Update();
private:
double cashValue;
};

#endif // CASH_H
