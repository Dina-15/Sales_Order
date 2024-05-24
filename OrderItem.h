//#include "Stock.h"
#include "Product.h"
#include <iostream>
using namespace std;
#ifndef ORDERITEM_H
#define ORDERITEM_H

class OrderItem
{
public:
    OrderItem();
    OrderItem(int q ,int id ,double salePrice);
    virtual ~OrderItem();
    void operator++();
    void operator--();
    void operator+=(int n);
    void operator-=(int n);
    int getId();
    double getSalePrice();
    void setProduct(Product* p);
    void setquantity(int q);
    int getQuantity();

private:
    double sale_price,p_price;
    int quantity;
    int m_id;
};

#endif // ORDERITEM_H
