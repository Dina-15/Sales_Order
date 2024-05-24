#include "Transaction.h"

Transaction::Transaction()
{
    order = nullptr;
    payment=nullptr;
}
Transaction::~Transaction()
{
    delete[] order;
    delete[] payment;
}
Order Transaction::GetOrder(int order_id)
{
    return *order;
}
ostream& operator<<(ostream& out,Transaction& t)
{
    out<<*t.order;
    if(t.order->getStatus()==2)
    {
        out<<"Payment Details ...\n";
        out<<*t.payment;
    }
    out<<"Transaction date : "<<t.Transaction_date;
    out<<"======================================="<<endl;
    return out;
}
bool Transaction::checkOrder(Order*o)
{
    if(order==o)
        return true;
    else
        return false;
}

void Transaction::assignTrans(Order* o )
{
    order=o;
    time_t now = time(0); //current date/time
    Transaction_date = ctime(&now); //convert now to string form
}
void Transaction::operator+=(Payment& p)
{
    cout<<"Amount is : "<<p.Pay(order)<<endl;
    int c;
    cout<<"Enter Type of Payment : ";
    cout<<"\n1.Cash\n2.Check\n3.Credit\nEnter Selection : ";
    cin>>c;
    switch(c)
    {
    case 1:
        payment=new Cash;
        payment->read();
        break;
    case 2:
        payment=new Check;
        payment->read();
        break;
    case 3:
        payment=new Credit;
        payment->read();
        break;
    }

}
