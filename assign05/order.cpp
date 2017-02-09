#include <iostream>
#include <iomanip>
#include <string>

#include "order.h"


/*****************************************************************
 * Default constructor
 ****************************************************************/
Order::Order()
{
	_quantity = 0;
	_product = Product :: Product();
	_customer = Customer :: Customer();
}

/*****************************************************************
 * Non default constructor
 ****************************************************************/
Order::Order(Product product, int quantity, Customer customer)
{
	_quantity = quantity;
	_product = product;
	_customer = customer;
}

/*****************************************************************
 * compute the total price for the order
 ****************************************************************/
double Order::getTotalPrice()
{
	return _product.getTotalPrice() * _quantity;
}

/*****************************************************************
 * set the product
 ****************************************************************/
void Order::setProduct(Product product)
{
	_product = product;
}

/*****************************************************************
 * set the quantity of items
 ****************************************************************/
void Order::setQuantity(int value)
{
	_quantity = value;
}

/*****************************************************************
 * set the customer
 ****************************************************************/
void Order::setCustomer(Customer customer)
{
	_customer = customer;
}

/*****************************************************************
 * display the receipt
 ****************************************************************/
void Order::displayReceipt()
{
	cout << _customer.getName() << endl;
	_product.displayReceipt();
}

