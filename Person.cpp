#include "Person.h"
#include <fstream>
Person::Person()
{
    //ctor
}
Person::~Person()
{
    //dtor
}
istream& operator>>(istream& in, Person& p)
{
 ofstream outfile("customers.txt",ios::app);
    cout<<"\nEnter Customer Data : \n";
    cout<<"Enter Full Name : ";
    in>> p.fullname;
    outfile<< p.fullname<<endl;
    cout<<"Enter ID : ";
    in>>p.m_id;
    outfile<<p.m_id<<endl;
    cout<<"Billing Address : ";
    in>>p.billing_address;
    outfile<<p.billing_address<<endl;
    cout<<"Enter  Phone : " ;
    in>>p.m_phone;
    outfile<<p.m_phone<<endl;
   outfile.close();
    return in;
}
int Person::getId()
{
return m_id;
}
string Person::Print()
{
    return "\nFull Name : " + fullname + Customer::Print() + "\nBilling Address : " + billing_address;
}
