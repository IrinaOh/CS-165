/***************************************************************
 * File: product.cpp
 * Author: Anderson Erichsen Fagundes
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/
using namespace std;
#include <iostream>
#include <string>
#include <iomanip>
#include "product.h"


/***************************************************************
 * This function will prompt fot the product information
  ***************************************************************/
void Product::promptData()
{
   // get the name of the product
   cout << "Enter name: ";
   getline(cin, name);

   // get the description
   cout << "Enter description: ";
   getline(cin, description);

   // get the weigh of the product
   cout << "Enter weight: ";
   cin >> weight;
   cin.clear();
   cin.ignore(256, '\n');

   // get the price of the product and
   // handle error
   cout << "Enter price: ";
   cin >> price;

   while (price < 0 || cin.fail())
   {
      cin.clear();
      cin.ignore(256,'\n');
      cout << "Enter price: ";
      cin >> price;
   }
}

/***************************************************************
 * GetSalesTax will calculate the percentage of tax to be paid
 ***************************************************************/
void Product::getSalesTax()
{
   salesTax = price * 0.06;
}

/***************************************************************
 * It will calculate the shipping cost of the product
 ***************************************************************/
void Product::getShippingCost()
{
   if(weight >= 5)
   {
      shippingCost = (weight * 0.1) + 2.00 - 0.5;
   }
   else
   {
      shippingCost = 2.00;
   }
}

/***************************************************************
 * It will return the total cost of the product
  ***************************************************************/
void Product::getTotalPrice()
{
   totalPrice = price + salesTax + shippingCost;
}

/***************************************************************
 * It will display the product with the description
 ***************************************************************/
void Product::advertisingDisplay()
{
   cout << name << " - $" << price << endl
        << '(' << description << ')' << endl; 
}

/***************************************************************
 * It will display the inventory with the price, name and weight
 ***************************************************************/
void Product::inventoryLineItem()
{
   cout <<'$' << price << " - " << name << " - "
        << weight << " lbs\n";
}

/***************************************************************
 * It will show the invoice for the product
  ***************************************************************/
void Product::receipt()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << name << endl;
   cout << "  Price:         $   " << price << endl;
   cout << "  Sales tax:     $    " << salesTax << endl;
   cout << "  Shipping cost: $    " << shippingCost << endl;
   cout << "  Total:         $   " << totalPrice << endl;
}
