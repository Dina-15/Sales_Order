#include "Customer.h"
#include "Company.h"
#include "Person.h"
#ifndef CUSTOMERS_H
#define CUSTOMERS_H

class Customers
{
public:
    Customers(int);
    virtual ~Customers();
    void addCustomer();
    void editCustomer(int id);
    void deleteCustomer(int id);
    void PrintCustomer();
    bool assignCustomer(Order* o,int c_id);
    bool checkId(int id);
protected:

private:
int c_counter,customer_size;
Customer** customerList;
};

#endif // CUSTOMERS_H
