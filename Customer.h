#include "Order.h"
#include <iostream>
#include <string.h>
using namespace std;
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
public:
    Customer();
    virtual ~Customer();
    friend ostream& operator<<(ostream& out , Customer& c );
    virtual string Print();
    virtual int getId()=0;
    void setOrder(Order* o);
protected:
    int m_id;
    string m_phone;
private:
 Order* order;

};

#endif // CUSTOMER_H
