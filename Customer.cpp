#include "Customer.h"
#include <string.h>
#include <iostream>
using namespace std;
Customer::Customer()
{
    order=nullptr;
}

Customer::~Customer()
{
   delete [] order;
}
void Customer::setOrder(Order* o)
{
  order = o;
}
string Customer::Print()
{
  return "\nID : " + to_string(m_id) + "\nPhone : " + m_phone;
}
