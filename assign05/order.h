// File: order.h

#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include "customer.h"

using namespace std;

// Put your Order class here
class Order
{
private:
	Product _product;
	Customer _customer;
	int _quantity;
public:
	Order();
	Order(Product product, int quantity, Customer customer);

	Product getProduct()    { return _product;           }
	int getQuantity()       { return _quantity;          }
	Customer getCustomer()  { return _customer;          }
	string getShippingZip() { return _customer.getAddress().getZip();  }
	double getTotalPrice(); 

	void setProduct(Product product);
	void setQuantity(int value);
	void setCustomer(Customer customer);
	void displayShippingLabel() {  _customer.display(); } 
	void displayReceipt();




};

#endif
