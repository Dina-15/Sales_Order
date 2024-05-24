#include "Customer.h"
#include <iostream>
#include <string.h>
using namespace std;
#ifndef COMPANY_H
#define COMPANY_H

class Company : public Customer
{
public:
    Company();
    virtual ~Company();
    string Print();
    int getId();
    friend istream& operator>>(istream& in , Company& co);
private:
   string Location;
   string Company_name;
};
#endif // COMPANY_H
