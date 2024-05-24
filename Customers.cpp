#include "Customers.h"

Customers::Customers(int c_size=25)
{
    customer_size =c_size;
    customerList = new Customer*[customer_size];
    c_counter=0;
}

Customers::~Customers()
{
    for(int i=0; i<customer_size; ++i)
    {
        delete customerList[i];
    }
    delete []customerList;
}

bool Customers::assignCustomer(Order* o,int c_id)
{
    for(int i=0 ; i<c_counter ; ++i)
    {
        if(c_id==customerList[i]->getId())
        {
            Customer* c =customerList[i];
            c->setOrder(o);
            return true;
        }
        else if(i==c_counter-1)
        return false;
    }
}
void Customers::addCustomer()
{
    cout<<"\n1. Person\n2. Company\n";
    int ch;
    bool New=true;
    cin>>ch;
    switch(ch)
    {
    case 1:
    {
        customerList[c_counter]= new Person;
        Person*person = dynamic_cast<Person*>(customerList[c_counter]);
        cin>>*person;
        c_counter++;
    }
    break;
    case 2:
    {
        customerList[c_counter]= new Company;
        Company* company=dynamic_cast<Company*>(customerList[c_counter]);
        cin>>*company;
        c_counter++;
    }
    break;
    default:
        New=false;
    }
    if(New)
    {
        cout<<"\nSuccessfully Saved !\n";
    }
}
void Customers::editCustomer(int id)
{
    if(c_counter==0)
    {
        cout<<"There is no Customer !\n";
    }
    else
    {
        for(int i=0 ; i<c_counter ; ++i)
        {
            if(Person* p=dynamic_cast<Person*>(customerList[i]))
            {
                if(id==p->getId())
                {
                    cin>>*p;
                    break;
                }
            }
            else if(Company*c=dynamic_cast<Company*>(customerList[i]))
            {
                if(id==c->getId())
                {
                    cin>>*c;
                    break;
                }
            }
        }
        cout<<"\nCustomer Edited Successfully !\n";
    }
}
void Customers::deleteCustomer(int id)
{
    if(c_counter==0)
    {
        cout<<"There are no Customers !\n";
    }
    bool deleted=false;
    for(int i=0 ; i<c_counter ; ++i)
    {
        if(id==customerList[i]->getId())
        {
            if(i==c_counter-1)
            {
                c_counter--;
            }
            else
            {
                customerList[i]=customerList[c_counter-1];
                c_counter--;
            }
            deleted=true;
            break;
        }
    }
    if(deleted)
    {
        cout<<"Deleted Successfully!\n";
    }
    else
        cout<<"Not Found!\n";
}
void Customers::PrintCustomer()
{
    if(c_counter==0)
        cout<<"There are no Customers!\n";
    for(int i=0 ; i<c_counter ; ++i)
    {
        cout<<customerList[i]->Print();
        cout<<"\n===================================\n";
    }

}
