#include "Check.h"

Check::Check()
{
                //ctor
}

Check::~Check()
{
                //dtor
}
void Check::read()
{
  Payment::read();
  cout<<"Enter Name : ";
  cin>>name;
  cout<<"Enter Bank Id : ";
  cin>>Bank_Id;
  cout<<"Order Paid Successfully !\n";
}
string Check::Update()
{
return "Name: "+ name+"\nBank Id : "+Bank_Id+"\nPaid date : "+Payment::Update() + "\n";
}
