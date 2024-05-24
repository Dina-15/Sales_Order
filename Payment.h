#include <iostream>
#include <time.h>
#include <string.h>
#include "Order.h"
using namespace std;
#ifndef PAYMENT_H
#define PAYMENT_H

class Payment
{
public:
    Payment();
    virtual ~Payment();
    double Pay(Order*o);
    virtual string Update();
    virtual void read();
    friend ostream& operator<<(ostream& out,Payment&p);
protected:
    double amount;
private:
 char* paid_date;//set date and time creating new Payment

};

#endif // PAYMENT_H
