#include "Product.h"
#include "OrderItem.h"
#include <iostream>
using namespace std;
#ifndef STOCK_H
#define STOCK_H

class Stock
{
public:
    Stock(int);
    Stock();
    virtual ~Stock();
    void AddStock(int product_id, int quantity);
    void UpdateStock(int product_id, int quantity);
    void DeleteProduct(int product_id);
    int GetQuantity(int product_id );
    friend ostream& operator<<(ostream& out , Stock& s);
    friend istream& operator>>(istream& in , Stock& s);
    bool AsssignProductByID(int id);
    void setNewquantity(int id,int q);
    double getPrice(int id);
protected:

private:
    int m_id;
    int p_counter,capacity;
    Product* productList;
    OrderItem orderItem;
};

#endif // STOCK_H
