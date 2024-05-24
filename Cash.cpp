#include "Cash.h"

Cash::Cash()
{
    //ctor
}

Cash::~Cash()
{
    //dtor
}
string Cash::Update()
{
return "Cash Value : " + to_string(cashValue)+"\nPaid date : "+Payment::Update()+"\n";
}
void Cash::read()
{
    Payment::read();

    cout<<"Enter cash Value : ";
    cin>>cashValue;
    while(cashValue<Payment::amount){
    cout<<"Sorry! You have to pay all the amount.."<<endl;
    cout<<"Enter cash Value : ";
    cin>>cashValue;}
    cout<<"Order Paid Successfully !\n";
}
