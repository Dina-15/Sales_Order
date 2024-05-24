#include "OrderItem.h"
#include "Stock.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
#ifndef ORDER_H
#define ORDER_H
enum OrderStatus { NEW , HOLD , PAID , CANCELED };
class Order
{
public:
    Order();
    virtual ~Order();
    void CreatOrder(Stock& stock);
    void UpdateOrder(Stock& stock);
    friend ostream& operator<<(ostream& out , Order& o);
    int getStatus();
    int getId();
    void PaidStatus();
    int getcount();
    double getTotal();
private:
    OrderStatus Status;
    int m_id,order_num;
    int m_number;
    double total;
    OrderItem* orderItem;
    char* date;//set date and time creating an order

};

#endif // ORDER_H
