#include "Payment.h"
#include <string.h>
using namespace std;
#ifndef CHECK_H
#define CHECK_H


class Check : public Payment
{
public:
    Check();
    virtual ~Check();
    void read();
    string Update();
private:
string name;
string Bank_Id;
};

#endif // CHECK_H
