/***************************************************************
 * File: product.h
 * Author: Anderson Erichsen Fagundes
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

/**************************************************************
 * Class Product will be used to help a warehouse store their
 * products
 *************************************************************/
class Product
{
  private:
   string name;
   double price;
   double weight;
   string description;
   double salesTax;
   double shippingCost;
   double totalPrice;
  public:
   void promptData();
   void getSalesTax();
   void getShippingCost();
   void getTotalPrice();
   void advertisingDisplay();
   void inventoryLineItem();
   void receipt();

} ;
#endif
