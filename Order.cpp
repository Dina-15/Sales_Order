#include "Order.h"

Order::Order()
{
    orderItem=new OrderItem[10];
    order_num=0;
    total=0.0;
    time_t now = time(0); //current date/time
    date = ctime(&now); //convert now to string form
}
Order::~Order()
{
    delete[]orderItem;
}
int Order::getStatus()
{
    return Status;
}
void Order::PaidStatus()
{
    Status=PAID;
}
int Order::getId()
{
    return m_id;
}
int Order::getcount()
{
 return order_num;
}
double Order::getTotal()
{
return total;
}
void Order::CreatOrder(Stock& stock)
{
    int ch;
    Status = NEW;
    cout<<"Enter Order Id : ";
    cin>>m_id;
    m_number = rand()%(1 + 100000);
    srand(time(0));
    do
    {
        int q, ID;
        cout<<"Enter Product Id : ";
        cin>>ID;
        while(!stock.AsssignProductByID(ID))
        {
            cout<<"Sorry, This id does n't belong to any product!\n";
            cout<<"Enter Product Id : ";
            cin>>ID;
        }
        cout<<"Stock Quantity of this product is  "<<stock.GetQuantity(ID);
        cout<<"\nEnter Quantity You need : ";
        cin>>q;
        while(q>stock.GetQuantity(ID))
        {
            cout<<"Sorry, this quantity is n't available now!"
                <<"\n Enter another quantity : ";
            cin>>q;
        }
        OrderItem* newProduct=new OrderItem(q,ID , stock.getPrice(ID));
        total+=newProduct->getSalePrice();
        stock.setNewquantity(ID,-q);
        orderItem[order_num++]= *newProduct;
        cout<<"Product added to your cart successfully !\n";
        cout<<"Add another Product ? (1. Yes , 2. No) : ";
        cin>>ch;
    }
    while(ch==1);
    cout<<"Order Saved Successfully !\n";
    Status=HOLD;

}
void Order::UpdateOrder(Stock& stock)
{
    int ch=-1, id ,n;
    while(ch!=0)
    {
        cout<<"\n\n[1] Cancel The Order\n[2] Increase Product Quantity by 1\n"
            <<"[3] Decrease Product Quantity by 1\n[4] Add extra quantity\n[5] Eliminate quantity\n"
            <<"[6] Cancel a product\n[0] Update done\nEnter selection : ";

        cin>>ch;
        switch(ch)
        {
        case 1:
        {
            system("cls");
            Status=CANCELED;
            for(int i=0 ; i<order_num ; ++i){
            stock.setNewquantity(id,orderItem[i].getQuantity());}
            return;
        }
        break;
        case 2:
        {
            cout<<"Enter product id to increase : ";
            cin>>id;
            for(int i=0 ; i<order_num ; ++i)
            {
                if(id==orderItem[i].getId())
                {
                    total-=orderItem[i].getSalePrice();
                    ++orderItem[i];
                    stock.setNewquantity(id,-1);
                    total+=orderItem[i].getSalePrice();
                    cout<<"Quantity increased successfully!\n";
                    system("pause");
                }
            }
            system("cls");
        }
        break;
        case 3:
        {
            cout<<"Enter product id to Decrease : ";
            cin>>id;
            for(int i=0 ; i<order_num ; ++i)
            {
                if(id==orderItem[i].getId())
                {
                    total-=orderItem[i].getSalePrice();
                    --orderItem[i];
                    stock.setNewquantity(id,1);
                    total+=orderItem[i].getSalePrice();
                    cout<<"Quantity decreased successfully!\n";
                    system("pause");
                }
            }
            system("cls");
        }
        break;
        case 4:
        {
            cout<<"Enter product id ";
            cin>>id;
            cout<<"Enter quantity to add : ";
            cin>>n;
            for(int i=0 ; i<order_num ; ++i)
            {
                if(id==orderItem[i].getId())
                {
                    total-=orderItem[i].getSalePrice();
                    orderItem[i]+=n;
                    stock.setNewquantity(id,-n);
                    total+=orderItem[i].getSalePrice();
                    cout<<"Quantity increased successfully!\n";
                    system("pause");
                }
            }
            system("cls");
        }
        break;
        case 5:
        {
            cout<<"Enter product id ";
            cin>>id;
            cout<<"Enter quantity to decrease : ";
            cin>>n;
               for(int i=0 ; i<order_num ; ++i)
            {
                if(id==orderItem[i].getId())
                {
                    total-=orderItem[i].getSalePrice();
                    orderItem[i]-=n;
                    stock.setNewquantity(id,n);
                    total+=orderItem[i].getSalePrice();
                    cout<<"Quantity decreased successfully!\n";
                    system("pause");
                }
            }
            system("cls");
        }
        break;
        case 6:
        {
            if(order_num==0)
            {
                cout<<"There are no Products in your cart !\n";
            }
            else
            {
                cout<<"Enter product id to Cancel : ";
                cin>>id;
                bool deleted=false;
                for(int i=0 ; i<order_num ; ++i)
                {
                    if(id==orderItem[i].getId())
                    {
                        if(i==order_num-1)
                        {
                            order_num--;
                        }
                        else
                        {
                            orderItem[i]=orderItem[order_num-1];
                            order_num--;
                        }
                        deleted=true;
                        stock.setNewquantity(id,orderItem[i].getQuantity());
                        total-=orderItem[i].getSalePrice();
                    }
                }
                if(deleted)
                {
                    cout<<"Product Canceled Successfully!\n";
                    system("pause");
                }
            }
            system("cls");
        }
        break;
        }
    }
 cout<<"\nOrder Updated Successfully !\n";
}
ostream& operator<<(ostream& out , Order& o)
{
    out<<"\nOrder Number : "<<o.m_number;//date
    out<<"\nOrder Id : "<<o.m_id;
    out<<"\nTotal Pay : $ "<<o.total<<" for "<<o.order_num<<" Product";
    out<<"\nOrder Status : ";
    if(o.Status==0)
    out<<"NEW";
    else if(o.Status==1)
    out<<"HOLD";
    else if(o.Status==2)
    out<<"PAID";
    else if(o.Status==3)
    out<<"CANCELED";
    out<<"\nOrder Date : "<<o.date;
    out<<endl;
    return out;
}

