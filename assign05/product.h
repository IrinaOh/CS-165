/***************************************************************
 * File: product.h
 * Author: Anderson Erichsen Fagundes
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
 using namespace std;

/**************************************************************
 * Class Product will be used to help a warehouse store their
 * products
 *************************************************************/
class Product
{
  private:
   string _name;
   double _weight;
   string _description;
   double _salesTax;
   double _shippingCost;
  
    // new ones added
   double _basePrice;


  public:
   Product();
   Product(string name, string description, double weight, double basePrice);
   void prompt();
   void computeTax();
   void computeShippingCost();
   double getTotalPrice();
   void displayAdvertising();
   void displayInventory();
   void displayReceipt();

   // new ones for this assign

   string getName()        {  return _name;         }
   string getDescription() {  return _description;  }
   double getBasePrice()   {  return _basePrice;    }
   double getWeight ()     {  return _weight;       }


   void setName          (string value);
   void setDescription   (string value);
   void setBasePrice     (double value);
   void setWeight        (double value);


} ;
#endif
