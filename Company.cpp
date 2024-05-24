#include "Company.h"
#include <fstream>
Company::Company()
{
  //ctor
}
Company::~Company()
{
  //dtor
}
istream& operator>>(istream& in , Company& co)
{
 ofstream outfile("customers.txt",ios::app);
 cout<<"\nEnter Customer Data : \n";
 cout<<"Enter Company name : ";
 in>>co.Company_name;
 outfile<<co.Company_name<<endl;
 cout<<"Enter ID : ";
 in>>co.m_id;
 outfile<<co.m_id<<endl;
 cout<<"Enter Location : ";
 in>>co.Location;
 outfile<<co.Location<<endl;
 cout<<"Enter Phone : " ;
 in>>co.m_phone;
 outfile<<co.m_phone<<endl;
 outfile.close();
 return in;
}
int Company::getId()
{
return m_id;
}
string Company::Print()
{
return "\nCompany name : " +  Company_name +Customer::Print()  + "\nLocation : " + Location ;
}
