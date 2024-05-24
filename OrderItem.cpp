#include "OrderItem.h"

OrderItem::OrderItem()
{
//default ctr
}
OrderItem::OrderItem(int q ,int id ,double salePrice)
{
  quantity=q;
  m_id=id;
  p_price=salePrice; // price of the product in the stock
  sale_price=salePrice*q; // total sale price of all quantity
}
OrderItem::~OrderItem()
{

}
int OrderItem::getQuantity()
{
 return quantity;
}
int OrderItem::getId()
{
return m_id;
}
double OrderItem::getSalePrice()
{
 return sale_price ;
}
void OrderItem::operator++()
{
  this->quantity++;
  this->sale_price+=this->p_price;
}
void OrderItem::operator--()
{
  this->quantity--;
  this->sale_price-=this->p_price;
}
void OrderItem::operator+=(int n)
{
  this->quantity+=n;
  this->sale_price+=(this->p_price*n);
}
void OrderItem::operator-=(int n)
{
  this->quantity-=n;
  this->sale_price-=(this->p_price*n);
}
