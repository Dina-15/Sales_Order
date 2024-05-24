#include <ctime>
#include <bits/stdc++.h>
#include "Payment.h"

Payment::Payment()
{
                //ctor
}
Payment::~Payment()
{
                //dtor
}
double Payment::Pay(Order* o)
{
amount=o->getTotal();
return amount;
}
string Payment::Update()
{
 time_t now = time(0);
 paid_date = ctime(&now);
 return paid_date;
}
void Payment::read()
{
     time_t now = time(0); //current date/time
     paid_date = ctime(&now); //convert now to string form
}
ostream& operator<<(ostream& out,Payment&p)
{
 out<<p.Update();
 return out;
}
