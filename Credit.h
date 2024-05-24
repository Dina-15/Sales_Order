#include "Payment.h"
#include <time.h>
#include <string.h>
using namespace std;
#ifndef CREDIT_H
#define CREDIT_H

class Credit : public Payment
{
public:
    Credit();
    virtual ~Credit();
    void read();
    string Update();
private:
string number;
string type;
time_t expireDate;//set date and time creating new Payment
int year , month , day;
};

#endif // CREDIT_H
