#include "Credit.h"
#include <time.h>
#include <bits/stdc++.h>

Credit::Credit()
{
                //ctor
}

Credit::~Credit()
{
                //dtor
}
void Credit::read()
{
Payment::read();
int diffDays;
do{
cout<<"Enter Number of card : ";
cin>>number;
cout<<"Enter Type :";
cin>>type;
//get the current time
time_t now=time(0);
cout<<"Enter Expire Date of the Card :(year/ month / day) : ";
cin>>year>>month>>day;
//create a tm struct for the desired date
tm desiredDate={0};
desiredDate.tm_year=year-1900;
desiredDate.tm_mon=month-1;
desiredDate.tm_mday=day;
//convert expireDate to time_t format
time_t expireDate=mktime(&desiredDate);
//calculate the difference between the current time and expireDate
double diff= difftime(expireDate,now);
//convert to days
diffDays = (int)(diff / (60*60*24)); // minus
if(diffDays<0)
cout<<"Unfortunately, your credit card has expired ,try again!\n";
}while(diffDays<0);
cout<<"Order Paid Successfully !\n";
}
string Credit::Update()
{
return  "Number of card : "+number+"\nType : "+type+"\nPaid date : "+Payment::Update()+"\n";
}
