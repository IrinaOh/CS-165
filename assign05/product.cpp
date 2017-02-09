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
 * Default Constructor- Set the name to "none", description 
 * to "", and the weight and the base price to 0.
 ***************************************************************/
Product :: Product()
{
  _name = "none";
  _description = "";
  _weight = 0;
  _basePrice = 0;

  computeShippingCost();

}

 /***************************************************************
  * Non-default - Accepts all four of these values (name, 
  * description, basePrice, weight) and sets them.
  ***************************************************************/
Product :: Product(string name, string description, double basePrice, double weight)
{
  _name = name;
  _description = description;
  _weight = weight;
  _basePrice = basePrice;
  computeTax();
  computeShippingCost();

}

 /***************************************************************
  * 
  ***************************************************************/
void Product::prompt()
{
   string name;
   string description;
   double weight;
   double price;

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

   setName(name);
   setDescription(description);
   setBasePrice(price);
   setWeight(weight);
}

/***************************************************************
 * 
 ***************************************************************/
void Product :: setName(string value)
{
  _name = value;
}

/***************************************************************
 * 
 ***************************************************************/
void Product :: setDescription(string value)
{
  _description = value;
}

/***************************************************************
 * 
 ***************************************************************/
void Product :: setBasePrice(double value)
{
  _basePrice = value;
  computeTax();
}

/***************************************************************
 * 
 ***************************************************************/
void Product :: setWeight(double value)
{
  _weight = value;
  computeShippingCost();
}

/***************************************************************
 * GetSalesTax will calculate the percentage of tax to be paid
 ***************************************************************/
void Product::computeTax()
{
   _salesTax = _basePrice * 0.06;
}

/***************************************************************
 * It will calculate the shipping cost of the product
 ***************************************************************/
void Product::computeShippingCost()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   if(_weight >= 5)
   {
      _shippingCost = (_weight * 0.1) + 2.00 - 0.5;
   }
   else
   {
      _shippingCost = 2.00;
   }
 
}

/***************************************************************
 * It will return the total cost of the product
  ***************************************************************/
double Product::getTotalPrice()
{
   return _basePrice + _salesTax + _shippingCost;
}

/***************************************************************
 * It will display the product with the description
 ***************************************************************/
void Product::displayAdvertising()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << _name << " - $" << _basePrice << endl
        << '(' << _description << ')' << endl; 
}

/***************************************************************
 * It will display the inventory with the price, name and weight
 ***************************************************************/
void Product::displayInventory()
{
  cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout <<'$' << _basePrice << " - " << _name << " - ";
   
   cout.precision(1);
   cout << _weight << " lbs\n";
}

/***************************************************************
 * It will show the invoice for the product
  ***************************************************************/
void Product::displayReceipt()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << _name << endl;
   cout << "  Price:         $  "   << setw(6) << _basePrice << endl; 
   cout << "  Sales tax:     $   "  <<  setw(5) << _salesTax        << endl;
   cerr << ">>>> The shipping cost is for >>" << _name << " is " << _shippingCost << endl;
   cout << "  Shipping cost: $    " <<  _shippingCost    << endl;
   cout << "  Total:         $ "   << setw(7) <<   getTotalPrice()  << endl;
}
