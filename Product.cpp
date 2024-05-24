#include "Product.h"
#include <fstream>
#include <cmath>
Product::Product()
{
   m_quantity=0;
}

Product::~Product()
{
    //dtor
}

void Product::Update()
{

}
void Product::setId(int id)
{
    m_id=id;
}
void Product::setQuantity(int q)
{
 if((q<0 && abs(q)<=m_quantity) || q>0)
 m_quantity+=q;
 else cout<<"sorry, more than stock quantity !\n";
}
void Product::delQuantity()
{
 m_quantity=0;
}
int Product::getId()
{
    return m_id;
}
int Product::getQuantity()
{
    return m_quantity;
}
double Product::getprice()
{
    return price;
}
ostream& operator<<(ostream& out, Product& p)
{
    out<<"\nProduct Name : "<<p.name;
    out<<"\nProduct ID : "<<p.m_id;
    out<<"\nProduct Number : "<<p.number;
    out<<"\nProduct Type : "<<p.type;
    out<<"\nProduct price per unit : "<<p.price;
    out<<"\nStock Quantity : "<<p.m_quantity;
    return out;
}
istream& operator>>(istream& in, Product& p)
{
    ofstream outfile("Products.txt",ios::app);
    cout<<"Product Name : ";
    in>>p.name;
    in.ignore(1);
    outfile<<p.name<<endl;
    cout<<"Product Number : ";
    in>>p.number;
    in.ignore(1);
    outfile<<p.number<<endl;
    cout<<"Product Type : ";
    in>>p.type;
    in.ignore(1);
    outfile<<p.type<<endl;
    cout<<"Product price per unit : ";
    in>>p.price;
    outfile<<p.price<<endl;
    in.ignore(1);
    return in;
}
