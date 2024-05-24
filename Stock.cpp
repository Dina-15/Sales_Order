#include "Stock.h"
#include <fstream>

Stock::Stock(int s_size=25)
{
    capacity=s_size;
    productList = new Product[capacity];
    p_counter=0;
}
Stock::Stock()
{

}
Stock::~Stock()
{
    delete [] productList;
}
void Stock::AddStock(int product_id, int quantity)
{
    if(quantity<capacity)
    {
        cin>>productList[p_counter];
        productList[p_counter].setId(product_id);
        productList[p_counter].setQuantity(quantity);
        p_counter++;
    }
}
void Stock::UpdateStock(int product_id, int quantity)
{
    for(int i=0 ; i<p_counter ; ++i)
    {
        if(product_id==productList[i].getId())
        {
            cin>>productList[i];
            productList[i].setId(product_id);
            productList[i].delQuantity();
            productList[i].setQuantity(quantity);
            break;
        }
    }
}
void Stock::DeleteProduct(int product_id)
{
    if(p_counter==0)
    {
        cout<<"THERE ARE NO PRODUCTS IN THE STOCK\n";
    }
    bool deleted=false;
    for(int i=0 ; i<p_counter ; ++i)
    {
        if(product_id==productList[i].getId())
        {
            if(i==p_counter-1)
                p_counter--;
            else
            {
                productList[i]=productList[p_counter-1];
                p_counter--;
            }
            deleted=true;
            break;
        }
    }
    if(deleted)
    {
        cout<<"PRODUCT DELETED SUCCESSFULLY !\n";
    }
    else
        cout<<"NOT FOUND !\n";
}
int Stock::GetQuantity(int product_id )
{
    int q=0;
    for(int i=0 ; i<p_counter ; ++i)
    {
        if(product_id==productList[i].getId())
        {
            q= productList[i].getQuantity();
            break;
        }
    }
    return q;
}
double Stock::getPrice(int id)
{
                double p;
for(int i=0 ; i<p_counter ; ++i)
    {
        if(id==productList[i].getId())
        {
            p= productList[i].getprice();
            break;
        }
    }
   return p;
}
 void Stock::setNewquantity(int id,int q)
{
   for(int i=0 ; i<p_counter ; ++i)
    {
        if(id==productList[i].getId())
        {
              productList[i].setQuantity(q);
            break;
        }
    }
}
bool Stock::AsssignProductByID(int id)
{
    bool found=false;
    for(int i=0 ; i<p_counter ; ++i)
    {
        if(id==productList[i].getId())
        {
            found= true;
            break;
        }
    }
    return found;
}
ostream& operator<<(ostream& out, Stock& s)
{
    for(int i=0 ; i<s.p_counter ; ++i)
    {
        out<<s.productList[i];
        out<<"\n===============================\n";
    }
    return out;
}
istream& operator>>(istream& in, Stock& s)
{
  ofstream outfile("Products.txt",ios::app);
    int q,id;
    cout<<"\nEnter Product Quantity : ";
    in>>q;
    outfile<<q<<endl;
    cout<<"Enter Product Id : ";
    in>>id;
    outfile<<id<<endl;
    s.AddStock(id,q);
    return in;
}
