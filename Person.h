#include "Customer.h"
#include <iostream>
#include <string.h>
using namespace std;
#ifndef PERSON_H
#define PERSON_H


class Person : public Customer
{
public:
    Person();
    virtual ~Person();
    string Print();
    friend istream& operator>>(istream& in, Person& p);
    int getId();
private:
    string billing_address;
    string fullname;
};
#endif // PERSON_H
