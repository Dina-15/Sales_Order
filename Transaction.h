#include "Order.h"
#include "Payment.h"
#include "Cash.h"
#include "Check.h"
#include "Credit.h"
#include <time.h>
#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction
{
public:
    Transaction();
    virtual ~Transaction();
    Order GetOrder(int order_id);
    friend ostream& operator<<(ostream& out,Transaction& t);
    void operator+=(Payment& p);
    void assignTrans(Order* o );
    bool checkOrder(Order*o);
private:
  Order* order;
  Payment* payment;
  char* Transaction_date ;
};

#endif // TRANSACTION_H
