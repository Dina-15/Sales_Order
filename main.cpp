#include <iostream>
#include <string.h>
#include <stdlib.h>//pause, cls
#include <windows.h> //SetConsoleTextAttribute
#include "Transaction.h"
#include "Customers.h"
#include "Stock.h"
#include "Payment.h"
using namespace std;

HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);

void PrintLine(string msg, bool line=true, int color_code=15)
{
    SetConsoleTextAttribute(cout_handle, color_code);
    cout<<msg<<(line==1? "\n" : "\t");
}
Customers customers(100);
Stock stock(100);
void customer()
{
    int ch=-1;
    while(ch!=0)
    {
        system("cls");
        PrintLine("\nMain Menu -> DataEntry -> Customer ..",1,3);
        PrintLine("\n[1] ADD NEW CUSTOMER",1);
        PrintLine("[2] UPDATE CUSTOMER",1);
        PrintLine("[3] DELETE CUSTOMER",1);
        PrintLine("[0] RETURN BACK",1,5);
        PrintLine("Enter Selection : ",0,11);
        cin>>ch;
        switch(ch)
        {
        case 1:
            system("cls");
            PrintLine("\nMain Menu -> DataEntry -> Customer -> ADD NEW CUSTOMER ..",1,3);
            customers.addCustomer();
            system("pause");
            break;
        case 2:
        {
            system("cls");
            PrintLine("\nMain Menu -> DataEntry -> Customer -> UPDATE CUSTOMER ..",1,3);
            int id;
            cout<<"\nEnter Customer Id to Update : ";
            cin>>id;
            customers.editCustomer(id);
        }
        system("pause");
        break;
        case 3:
        {
            system("cls");
            PrintLine("\nMain Menu -> DataEntry -> Customer -> DELETE CUSTOMER ..",1,3);
            int id;
            cout<<"\nEnter Customer Id to Delete : ";
            cin>>id;
            customers.deleteCustomer(id);
        }
        system("pause");
        break;
        case 0:
            return;
        }
    }
}
void product()
{
    int ch=-1;
    while(ch!=0)
    {
        system("cls");
        PrintLine("\nMain Menu -> DataEntry -> Product ..",1,3);
        PrintLine("\n[1] ADD NEW PRODUCT IN STOCK",1);
        PrintLine("[2] UPDATE PRODUCT IN STOCK",1);
        PrintLine("[3] DELETE PRODUCT IN STOCK",1);
        PrintLine("[0] RETURN BACK",1,5);
        PrintLine("Enter Selection : ",0,11);
        cin>>ch;
        switch(ch)
        {
        case 1:
        {
            system("cls");
            PrintLine("\nMain Menu -> DataEntry -> Product -> ADD NEW PRODUCT IN STOCK",1,3);
            cin>>stock;
        }
        system("pause");
        break;
        case 2:
        {
            system("cls");
            PrintLine("\nMain Menu -> DataEntry -> Product -> UPDATE PRODUCT IN STOCK",1,3);
            int q,id;
            cout<<"\nEnter Product Id : ";
            cin>>id;
            cout<<"Enter Product New Quantity : ";
            cin>>q;
            stock.UpdateStock(id,q);
        }
        system("pause");
        break;
        case 3:
        {
            system("cls");
            int id;
            PrintLine("\nMain Menu -> DataEntry -> Product -> DELETE PRODUCT IN STOCK",1,3);
            cout<<"\nEnter New Product Id to Delete : ";
            cin>>id;
            stock.DeleteProduct(id);
        }
        system("pause");
        break;
        case 0:
            return;
        }
    }
}
void DataEntry()
{
    int ch=-1;
    while(ch!=0)
    {
        system("cls");
        PrintLine("\nMain Menu -> DataEntry ..",1,3);
        PrintLine("\n[1] CUSTOMER",1);
        PrintLine("[2] PRODUCT",1);
        PrintLine("[0] RETURN BACK",1,5);
        PrintLine("Enter Selection : ",0,11);
        cin>>ch;
        switch(ch)
        {
        case 1:
            system("cls");
            customer();
            break;
        case 2:
            system("cls");
            product();
            break;
        case 0:
            return;
        }
    }
}
int Trans_counter=0;
int order_count=0;
Order* orderList=new Order();
Transaction* transList = new Transaction;
void AddTransaction()
{
    Order* newOrder=new Order;
    int c_id;
    PrintLine("\nMain Menu -> Sales Process -> Add Transaction..",1,11);
    cout<<"\nEnter Customer ID : ";
    cin>>c_id;
    while(!customers.assignCustomer(orderList+order_count,c_id))
    {
        cout<<"Sorry, This id does n't belong to any order!\n ";
        cout<<"\nEnter Customer ID : ";
        cin>>c_id;
    }
    transList[Trans_counter++].assignTrans(orderList+order_count);
    newOrder->CreatOrder(stock);
    orderList[order_count++]=*newOrder;
    srand(time(0));
}
void UpdateOrder()
{
    int o_id;
    PrintLine("\nMain Menu -> Sales Process -> Update Order..",1,3);
    bool valid=false;
    while(!valid)
    {
        cout<<"\nEnter Order Id : ";
        cin>>o_id;
        for(int i=0; i<order_count; ++i)
        {
            if(o_id==orderList[i].getId())
            {
                orderList[i].UpdateOrder(stock);
                if(orderList[i].getStatus()==3)//canceled
                {

                    if(i==order_count-1)//delete it
                    {
                        order_count--;
                    }
                    else
                    {
                        orderList[i]=orderList[order_count-1];
                        order_count--;
                    }
                    cout<<"Order Canceled Successfully !\n";
                }
                valid=true;
                break;
            }
            else if(i==order_count-1)
            {
                cout<<"Sorry, This id does n't belong to any order!\n ";
                valid=false;
            }
        }
    }
}
Payment payment;
void PayOrder()
{
    int id;
    PrintLine("\nMain Menu -> Sales Process -> pay order..",1,3);
    bool valid=false;
    while(!valid)
    {
        cout<<"\nEnter order id to pay : ";
        cin>>id;
        for(int i=0; i<order_count; ++i)
        {
            if(id==orderList[i].getId())
            {
                for(int j=0; j<Trans_counter; ++j)
                    if(transList[j].checkOrder(orderList+i))
                    {
                        transList[j]+= payment;
                        orderList[i].PaidStatus();
                    }
                valid=true;
                break;
            }
            else if(i==order_count-1)
            {
                cout<<"Sorry, This id does n't belong to any order!\n ";
                valid=false;
            }
        }
    }
}
void UpdatePayment()
{
    int id;
    PrintLine("\nMain Menu -> Sales Process -> UPDATE PAYMENT..",1,3);
    bool valid=false;
    while(!valid)
    {
        cout<<"\nEnter order id to pay : ";
        cin>>id;
        for(int i=0; i<order_count; ++i)
        {
            if(id==orderList[i].getId())
            {
                for(int j=0; j<Trans_counter; ++j)
                    if(transList[j].checkOrder(orderList+i))
                    {
                        transList[j]+= payment;
                        orderList[i].PaidStatus();
                    }
                valid=true;
                break;
            }
            else if(i==order_count-1)
            {
                cout<<"Sorry, This id does n't belong to any order!\n ";
                valid=false;
            }
        }
    }
}
void SalesProcess()
{
    int ch=-1;
    while(ch!=0)
    {
        system("cls");
        PrintLine("\nMain Menu -> Sales Process ..",1,3);
        PrintLine("\n[1] ADD TRANSACTION ",1);
        PrintLine("[2] UPDATE ORDER",1);
        PrintLine("[3] PAY ORDER",1);
        PrintLine("[4] UPDATE PAYMENT",1);
        PrintLine("[0] RETURN BACK",1,5);
        PrintLine("Enter Selection : ",0,11);
        cin>>ch;
        switch(ch)
        {
        case 1:
            system("cls");
            AddTransaction();
            system("pause");
            break;
        case 2:
            system("cls");
            UpdateOrder();
            system("pause");
            break;
        case 3:
            system("cls");
            PayOrder();
            system("pause");
            break;
        case 4:
            system("cls");
            UpdatePayment();
            system("pause");
            break;
        case 0:
            return;
        }
    }
}
void Print()
{
    int ch=-1;
    while(ch!=0)
    {
        system("cls");
        PrintLine("\nMain Menu -> Print ..",1,3);
        PrintLine("\n[1] CUSTOMERS",1);
        PrintLine("[2] STOCK DATA",1);
        PrintLine("[3] TRANSACTION",1);
        PrintLine("[0] RETURN BACK",1,5);
        PrintLine("Enter Selection : ",0,11);
        cin>>ch;
        switch(ch)
        {
        case 1:
            system("cls");
            PrintLine("\nMain Menu -> Print -> Customers ..",1,3);
            customers.PrintCustomer();
            system("pause");
            break;
        case 2:
            system("cls");
            PrintLine("\nMain Menu -> Print -> STOCK DATA..",1,3);
            cout<<stock;
            system("pause");
            break;
        case 3:
            system("cls");
            PrintLine("\nMain Menu -> Print -> TRANSACTION..",1,3);
            for(int i=0; i<Trans_counter; ++i)
                cout<<transList[i];
            system("pause");
            break;
        case 0:
            return;

        }
    }

}
int main()
{
    int ch=-1;
    while(ch!=0)
    {
        system("cls");
        PrintLine("\nMain Menu",1,3);
        PrintLine("\n[1] DATA ENTRY",1);
        PrintLine("[2] SALES PROCESS",1);
        PrintLine("[3] PRINT",1);
        PrintLine("[0] EXIT",1,12);
        PrintLine("\nEnter Selection : ",0,11);
        cin>>ch;
        switch(ch)
        {
        case 1:
            system("cls");
            DataEntry();
            break;
        case 2:
            system("cls");
            SalesProcess();
            break;
        case 3:
            system("cls");
            Print();
            break;
        case 0:
            system("cls");
            PrintLine("\n\tThanks",1);
            break;
        }
    }
    return 0;
}
