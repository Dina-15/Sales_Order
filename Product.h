#include <iostream>
using namespace std;
#include <string.h>
#ifndef PRODUCT_H
#define PRODUCT_H


class Product
{
public:
    Product();
    virtual ~Product();
    void Update();
    friend ostream& operator<<(ostream& out , Product& p);
    friend istream& operator>>(istream& in , Product& p);
    void setId(int id);
    void setQuantity(int q);
    int getId();
    int getQuantity();
    double getprice();
    void delQuantity();
protected:

private:
    int m_id,m_quantity;
    string number,name,type;
    double price;
};

#endif // PRODUCT_H
